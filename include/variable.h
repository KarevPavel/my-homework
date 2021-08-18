#pragma once

#include <astnode.hpp>

class Variable : public ASTNode {
public:
    explicit Variable(std::string name)
            : ASTNode(name)
            , name_(name) {}

    std::string name() const { return name_; }

private:
    std::string name_;
};