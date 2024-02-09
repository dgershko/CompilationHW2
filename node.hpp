#include <iostream>
#include <vector>
#include <string>

typedef std::vector<NExpression *> ExpressionList;
typedef std::vector<NStatement *> StatementList;
typedef enum binop
{
    ADD,
    SUB,
    MUL,
    DIV
} BinOp;
typedef enum relop
{
    EQ,
    NEQ,
    GT,
    GTE,
    LT,
    LTE
} RelOp;
typedef enum numtype
{
    INT,
    BYTE,
    BOOL
} NumType;

class Node
{
public:
    virtual ~Node() {}
};

class NExpression : public Node
{
};

class NStatement : public Node
{
};

class NBlock : public NExpression
{
public:
    StatementList statements;
    NBlock() = default;
    NBlock(const NStatement &stmt) : statements(1, &stmt) {}
};
class Ninteger : public NExpression
{
public:
    int value;
    NumType type;
    Ninteger(int value) : value(value) {}
    Ninteger(int value, NumType type) : value(value), type(type) {}
};

class NCast : public NExpression {
public:
    NumType to;
    NExpression& expr;
    NCast(NumType to, NExpression& expr) : to(to), expr(expr) {}
};

class NIdentifier : public NExpression
{
public:
    std::string name;
    NIdentifier(const std::string &name) : name(name) {}
};

class NCall : public NExpression
{
public:
    const NIdentifier &id;
    NExpression &arg;
    NCall(const NIdentifier &id, NExpression &argument) : id(id), arg(argument) {}
    // NCall(const NIdentifier& id) : id(id) {}
};

class NAnd : public NExpression
{
public:
    NExpression &left;
    NExpression &right;
    NAnd(NExpression &left, NExpression &right) : left(left), right(right) {}
};

class NOr : public NExpression
{
public:
    NExpression &left;
    NExpression &right;
    NOr(NExpression &left, NExpression &right) : left(left), right(right) {}
};

class NNot : public NExpression
{
public:
    NExpression &expr;
    NNot(NExpression &expr) : expr(expr) {}
};

class NBinOp : public NExpression
{
public:
    const BinOp op_type;
    NExpression &left;
    NExpression &right;
    NBinOp(NExpression &left, BinOp op, NExpression &right) : left(left), op_type(op), right(right) {}
};

class NRelOp : public NExpression
{
public:
    const RelOp op_type;
    NExpression &left;
    NExpression &right;
    NRelOp(NExpression &left, RelOp op, NExpression &right) : left(left), op_type(op), right(right) {}
};

class NAssign : public NExpression
{
    NIdentifier &left;
    NIdentifier &right;
    NAssign(NIdentifier &left, NIdentifier &right) : left(left), right(right) {}
};

// class NBlock : public NExpression {
// public:
//     StatementList statements;
//     NBlock() {}
// };

#define YYSTYPE Node *