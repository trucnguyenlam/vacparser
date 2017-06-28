#include "Lexer.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace Parser;

int main(int argc, char const *argv[])
{
    std::ifstream t(argv[1]);
    std::stringstream buffer;

    buffer << t.rdbuf();
    std::string str = buffer.str();
    Scanner* sc = new Scanner(str);

    for (const auto & to: sc->scanTokens()){
        std::cout << to->ToString() << std::endl;
    }

    return 0;
}