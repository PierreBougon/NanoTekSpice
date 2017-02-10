//
// Created by peau_c on 2/6/17.
//

#include <components/IComponent.h>
#include <Logger.h>
#include <sstream>
#include "parser/Parser.h"

nts::Parser::Parser() {
	_root = new t_ast_node(nullptr);
	_root->children = new std::vector<t_ast_node *>;
}

nts::Parser::~Parser() {
}

//TODO: Check avec la liste des noms des components;
bool nts::Parser::checkIfKeywordOrComponent(std::string toBeChecked) {
	return (toBeChecked == "input" || toBeChecked == "output");
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

void nts::Parser::checkChipset() {
	t_ast_node	*node;

	node = (t_ast_node*)getNode(nts::ASTNodeType::SECTION, ".chipsets:", _root->children);
	for (auto it = node->children->begin(); it < node->children->end(); it++) {
		printf("%s %s\n", (*it)->lexme.c_str(), (*it)->value.c_str());
	}
}

void nts::Parser::createAndPushANewNode(nts::ASTNodeType section, std::string lexme, std::string value, nts::ASTNodeType sectionTarget, std::string lexmeTarget) {
	t_ast_node	*node;
	t_ast_node *newNode = createTree();

	newNode->type = section;
	newNode->lexme = lexme;
	newNode->value = value;
	node = (t_ast_node*)getNode(sectionTarget, lexmeTarget, _root->children);
	node->children->push_back(newNode);
}
void nts::Parser::addLinkNode(std::string word1, std::string word2) {

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

		nts::t_ast_node *chipsetNode = createTree();
		chipsetNode->type = nts::ASTNodeType::SECTION;
		chipsetNode->lexme = input;
		chipsetNode->value = "";
		_root->children->push_back(chipsetNode);
		return;
	}
	if (state == 0) {
		Logger::log(Logger::Level::Error, ".chipsets: must be the first non-comment line in the configuration file\n", true);
	}
	getWords(input, state);
}

void nts::Parser::parseTree(nts::t_ast_node &root) {}

// TODO: Faire la fonction qui delete en deep;
nts::t_ast_node *nts::Parser::createTree() {
	nts::t_ast_node *newItem = new nts::t_ast_node(nullptr);

	newItem->children = new std::vector<t_ast_node *>;
	newItem->type = nts::ASTNodeType::DEFAULT;
	newItem->lexme = "";
	newItem->value = "";
	return (newItem);
}
