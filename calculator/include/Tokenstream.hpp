/*
 * Tokenstream.hpp
 *
 *  Created on: Jul 24, 2017
 *      Author: dawlap
 */

#ifndef TOKENSTREAM_HPP_
#define TOKENSTREAM_HPP_

#include "std_lib_facilities.h"
#include "Token.hpp"

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	virtual ~Token_stream();

private:
	bool full;
	Token buffer;
};

#endif /* TOKENSTREAM_HPP_ */
