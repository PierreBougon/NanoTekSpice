//
// Created by peau_c on 2/6/17.
//

#ifndef NANOTEKSPICE_PARSER_H
#define NANOTEKSPICE_PARSER_H

#include "components/ComponentCreator.h"
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

		void setBaseValuesFromArgument(char **av);
		void *getNode(ASTNodeType type, std::string string, std::vector<s_ast_node *> *actualLeaf);
		IComponent *getItemFromList(std::string lexmeValue);
		const std::vector<IComponent *> &getComponentList() const;
		t_ast_node *getRoot() const;
			private:
		t_ast_node  				*_root;
		std::vector<IComponent *>	_componentList;
		void addChipsetNode(std::string word1, std::string word2);
		void getWords(const std::string &input, int state);
		void addLinkNode(std::string word1, std::string word2);
		void createAndPushANewNode(ASTNodeType section, std::string lexme, std::string value, ASTNodeType sectionTarget, std::string lexmeTarget);
		void createListOfComponents();
		void linkEveryComponent();
		void *deleteChildrenRecursively(std::vector<s_ast_node *> *root);
		Tristate determineTristateValue(int trist);
	};
}

#endif //NANOTEKSPICE_PARSER_H
