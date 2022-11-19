#include "Parser.h"
#include "AstNode.h"
#include "Lexer.h"
#include <memory>

using namespace C100;
std::shared_ptr<AstNode> Parser::Parse() { return ParseExpr(); }

std::shared_ptr<AstNode> Parser::ParseExpr() { return ParseAddExpr(); }

std::shared_ptr<AstNode> Parser::ParseAddExpr() {
    std::shared_ptr<AstNode> left = ParseMultiExpr();
    while (Lex.CurrentToken->Kind == TokenKind::Add ||
           Lex.CurrentToken->Kind == TokenKind::Sub) {
        BinaryOperator anOperator = BinaryOperator::Add;
        if (Lex.CurrentToken->Kind == TokenKind::Sub) {
            anOperator = BinaryOperator::Sub;
        }
        Lex.GetNextToken();
        auto node = std::make_shared<BinaryNode>();
        node->BinOp = anOperator;
        node->Lhs = left;
        node->Rhs = ParseMultiExpr();
        left = node;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseMultiExpr(){
    std::shared_ptr<AstNode> left = ParsePrimaryExpr();
    while (Lex.CurrentToken->Kind == TokenKind::Mul ||
           Lex.CurrentToken->Kind == TokenKind::Div) {
        BinaryOperator anOperator = BinaryOperator::Mul;
        if (Lex.CurrentToken->Kind == TokenKind::Div) {
            anOperator = BinaryOperator::Mul;
        }
        Lex.GetNextToken();
        auto node = std::make_shared<BinaryNode>();
        node->BinOp = anOperator;
        node->Lhs = left;
        node->Rhs = ParsePrimaryExpr();
        left = node;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParsePrimaryExpr(){
    auto node = std::make_shared<ConstantNode>();
    node->Value = Lex.CurrentToken->Value;
    Lex.GetNextToken();
    return node;
}