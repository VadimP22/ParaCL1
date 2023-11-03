#pragma once

#include "ISourceBuffer.h"

namespace pcl {
    class Lexer {
        //TODO
        public:
        Lexer(ISourceBuffer &source_buffer) : source_buffer_(source_buffer) {};

        private:
        ISourceBuffer &source_buffer_;
    };
};
