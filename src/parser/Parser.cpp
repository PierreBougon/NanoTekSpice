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

void nts::Parser::feed(std::string const &input) {
	std::string copy = input;
	static int state = 0;

	if (input == ".chipsets:" || input == ".links:") {
		state = (input == ".chipsets:" ? 1 : 2);

		nts::t_ast_node *chipsetNode = new nts::t_ast_node(nullptr);
		chipsetNode->type = nts::ASTNodeType::SECTION;
		chipsetNode->lexme = input;
		chipsetNode->value = "";
		chipsetNode->children = nullptr;
		_root->children->push_back(chipsetNode);
		return;
	}
	if (state == 0) {
		Logger::log(Logger::Level::Error, ".links is before .chipset in the configuration file\n", true);
	}
	if (state == 1) {
		feedChipsets(input);
	} else if (state == 2) {
		feedLinks(input);
	}
}

//TODO: Check avec la liste des noms des components;
bool nts::Parser::checkIfKeywordOrComponent(std::string toBeChecked) {
	return (toBeChecked == "input" || toBeChecked == "output");
}

void *nts::Parser::getNode(nts::ASTNodeType type, std::string string, std::vector<s_ast_node *> *root) {
	t_ast_node *node = nullptr;

	if (!root)
		return (nullptr);
	for(std::vector<s_ast_node *>::iterator it = root->begin();it < root->end(); it++) {
		node = (t_ast_node *) getNode(type, string, (*it)->children);
		printf("Tested values : %d\n%s\n Normal Values : %d\n%s\n", (*it)->type, (*it)->lexme.c_str(), type, string.c_str());
		if ((*it)->type == type && (*it)->lexme == string) {
			printf("FOUND\n");
			return (*it);
		}
		if (node)
			break;
	}
	return (node);
}

void nts::Parser::feedChipsets(const std::string &input) {
	t_ast_node *newNode = createTree();
	std::string word1, word2, copy;
	std::stringstream stringstream;

	copy = input;
	stringstream.str(copy.c_str());
	printf("stringstream.str = %s\n", stringstream.str().c_str());
	copy = input;
	stringstream >> word1 >> word2;
	printf("values = |%s| |%s|\n", word1.c_str(), word2.c_str());
	if (!checkIfKeywordOrComponent(word1)) {
		Logger::log(Logger::Error, "On line : " + copy + " first word is neither a component or a keyword\n", true);
	}
	newNode->type = nts::ASTNodeType::COMPONENT;
	newNode->lexme = word1;
	newNode->value = word2;
	getNode(nts::ASTNodeType::SECTION, ".chipsets:", _root->children);
	exit(1);
}
void nts::Parser::feedLinks(const std::string &input) {
	printf("links = %s\n", input.c_str());
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
