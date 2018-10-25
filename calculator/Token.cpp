#include "Token.hpp"

Token::Token(char ch)
    : Token(ch, 0)
{}

Token::Token(char ch, double v)
    : kind(ch), value(v)
{}

