#include "Lexer.h"
#include <iostream>

using namespace C100;

const char *code = "  15 + 1 - 3*4/2";
void testLexer() {
    Lexer lexer(code);

    do {
        lexer.GetNextToken();
        std::cout << lexer.CurrentToken->Content << std::endl;
    } while (lexer.CurrentToken->Kind != TokenKind::Eof);
}

int main() {
    testLexer();
    return 0;
}