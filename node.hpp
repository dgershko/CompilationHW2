#include <iostream>
#include <vector>
#include <string>

typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NStatement*> StatementList;
typedef enum binop{
    ADD, SUB, MUL, DIV
} BinOp;
typedef enum relop {
    EQ, NEQ, GT, GTE, LT, LTE
} RelOp;

class Node {
public:
    virtual ~Node() {}
};

class NExpression : public Node {
};

class NStatement : public Node {
};

class Ninteger : public NExpression {
public:
    int value;
    Ninteger(int value) : value(value) {}
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) {}
};

class NCall : public NExpression {
public:
    const NIdentifier& id;
    NExpression& arg;
    NCall(const NIdentifier& id, NExpression& argument) : id(id), arg(argument) {}
    // NCall(const NIdentifier& id) : id(id) {}
};

class NBinOp : public NExpression {
public:
    const BinOp op_type;
    NExpression& left;
    NExpression& right;
    NBinOp(NExpression& left, BinOp op, NExpression& right) : 
        left(left), op_type(op), right(right) { }
};

class NRelOp : public NExpression {
public: 
    const RelOp op_type;
    NExpression& left;
    NExpression& right;
    NRelOp(NExpression& left, RelOp op, NExpression& right) :
        left(left), op_type(op), right(right) {}

};

class NAssign : public NExpression {
    NIdentifier& left;
    NIdentifier& right;
    NAssign(NIdentifier& left, NIdentifier& right) : 
        left(left), right(right) {}
};

// class NBlock : public NExpression {
// public:
//     StatementList statements;
//     NBlock() {}
// };

#define YYSTYPE Node*