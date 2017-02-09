//
// Created by peau_c on 2/6/17.
//

#ifndef NANOTEKSPICE_PARSER_H
#define NANOTEKSPICE_PARSER_H

#include "IParser.h"

namespace nts {
	class Parser : public nts::IParser {
	public:
							Parser();
		virtual             ~Parser();
		virtual void        feed(std::string const &input);
		virtual void        parseTree(t_ast_node &root);
		virtual t_ast_node  *createTree();
	protected:
		t_ast_node  *_root;

		void feedChipsets(const std::string &input);
		void feedLinks(const std::string &input);
		bool checkIfKeywordOrComponent(std::string toBeChecked);
		void *getNode(ASTNodeType type, std::string string, std::vector<s_ast_node *> *actualLeaf);
	};
}

#endif //NANOTEKSPICE_PARSER_H
