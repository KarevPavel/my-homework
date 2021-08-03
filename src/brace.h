#pragma once

#include <astnode.hpp>

class Brace : public ASTNode {
public:

    explicit Brace(ASTNode *pNode, ASTNode *pAstNode)
            : ASTNode("()", pNode, pAstNode) {}
};