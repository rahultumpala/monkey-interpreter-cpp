//
// Created by rahultumpala on 7/4/23.
//

#ifndef MONKEYINTERPRETER_AST_H
#define MONKEYINTERPRETER_AST_H

#include <vector>
#include <string>
#include "../token/token.h"

namespace astNs {

    class astNode {
    public:
        virtual string tokenLiteral() = 0;

        virtual string String() = 0;
    };

    class expression : public astNode {
    public:
        virtual void expressionNode() = 0;
    };

    class statement : public astNode {
    public:
        virtual void statmentNode() = 0;
    };

    class identifier : public expression {
    public:
        std::string value;
        token *token;


        identifier(class token *t, string v) {
            this->token = t;
            this->value = std::move(v);
        }

        string tokenLiteral() override {
            return token->token_literal();
        }

        string String() override {
            return value;
        }

        void expressionNode() override {

        }
    };

    class integerLiteral : public expression {
    public:
        token *token;
        int value;

        integerLiteral(class token *t, int v) {
            token = t;
            value = v;
        }

        string tokenLiteral() override {
            return token->token_literal();
        }

        string String() override {
            return to_string(value);
        }

        void expressionNode() override {

        }

    };


    class letStatement : public statement {
    public:
        token *token;
        identifier *name;
        expression *value;

        letStatement(class token *t, identifier *name, expression *value) {
            this->token = t;
            this->name = name;
            this->value = value;
        }

        string tokenLiteral() override {
            return token->token_literal();
        }

        string String() override {
            return tokenLiteral() + " " + name->String() + " = " + value->String() + " ;";
        }

        void statmentNode() override {
        }
    };

    class ast {
    public:
        vector<astNode *> program;

        ast(vector<astNode *> pr) {
            this->program = pr;
        }
    };
}
#endif //MONKEYINTERPRETER_AST_H
