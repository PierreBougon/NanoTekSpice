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
		void checkChipset();
		void checkLinks();
	protected:
		t_ast_node  *_root;

		bool checkIfKeywordOrComponent(std::string toBeChecked);
		void *getNode(ASTNodeType type, std::string string, std::vector<s_ast_node *> *actualLeaf);
		void addChipsetNode(std::string word1, std::string word2);
		void getWords(const std::string &input, int state);
		void addLinkNode(std::string word1, std::string word2);
		void createAndPushANewNode(ASTNodeType section, std::string lexme, std::string value, ASTNodeType sectionTarget,
							   std::string lexmeTarget);
	};
}

#endif //NANOTEKSPICE_PARSER_H
