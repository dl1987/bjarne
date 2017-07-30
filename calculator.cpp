//============================================================================
// Name        : calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "std_lib_facilities.h"
#include "Token.hpp"
#include "Tokenstream.hpp"

Token_stream ts;
double expression();

/*
 * Primary:
 * 	Number
 * 	(Expression )
 *
 */
double primary()
{

	Token t = ts.get();
	switch(t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if(t.kind != ')') error("Oczekiwano ')'");
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if(t.kind != '}') error("Oczekiwano '}'");
		return d;
	}
	case '8':
		return t.value;
	default:
		error("Oczekiwano czynnika");

	}
}

/*
 * Term:
 * 	Primary
 * 	Term * Primary
 * 	Term / Primary
 * 	Term % Primary
 *
 */
double term()
{
	double left = primary();
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
			double d = primary();
			if(d==0) error("Dzielenie przez 0");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

/*
 * Expression:
 * 	Term
 * 	Expression + Term
 * 	Expression - Term
 *
 */
double expression()
{
	double left = term();
	Token t = ts.get();
	while(true)
	{
		switch(t.kind){
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


int main(void) {
	try
	{
		double val = 0;
		while(cin)
		{
			Token t = ts.get();
			if(t.kind == 'x') break;
			if(t.kind == '=')
				cout << val << '\n';
			else
				ts.putback(t);
			val = expression();
		}
			keep_window_open();
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch(...)
	{
		cerr << "Wyjatek \n";
		keep_window_open();
		return 2;
	}
	return EXIT_SUCCESS;
}
