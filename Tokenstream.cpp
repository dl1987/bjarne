/*
 * Tokenstream.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: dawlap
 */

#include "Tokenstream.hpp"

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}
Token_stream::~Token_stream() {
	// TODO Auto-generated destructor stub
}

void Token_stream::putback(Token t)
{
	if(full) error("wywolanie funkcji putback(), gdy bufor jest pelny");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if(full)
	{
		full=false;
		return buffer;
	}

	char ch;
	std::cin >> ch;

	switch(ch)
	{
	case '=':
	case 'x':
	case '{': case '}': case '(': case ')':
	case '+': case '-': case '*': case '/':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	}
	default:
		error("Nieprawidlowy token");
	}
}

