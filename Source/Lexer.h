#pragma once

#include "ISourceBuffer.h"
#include "TokenizedBuffer.h"

namespace pcl {
    class Lexer {
    public:
        Lexer(ISourceBuffer &source_buffer) : source_buffer_(source_buffer) {};

        TokenizedBuffer* Lex();

    private:
        ISourceBuffer &source_buffer_;
    };
};
