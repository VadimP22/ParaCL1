#pragma once

#include "Token.h"

#ifdef DEBUG_MODE
#include <ostream>
#endif

namespace pcl {
    enum class KeywordType {
        While,
        If,
        Print,
        True,
        False,
    };
    
    class KeywordToken final : public Token {
    public:
        static const TokenKind Kind = 0;      
        KeywordToken(KeywordType type) : Token(Kind), type_(type) {}

        KeywordType GetType() const { return type_; }

    private:
        KeywordType type_;
    };

    class ScopeOpenToken final : public Token {
    public:
        static const TokenKind Kind = 1;
        ScopeOpenToken() : Token(Kind) {}

    #ifdef DEBUG_MODE
        void Dump(std::ostream &out) override { out << "ScopeOpen"; }
    #endif
    };

    class ScopeCloseToken final : public Token {
    public:
        static const TokenKind Kind = 2;
        ScopeCloseToken() : Token(Kind) {}

    #ifdef DEBUG_MODE
        void Dump(std::ostream &out) override { out << "ScopeClose"; }
    #endif
    };

    class BracketOpenToken final : public Token {
    public:
        static const TokenKind Kind = 3;
        BracketOpenToken() : Token(Kind) {}

    #ifdef DEBUG_MODE
        void Dump(std::ostream &out) override { out << "BracketOpen"; }
    #endif
    };

    class BracketCloseToken final : public Token {
    public:
        static const TokenKind Kind = 4;
        BracketCloseToken() : Token(Kind) {}

    #ifdef DEBUG_MODE
        void Dump(std::ostream &out) override { out << "BracketClose"; }
    #endif
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

#ifdef DEBUG_MODE
    void Dump(BinaryOperatorType type, std::ostream &out);
#endif

    class BinaryOperatorToken final : public Token {
    public:
        static const TokenKind Kind = 5;
        BinaryOperatorToken(BinaryOperatorType type) : Token(Kind), type_(type) {}

        BinaryOperatorType GetType() const { return type_; }
    #ifdef DEBUG_MODE
        void Dump(std::ostream &out) override { 
            std::cout << "BinaryOperator(";
            pcl::Dump(type_, out); 
            std::cout << ")";
        }
    #endif

        private:
        BinaryOperatorType type_;
    };

    class IntegerLiteral final : public Token {
    public:
        static const TokenKind Kind = 6;
        IntegerLiteral(char *begin, char *end) : Token(Kind) {}

        //TODO: Do I need such complicated interface?
        
        int GetValue() const {
            if (is_negative_)
                return -1 * absolute_value_;

            return absolute_value_;
        }

        unsigned GetAbsoluteValue() const { return absolute_value_; }
        bool IsNegative() const { return is_negative_; }

    private:
        unsigned absolute_value_;
        bool is_negative_;
    };

    class DelemiterToken final : public Token {
    public:
        static const TokenKind Kind = 7;  
        DelemiterToken() : Token(Kind) {}
    };

    class IdentifierToken final : public Token {
    public:
        static const TokenKind Kind = 8;
        IdentifierToken(const char *begin, const char *end) : Token(Kind), begin_(begin), end_(end) {}

        const char* Begin() const { return begin_; }
        const char* End() const { return end_; }

    private:
        const char *begin_;
        const char *end_;
    };
}; // namespace pcl
