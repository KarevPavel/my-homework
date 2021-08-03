// OTUS C++ Basic course homework skeleton.
// Lexer interface

#pragma once

#include <istream>
#include <string>

class Lexer {
public:
    enum class Token {
        Number,
        Operator,
        End,
        Lbrace,
        Rbrace,
        Name,
        Error
    };

    explicit Lexer(std::istream &in);

    Lexer(const Lexer &other) = delete;

    Lexer &operator=(const Lexer &other) = delete;

    Token next_token();

    int get_number() const { return number_; }

    std::string get_operator() const { return operator_; }

    std::string get_name() const { return name_; }

protected:
    bool isrbrace() const;

    bool islbrace() const;

    bool isbrace() const;

    bool isoperator() const;

private:
    enum class State {
        Empty,
        ReadNumber,
        ReadName,
        End,
    };

    char next_not_space_char();
    char next_char();
    static void throwIf(bool condition, const std::string & msg);
    bool end() const;

    State state_;
    std::string name_;
    int number_;
    std::string operator_;
    char ch_;
    std::istream &in_;
};

inline Lexer::Lexer(std::istream &in)
        : state_(State::Empty), number_(0), in_(in) {
    next_char();
}

inline char Lexer::next_not_space_char() {
    for (in_.get(ch_); isspace(ch_); in_.get(ch_)) {
        if (end()) {
            break;
        }
    }
    return ch_;
}

inline char Lexer::next_char() {
    in_.get(ch_);
    return ch_;
}

inline bool Lexer::end() const { return in_.eof() || ch_ == '\n'; }

inline bool Lexer::isrbrace() const { return ch_ == ')'; }

inline bool Lexer::islbrace() const { return ch_ == '('; }

inline bool Lexer::isbrace() const { return islbrace() || isrbrace(); }

inline bool Lexer::isoperator() const {
    return ch_ == '+' || ch_ == '-' || ch_ == '*' || ch_ == '/';
}
