/*
 * Token.hpp
 *
 *  Created on: Jul 24, 2017
 *      Author: dawlap
 */

#ifndef TOKEN_HPP_
#define TOKEN_HPP_

class Token
{
public:
	char kind;
	double value;

	Token(char ch)
		:kind(ch), value(0) {}
	Token(char ch, double val)
		:kind(ch), value(val) {}
};



#endif /* TOKEN_HPP_ */
