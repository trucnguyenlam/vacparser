#include "Tokens.h"

using namespace Parser;

std::string Token::ToString(void) const{
    return std::to_string(type) + " " + lexeme;
}

