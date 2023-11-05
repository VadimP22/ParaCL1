#pragma once

#include "Token.h"

namespace pcl {
    enum class KeywordType {
        While,
        If,
        Print,
        True,
        False,
    };
    
    class KeywordToken : public Token {
        public:
        static const TokenKind Kind = 0;      
        KeywordToken(KeywordType type) : Token(Kind), type_(type) {}

        KeywordType GetType() { return type_; }

        private:
        KeywordType type_;
    };

    class ScopeOpenToken : public Token {
        public:
        static const TokenKind Kind = 1;
        ScopeOpenToken() : Token(Kind) {}
    };

    class ScopeCloseToken : public Token {
        public:
        static const TokenKind Kind = 2;
        ScopeCloseToken() : Token(Kind) {}
    };

    class BracketOpenToken : public Token {
        public:
        static const TokenKind Kind = 3;
        BracketOpenToken() : Token(Kind) {}
    };

    class BracketCloseToken : public Token {
        public:
        static const TokenKind Kind = 4;
        BracketCloseToken() : Token(Kind) {}
    };

    enum class BinaryOperatorType {
        Assignment,
        Addition,  
        Subtraction,
        Multiplication,
        Division,
        Equal,
        NotEqual,
        Greater,
        GreaterOrEqual,
        Less,
        LessOrEqual,
    };

    class BinaryOperatorToken : public Token {
        public:
        static const TokenKind Kind = 5;
        BinaryOperatorToken(BinaryOperatorType type) : Token(Kind), type_(type) {}

        BinaryOperatorType GetType() { return type_; }

        private:
        BinaryOperatorType type_;
    };

    class IntegerLiteral : public Token {
        public:
        static const TokenKind Kind = 6;
        IntegerLiteral(char *begin, char *end) : Token(Kind) {}

        //TODO: Do I need such complicated interface?

        int GetValue() {
            if (is_negative_)
                return -1 * absolute_value_;

            return absolute_value_;
        }

        unsigned GetAbsoluteValue() { return absolute_value_; }
        bool IsNegative() { return is_negative_; }

        private:
        unsigned absolute_value_;
        bool is_negative_;
    };

    class DelemiterToken : public Token {
        public:
        static const TokenKind Kind = 7;  
        DelemiterToken() : Token(Kind) {}
    };
}; // namespace pcl
