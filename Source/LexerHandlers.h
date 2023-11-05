#pragma once

#include <utility>

#include "TypedTokens.h"

namespace pcl {
    std::pair<bool, pcl::KeywordType> HandleKeyword(const char*, const char*);
};
