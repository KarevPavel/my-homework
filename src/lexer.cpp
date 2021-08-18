// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include "lexer.hpp"
#include <cctype>

Lexer::Token Lexer::next_token() {
    for (;;) {
        switch (state_) {
            case State::End:
                return Token::End;
            case State::ReadNumber:
                if (end()) {
                    state_ = State::End;
                    return Token::Number;
                }
                if (std::isdigit(ch_)) {
                    number_ = 10 * number_ + (ch_ - '0');
                    state_ = State::ReadNumber;
                    next_char();
                    throwIf(std::isalpha(ch_),
                            "Нельзя указывать число и переменную слитно!");
                    break;
                }
                state_ = State::ReadOperator;
                return Token::Number;
            case State::ReadName:
                if (end()) {
                    state_ = State::End;
                    return Token::Name;
                }
                if (std::isalpha(ch_)) {
                    name_ += ch_;
                    throwIf(std::isdigit(ch_),
                            "Нельзя указывать переменную и число слитно!");
                    next_char();
                    break;
                }
                state_ = State::ReadOperator;
                return Token::Name;
            case State::ReadOperator:
/*                if (end()) {
                    throwIf(true,
                            "Ожидался оператор!");
                }*/
                if (std::isspace(ch_)) {
                    next_char();
                    state_ = State::ReadOperator;
                    break;
                }
                if (islbrace()) {
                    name_ += ch_;
                    next_char();
                    state_ = State::Empty;
                    return Token::Lbrace;
                }
                if (isrbrace()) {
                    name_ += ch_;
                    next_char();
                    state_ = State::Empty;
                    return Token::Rbrace;
                }
                if (std::isalpha(ch_)) {
                    throwIf(true,
                            "Между пременными/числами должен быть оператор!");
                }
                if (std::isdigit(ch_)) {
                    throwIf(true,
                            "Между пременными/числами должен быть оператор!");
                }
                if (isoperator()) {
                    operator_ = ch_;
                    next_char();
                    state_ = State::Empty;
                    return Token::Operator;
                }
                return Token::End;
            case State::Empty:
                if (end()) {
                    state_ = State::End;
                    return Token::End;
                }
                if (std::isspace(ch_)) {
                    next_not_space_char();
                    break;
                }
                if (isoperator()) {
                    operator_ = ch_;
                    next_not_space_char();
                    throwIf(name_.empty() && number_ == 0,
                            "Перед оператором должна быть либо переменная, либо число!");
                    throwIf(end(),
                            "После оператора должна быть либо переменная, либо число!");

                    return Token::Operator;
                }
                if (islbrace()) {
                    name_ += ch_;
                    next_not_space_char();
                    state_ = State::Empty;
                    return Token::Lbrace;
                }
                if (isrbrace()) {
                    name_ += ch_;
                    next_not_space_char();
                    state_ = State::Empty;
                    return Token::Rbrace;
                }
                if (std::isdigit(ch_)) {
                    number_ = ch_ - '0';
                    state_ = State::ReadNumber;
                    next_char();
                    break;
                }
                if (std::isalpha(ch_)) {
                    name_ = ch_;
                    state_ = State::ReadName;
                    next_char();
                    break;
                }
        }
    }
}

void Lexer::throwIf(bool condition, const std::string &msg) {
    if (condition) {
        throw std::invalid_argument(msg);
    }
}

