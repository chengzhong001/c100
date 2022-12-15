#ifndef C100_PARSER_H
#define C100_PARSER_H

#include <memory>

#include "AstNode.h"
#include "Lexer.h"

namespace C100 {
class Parser {
private:
    Lexer &Lex;

public:
    Parser(Lexer &lex) : Lex(lex) {}
    std::shared_ptr<ProgramNode> Parse();

private:
    std::shared_ptr<AstNode> ParseExpr();
    std::shared_ptr<AstNode> ParseAddExpr();
    std::shared_ptr<AstNode> ParseMultiExpr();
    std::shared_ptr<AstNode> ParsePrimaryExpr();
};

}  // namespace C100

#endif