//

// Created by Pierre Bougon on 02/02/17.
//

#ifndef NANOTEKSPICE_IPARSER_H_
#define NANOTEKSPICE_IPARSER_H_


#include <zconf.h>
#include <vector>
#include <string>

namespace nts
{
    enum class ASTNodeType : int
    {
        DEFAULT = -1,
        NEWLINE = 0,
        SECTION,
        COMPONENT,
        LINK,
        LINK_END,
        STRING
    };

    typedef struct      s_ast_node
    {
        s_ast_node(std::vector<struct s_ast_node *> *children) : children(children){};
        std::string                         lexme;
        ASTNodeType                         type;
        std::string                         value;
        std::vector<struct s_ast_node *>    *children;
    }                   t_ast_node;

    class IParser
    {
    public:
        virtual             ~IParser(){};
        virtual void        feed(std::string const &input) = 0;
        virtual void        parseTree(t_ast_node & root) = 0;
        virtual t_ast_node  *createTree() = 0;
    };
}


#endif // !NANOTEKSPICE_IPARSER_H_
