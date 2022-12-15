#ifndef C100_LEXER_H
#define C100_LEXER_H

#include <memory>
#include <string_view>

namespace C100 {
enum class TokenKind {
    Add,
    Sub,
    Mul,
    Div,
    Num,
    LParent,
    RParent,
    Eof,
};

class Token {
public:
    TokenKind Kind;
    int Value;
    std::string_view Content;
};

class Lexer {
private:
    std::string_view SourceCode;
    char CurChar{' '};
    int Cursor{0};

public:
    std::shared_ptr<Token> CurrentToken;

public:
    Lexer(const char* code) : SourceCode(code) {}
    void GetNextToken();
    void GetNextChar();
};

}  // namespace C100

#endif