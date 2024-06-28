//
// File:   ExpTree.cpp
// Author: Adam.Lewis@athens.edu
// Purpose:
// Use the tree class from lecture to build an expression tree. By intent, we
// don't use inheritance here as we're using the Tree rather than extending it.
//
#include <stack>
#include <string>
#include <cstring>
#include <iostream>
#include "Tree.hpp"
using namespace std;

enum NodeTypes { NUMBER, OPERATOR};

struct ExpNode {
    NodeTypes nodetype;
    double operand;
    string op;
    ExpNode(NodeTypes typ, double opd = 0, string opr = "") :nodetype(typ), operand(opd), op(opr) {}
    ExpNode(double opd): nodetype(NUMBER), operand(opd), op("") {}
    ExpNode(string op): nodetype(OPERATOR), operand(0.0), op(op) {}
    bool operator<(const ExpNode &rhs) { 
        return true;
    }
};
void printNode(ExpNode aNode) {
    if (aNode.nodetype == NUMBER) { std::cout << aNode.operand << " ";}
    else if (aNode.nodetype == OPERATOR) {std::cout << aNode.op << " "; }
    else { std::cout << "BAD NODE IN EXP TREE\n"; }
}

using TreeOfExpNodes = Tree<ExpNode>;
stack<TreeOfExpNodes> nodes;
stack<string> operations;

TreeOfExpNodes & buildExpTree(istream &ins) {
    const char DECIMAL = '.';
    const char RIGHTPAREN = ')';
    TreeOfExpNodes leftOp;
    TreeOfExpNodes rightOp;
    string str;
    while (ins && ins.peek() != '\n') {
        if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
            double opd;
            ins >> opd;
            std::cout << "NUMBER: " << opd << " ";
            ExpNode * aNewNode = new ExpNode(opd);
            nodes.push( TreeOfExpNodes{ *aNewNode } );
        }
        else if (strchr("+-*/", ins.peek())!= nullptr) {
            ins >> str;
            std::cout << "OP: " << str << " ";
            operations.push( str );
        }
        else if (ins.peek() == RIGHTPAREN) {
            std::cout << "RIGHTPAREN ";
            ins.ignore();
            rightOp = nodes.top();
            nodes.pop();
            leftOp = nodes.top();
            nodes.pop();
            str = "";
            str += operations.top();
            ExpNode * aNewNode = new ExpNode(str);
            nodes.push( TreeOfExpNodes(leftOp, *aNewNode, rightOp) );
        }
        else {
            ins.ignore();
        }
    }
    return nodes.top();
}

double computeOp(string op, double leftrand, double rightrand) {
    double result = 0.0;
    if (op == "+") {
        result = leftrand + rightrand;
    }
    else if (op == "-") {
        result = leftrand - rightrand;
    }
    else if (op == "*") {
        result = leftrand * rightrand;
    }
    else if (op == "/") {
        result = leftrand / rightrand;
    }
    else {
        std::cerr << "Bad operator in expression, operator was " << op << std::endl;
    }
    return result;
}
//
// Algorithm:
// Do an in-order traversal of the tree (note: will
// need to adjust the return type of the function)
//
// If anExpTree is not empty
//    if anExpTree. root is an operand
//       return that value
//    else
//        A = evalExpTRee(anExpTree.left())
//        B = evalExpTree(anExpTree.right())
//        Op = anExpTree.root()
//        return A Op B
//
int evalExpTree(TreeOfExpNodes anExpTree) {
    if (!anExpTree.isEmpty()) {
        if (anExpTree.root().nodetype == NUMBER) {
            return anExpTree.root().operand;
        }
        else {
            double A = evalExpTree(anExpTree.left());
            double B = evalExpTree(anExpTree.right());
            ExpNode opnode = anExpTree.root();
            return computeOp(opnode.op, A, B);
        }
    }
    else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    string exp = "";
    cout << "Enter an expression in infix format: ";
    TreeOfExpNodes expTree = buildExpTree(cin);
     cout << "Pre-order traversal of expression tree" << endl;
    expTree.preorder(printNode);
    cout << "In-order traversal of expression tree" << endl;
    expTree.inorder(printNode);
    int result = evalExpTree(expTree);
    std::cout << "Result of evaluated expression is: " << result << std::endl;
    return 0;
}
