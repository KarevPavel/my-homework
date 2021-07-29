#pragma once

#include <astnode.hpp>

class Div : public ASTNode {
public:
    explicit Div(ASTNode *pNode, ASTNode *pAstNode)
            : ASTNode("/", pNode, pAstNode) {}
};