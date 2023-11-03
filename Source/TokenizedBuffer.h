#pragma once

#include <concepts>
#include <vector>

#include "Token.h"

namespace pcl {
    class TokenizedBuffer {
        public:
        Token* Begin();
        Token* End();

        template<typename T> requires std::derived_from<T, Token>
        void Push(T *token) { tokens_.push_back(token); } 

        private:
        std::vector<Token*> tokens_{};
    };
};
