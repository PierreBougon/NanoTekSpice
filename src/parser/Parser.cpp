//
// Created by peau_c on 2/6/17.
//

#include "parser/Parser.h"

nts::Parser::Parser() {
	_root = nullptr;
}

nts::Parser::~Parser() {
}

void nts::Parser::feed(std::string const &input) {

}

void nts::Parser::parseTree(nts::t_ast_node &root) {

}

// TODO: Faire la fonction qui delete en deep;
nts::t_ast_node *nts::Parser::createTree() {
	nts::t_ast_node *newItem = new nts::t_ast_node(nullptr);

	newItem->children = nullptr;
	newItem->type = nts::ASTNodeType::DEFAULT;
	return (newItem);
}
