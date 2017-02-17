//
// Created by peau_c on 2/6/17.
//

#include <sstream>
#include "components/COutput.h"
#include "components/ComponentCreator.h"
#include "utils/Logger.h"
#include "parser/Parser.h"

nts::Parser::Parser() {
	_root = new t_ast_node(nullptr);
	_root->children = new std::vector<t_ast_node *>;
}

nts::Parser::~Parser() {
}

void *nts::Parser::getNode(nts::ASTNodeType type, std::string string, std::vector<s_ast_node *> *root) {
	t_ast_node *node = nullptr;

	if (!root)
		return (nullptr);
	for(std::vector<s_ast_node *>::iterator it = root->begin(); it < root->end(); it++) {
		if ((node = (t_ast_node *) getNode(type, string, (*it)->children)))
			break;
		if ((*it)->type == type && (*it)->lexme == string) {
			return (*it);
		}
	}
	return (node);
}

void nts::Parser::checkLinks() {
	t_ast_node *node;

	node = (t_ast_node *) getNode(nts::ASTNodeType::SECTION, ".links:", _root->children);
	for(std::vector<t_ast_node *>::iterator it = node->children->begin(); it < node->children->end(); it++) {
		printf("%s:%s\t", (*it)->lexme.c_str(), (*it)->value.c_str());
		printf("%s:%s\n", (*it)->children->at(0)->lexme.c_str(), (*it)->children->at(0)->value.c_str());
	}
}

void nts::Parser::checkChipset() {
	t_ast_node *node;

	node = (t_ast_node *) getNode(nts::ASTNodeType::SECTION, ".chipsets:", _root->children);
	for(std::vector<t_ast_node *>::iterator it = node->children->begin(); it < node->children->end(); it++) {
		printf("%s\t%s\n", (*it)->lexme.c_str(), (*it)->value.c_str());
	}
}

void nts::Parser::createAndPushANewNode(nts::ASTNodeType section, std::string lexme, std::string value,
										nts::ASTNodeType sectionTarget, std::string lexmeTarget) {
	t_ast_node *node;
	t_ast_node *newNode = createTree();

	newNode->type = section;
	newNode->lexme = lexme;
	newNode->value = value;
	node = (t_ast_node *) getNode(sectionTarget, lexmeTarget, _root->children);
	node->children->push_back(newNode);
}

void nts::Parser::addLinkNode(std::string word1, std::string word2) {
	std::string delimiter = ":";
	std::string pairs[2][2];

	if (word1.find(delimiter) == word1.npos || word2.find(delimiter) == word2.npos)
		Logger::log(Logger::Error, "Syntax error in the line : " + word1 + " " + word2, true);
	pairs[0][0] = word1.substr(0, word1.find(delimiter));
	pairs[0][1] = word1.substr(word1.find(delimiter) + 1);
	pairs[1][0] = word2.substr(0, word2.find(delimiter));
	pairs[1][1] = word2.substr(word2.find(delimiter) + 1);
	createAndPushANewNode(nts::ASTNodeType::LINK, pairs[0][0], pairs[0][1], nts::ASTNodeType::SECTION, ".links:");
	createAndPushANewNode(nts::ASTNodeType::LINK_END, pairs[1][0], pairs[1][1], nts::ASTNodeType::LINK, pairs[0][0]);
}

void nts::Parser::addChipsetNode(std::string word1, std::string word2) {
	createAndPushANewNode(nts::ASTNodeType::COMPONENT, word1, word2, nts::ASTNodeType::SECTION, ".chipsets:");
}

void nts::Parser::getWords(const std::string &input, int state) {
	std::string word1, word2, copy;
	std::stringstream stringstream;

	copy = input;
	stringstream.str(copy.c_str());
	stringstream >> word1 >> word2;
	if (state == 1)
		addChipsetNode(word1, word2);
	else
		addLinkNode(word1, word2);
}

void nts::Parser::feed(std::string const &input) {
	std::string copy = input;
	static int state = 0;

	if (input == ".chipsets:" || (input == ".links:" && state == 1)) {
		state = (input == ".chipsets:" ? 1 : 2);

		nts::t_ast_node *targetNode = createTree();
		targetNode->type = nts::ASTNodeType::SECTION;
		targetNode->lexme = input;
		targetNode->value = "";
		_root->children->push_back(targetNode);
		return;
	}
	if (state == 0) {
		Logger::log(Logger::Level::Error, ".chipsets: must be the first non-comment line in the configuration file",
					true);
	}
	getWords(input, state);
}

void nts::Parser::createListOfComponents() {
	nts::t_ast_node *childrenNode = (t_ast_node *) getNode(nts::ASTNodeType::SECTION, ".chipsets:", _root->children);
	nts::ComponentCreator factory;

	for(std::vector<t_ast_node *>::iterator it = childrenNode->children->begin();
		it < childrenNode->children->end(); it++) {
		try {
			_componentList.push_back(factory.createComponent((*it)->lexme, (*it)->value));
		}
		catch (std::exception e) {
			Logger::log(Logger::Error, "Component " + (*it)->lexme + " is undefined, aborting", true);
		}
	}
}

nts::IComponent *nts::Parser::getItemFromList(std::string lexmeValue) {
	for(std::vector<IComponent *>::iterator it = _componentList.begin(); it < _componentList.end(); it++) {
		if ((*it)->getName() == lexmeValue)
			return (*it);
	}
	return (nullptr);
}

void nts::Parser::linkEveryComponent() {
	nts::t_ast_node *childrenNode = (t_ast_node *) getNode(nts::ASTNodeType::SECTION, ".links:", _root->children);
	IComponent *linker;
	IComponent *toBeLinked;

	for(std::vector<t_ast_node *>::iterator it = childrenNode->children->begin();
		it < childrenNode->children->end(); it++) {
		linker = getItemFromList((*it)->lexme);
		toBeLinked = getItemFromList((*it)->children->at(0)->lexme);
		if (!linker || !toBeLinked)
			//TODO: Changer ce message d'erreur de merde
			Logger::log(Logger::Error, "!linker || !toBeLinked", true);
		try {
			if (dynamic_cast<nts::Component::COutput *> (linker) != nullptr) {
				linker->SetLink((size_t) std::stoul((*it)->value) - 1, *toBeLinked,
								(size_t) std::stoul((*it)->children->at(0)->value) - 1);
			} else {
				toBeLinked->SetLink(((size_t) std::stoul((*it)->children->at(0)->value) - 1), *linker,
									(size_t) std::stoul((*it)->value) - 1);
			}
		}
		catch (std::exception e) {
			Logger::log(Logger::Error,
						"On line " + (*it)->lexme + ":" + (*it)->value + " " + (*it)->children->at(0)->lexme + ":" +
						(*it)->children->at(0)->value + ", linkage of a pin that dosn't exists.",
						true);
		}
	}

}

void nts::Parser::parseTree(nts::t_ast_node &root) {

	createListOfComponents();
	linkEveryComponent();
	printf("Im a separator lol \n\n");

}

// TODO: Faire la fonction qui delete en deep;
nts::t_ast_node *nts::Parser::createTree() {
	nts::t_ast_node *newItem = new nts::t_ast_node(nullptr);

	newItem->children = new std::vector<t_ast_node *>;
	newItem->type = nts::ASTNodeType::DEFAULT;
	newItem->lexme = "";
	newItem->value = "";
	return (newItem);
}

nts::t_ast_node *nts::Parser::getRoot() const {
	return _root;
}

const std::vector<nts::IComponent *> &nts::Parser::getComponentList() const {
	return _componentList;
}
