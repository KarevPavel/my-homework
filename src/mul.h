#pragma once

#include <astnode.hpp>

class Mul : public ASTNode {
public:
    explicit Mul(ASTNode *pNode, ASTNode *pAstNode)
            : ASTNode("*", pNode, pAstNode) {}
};