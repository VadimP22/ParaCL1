#pragma once

#include <string>

#include "ISourceBuffer.h"

namespace pcl {
    class StaticSourceBuffer : public ISourceBuffer {
        public:
        StaticSourceBuffer(const char* data) : data_(data) {}
        
        const char* Begin() override { return  data_.begin().base(); } 
        const char* End() override { return data_.end().base(); };

        private:
        std::string data_;
    };
};
