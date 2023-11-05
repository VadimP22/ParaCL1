#pragma once

#include <concepts>

namespace pcl {   
    using TokenKind = int;

    class Token {
        //TODO: Add location in source file
        public:
        static const TokenKind Kind = -1;
        
        Token(TokenKind token_kind) : token_kind_(token_kind) {}

        TokenKind GetKind() { return  token_kind_;} 

        template <typename T> requires std::derived_from<T, Token>
        T& As() { return static_cast<T>(this); }

        private:
        TokenKind token_kind_;
    }; // class Token  
}; // namespcae pcl
