#ifndef C100_CODEGEN_H
#define C100_CODEGEN_H

#include "AstNode.h"

namespace C100 {
class CodeGen : public AstVisitor {
private:
    int StackLevel{0};

public:
    CodeGen() {}
    ~CodeGen() {}
    void VisitorProgramNode(ProgramNode *node) override;

private:
    void VisitorBinaryNode(BinaryNode *node) override;
    void VisitorConstantNode(ConstantNode *node) override;

    void Push();
    void Pop(const char *reg);
};
}  // namespace C100

#endif