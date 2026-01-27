/*

implement a hierarchy of classes for arithmetic expression manipulations:
    - the classes holds, evaluates and prints arithmetic expressions
    - print in infix, prefix or postfix notation

Additional work:
   - note that the postfix notation is also called Reverse Polish notation (RPN)
   - it is a mathematical notation in which operators follow their operands
   - this notation does not need any parentheses i.e. this notation is non ambigu
   - => you can read (easily) RPN expressions using a stacks
  implement a code to read RPN expression and store them with your class objects
  RPN arithmetic expression are passed as main command-line arguments

./main 87 12 - + 75 -
*/
#include <iostream>
#include <stdexcept>

class Expr {
public:
    virtual int evaluation() const = 0;
    virtual void print() const = 0;
    virtual ~Expr() {}
};

class Constante : public Expr {
    int value;

public:
    Constante(unsigned int v) : value(v) {}

    int evaluation() const override {
        return value;
    }

    void print() const override {
        std::cout << value;
    }
};

class Unaryexpr : public Expr {
    const Expr& expr;

public:
    UnaryMinus(const Expr& e) : expr(e) {}

    int eval() const override {
        return -expr.eval();
    }

    void print() const override {
        expr.print();
        std::cout << " -";
    }
};

class BinaryExpr : public Expr {
protected:
    const Expr& gauche;
    const Expr& droit;

public:
    BinaryExpr(const Expr& l, const Expr& r)
        : gauche(l), droit(r) {}
};

class Plus : public BinaryExpr {
public:
    Plus(const Expr& l, const Expr& r)
        : BinaryExpr(l, r) {}

    int evaluation() const override {
        return gauche.evaluation() + droit.evaluation();
    }

    void print() const override {
        gauche.print();
        droit.print();
        std::cout << " +";
    }
};

class Minus : public BinaryExpr {
public:
    Minus(const Expr& l, const Expr& r)
        : BinaryExpr(l, r) {}

    int evaluation() const override {
        return gauche.eval() - droit.eval();
    }

    void print() const override {
        gauche.print();
        droit.print();
        std::cout << " -";
    }
};


int main()
{
    try
    {
        // Constant c1(12), c2(-87), c3(23); // try it (-87 is not an unsigned int)
        Constant c1(12), c2(87), c3(75);

        c1.print(); // affiche 12
        std::cout << std::endl;
        std::cout << "eval " << c1.eval() << std::endl; // affiche 12

        UnaryMinus u1(c1);
        u1.print(); // affiche 12 -
        std::cout << std::endl;
        std::cout << "eval " << u1.eval() << std::endl; // affiche -12

        Plus p1(c2, u1);
        p1.print(); // affiche 87 12 -+
        std::cout << std::endl;
        std::cout << "eval " << p1.eval() << std::endl; // affiche 75

        Minus m1(p1, c3);
        m1.print(); // 87 12 -+75 -
        std::cout << std::endl;
        std::cout << "eval " << m1.eval() << std::endl; // affiche 0

        Divide d1(p1, m1);
        std::cout << std::endl;
        std::cout << d1.eval() << std::endl; // throws an instance of 'std::runtime_error'

        std::vector<???> expr;
        expr.push_back(???c1);
        expr.push_back(???u1);
        // parcourez le vecteur
    }
    catch (std::runtime_error &e)
    {
        // affiche zero divide error
        std::cout << e.what() << std::endl;
    }
    return 0;
}
