#include "TokenStream.hpp"
#include "../std_lib/std_lib_facilities.h"

Token TokenStream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch(ch)
    {
        case '=': case 'x':
        case '(': case ')':
        case '+': case '-': case '*': case '/':
            return Token(ch);
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                std::cin.putback(ch);
                double val;
                cin >> val;
                return Token('8', val);
            }
        default:
            error("Bad token");
    }
}

void TokenStream::putback(Token t)
{
    full = true;
    buffer = t;
}
