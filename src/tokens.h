#ifndef _COREVM_PARSER_TOKENS_DEF_H_
#define _COREVM_PARSER_TOKENS_DEF_H_
#include <cstddef>
#include <string>

extern "C" {
	#include <regexpm/parser.h>
}

namespace Assembler {
	typedef enum {
		ID,
		NUM,
		COMMA,
		ARROW,
		LPAREN,
		RPAREN,
		FUNCTION,
		TOKEN_EOF,
		INVALID_TOKEN
	} TOKEN_ID;

	class Token {
	private:
		TOKEN_ID _id;
		std::string _data;

	public:
		Token();
		Token(TOKEN_ID id);
		Token(TOKEN_ID id, char const* input, size_t len);
		~Token();

		TOKEN_ID id() const;
		char const* asString() const;
		int asInt() const;
	};

	class Tokeniser {
	private:
		regex idRegex;
		regex intRegex;
		int _numProcessedLines;

		char const* skipWhite(char const* input);
	public:
		Tokeniser();
		~Tokeniser();
		Token peekToken(char const* input, size_t& len);
		Token peekToken(char const* input);
		Token nextToken(char const*& input);
		void resetLines();
	};
}

#endif //_COREVM_PARSER_TOKENS_DEF_H_
