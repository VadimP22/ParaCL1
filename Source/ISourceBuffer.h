#pragma once

namespace pcl {
    class ISourceBuffer {
        virtual const char* Begin() = 0;
        virtual const char* End() = 0;
    };
};
