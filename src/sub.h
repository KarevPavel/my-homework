#pragma once

#include <astnode.hpp>

class Sub : public ASTNode {
public:
    explicit Sub(ASTNode *pNode, ASTNode *pAstNode)
            : ASTNode("-", pNode, pAstNode) {}
};