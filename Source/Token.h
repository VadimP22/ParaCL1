#pragma once

#include <concepts>

#ifdef DEBUG_MODE
#include <iostream>
#endif

namespace pcl {   
    using TokenKind = int;

    class Token {
        //TODO: Add location in source file
    public:
        static const constexpr TokenKind Kind = -1;
        
        Token(TokenKind token_kind) : token_kind_(token_kind) {}
        virtual ~Token() = default;

        TokenKind GetKind() { return  token_kind_;} 

    #ifdef DEBUG_MODE
        virtual void Dump(std::ostream& out) { out << "Basic"; }
    #endif

        template <typename T> requires std::derived_from<T, Token>
        T& As() { return static_cast<T>(this); }

        template <typename T> requires std::derived_from<T, Token>
        bool Is() {
            if (token_kind_ == T::Kind)
                return true;

            return false;
        }

    private:
        TokenKind token_kind_;
    }; // class Token  
}; // namespcae pcl
