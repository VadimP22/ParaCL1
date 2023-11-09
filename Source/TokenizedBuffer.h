#pragma once

#include <concepts>
#include <vector>

#include "Token.h"

namespace pcl {
    class TokenizedBuffer {
    public:
        Token** Begin() { return tokens_.begin().base(); };
        Token** End() { return tokens_.end().base(); };

        template<typename T> requires std::derived_from<T, Token>
        void Push(T *token) { tokens_.push_back(token); counter_ += 1; } 

        int GetTokensCount() { return counter_; }

    private:
        int counter_ = 0;
        std::vector<Token*> tokens_{};
    };
};
