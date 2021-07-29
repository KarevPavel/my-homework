#pragma once

#include <astnode.hpp>

class Brace : public ASTNode {
public:
    explicit Brace(std::string brace, ASTNode *pNode, ASTNode *pAstNode)
            : ASTNode(brace, pNode, pAstNode) {}

    explicit Brace(std::string name)
            : ASTNode(name), name_(name) {}

    std::string name() const { return name_; }

private:
    std::string name_;
};