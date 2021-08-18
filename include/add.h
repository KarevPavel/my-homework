#pragma once

#include "astnode.hpp"

class Add : public ASTNode {
public:
    explicit Add(ASTNode *pNode, ASTNode *pAstNode)
            : ASTNode("+", pNode, pAstNode) {}
};