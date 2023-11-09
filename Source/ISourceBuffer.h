#pragma once

namespace pcl {
    class ISourceBuffer {
    public:
        virtual ~ISourceBuffer() = default;

        virtual const char* Begin() = 0;
        virtual const char* End() = 0;
    };
};
