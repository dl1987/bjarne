#include <iostream>
#include "TokenStream.hpp"
#include "../std_lib/std_lib_facilities.h"

TokenStream ts;

Token get_token()
{
    char ch;
    std::cin >> ch;

    switch(ch)
    {
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);
        case '.': case '0': case '1': case '2': case '3': case '4':
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

double expression();

double primary()
{
    Token t = ts.get();
    switch(t.kind)
    {
        case '(':
        {
            auto ex = expression();
            t = ts.get();
            if(t.kind != ')') error("')' expected");
            return ex;
        }
        case '8':
            return t.value;
        default:
            ts.putback(t);
            error("primary expected");
    }
}

double term()
{
    auto left = primary();
    Token t = ts.get();
    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
                {
                    auto prim = primary();
                    if(prim == 0) error("divide by 0");
                    left /= prim;
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression()
{
    auto left = term();
    Token t = ts.get();
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

int main()
{
    try {
        double val = 0;
        while(cin)
        {
            Token t = ts.get();
            if(t.kind == 'x') break;
            if(t.kind == '=') cout << val << "\n";
            else ts.putback(t);
            val = expression();
        }
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "wyjatek";
        return 2;
    }
}