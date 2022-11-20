#include "Lexer.h"
#include "Parser.h"
#include "PrintVisitor.h"
#include <iostream>

using namespace C100;

const char *code = "  5 + 1 - 3*4/2";
void testLexer() {
    Lexer lexer(code);

    do {
        lexer.GetNextToken();
        std::cout << lexer.CurrentToken->Content << std::endl;
    } while (lexer.CurrentToken->Kind != TokenKind::Eof);
}

int main() {
    Lexer lex(code);
    lex.GetNextToken();
    Parser parser(lex);
    PrintVisitor visitor;
    auto root = parser.Parse();
    root->Accept(&visitor);

    return 0;
}