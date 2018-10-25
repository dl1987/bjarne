#include "Token.hpp"

class TokenStream
{
public:
    TokenStream() : full(false), buffer(0){}
    Token get();
    void putback(Token);
private:
    bool full;
    Token buffer;
};
