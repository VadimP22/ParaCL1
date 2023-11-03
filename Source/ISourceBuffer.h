#pragma once

namespace pcl {
    class ISourceBuffer {
        public:
        virtual const char* Begin() = 0;
        virtual const char* End() = 0;
    };
};
