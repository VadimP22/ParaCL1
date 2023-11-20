#pragma once

#include "TokenizedBuffer.h"

namespace pcl {
    class Parser final {
    public:
        Parser(TokenizedBuffer *tokens) : tokens_(tokens) {}

    private:
        TokenizedBuffer *tokens_;
    };  
};
