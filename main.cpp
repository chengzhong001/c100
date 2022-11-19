#include "Lexer.h"
#include <cctype>
#include <iostream>

using namespace C100;
int main() {
    const char *code = "  5 + 1 - 3*4/2";
    Lexer lexer(code);

    do {
        lexer.GetNextToken();
        std::cout << lexer.CurrentToken->Content << std::endl;
    } while (lexer.CurrentToken->Kind != TokenKind::Eof);
    return 0;
    
}