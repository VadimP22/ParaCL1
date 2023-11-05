#pragma once

#include "TypedTokens.h"

namespace pcl {
    void PrintSequence(const char* begin, const char* end);

    bool IsSymbol(char sym);
    bool IsNumber(char sym);

    bool CompareToString(const char* begin, const char* end, const char* str);
};
