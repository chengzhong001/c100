#include <cstdio>
#include <iostream>

#include "CodeGen.h"
#include "Lexer.h"
#include "Parser.h"
// #include "PrintVisitor.h"

using namespace C100;

const char *code = "  5 + 1 - 3*4/2";
void testLexer() {
    Lexer lexer(code);

    do {
        lexer.GetNextToken();
        std::cout << lexer.CurrentToken->Content << std::endl;
    } while (lexer.CurrentToken->Kind != TokenKind::Eof);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("please input: ./c100 code\n");
        return 0;
    }

    const char *source = argv[1];
    Lexer lex(source);
    lex.GetNextToken();

    Parser parser(lex);
    CodeGen codeGen;
    // PrintVisitor visitor;

    auto root = parser.Parse();
    root->Accept(&codeGen);

    return 0;
}