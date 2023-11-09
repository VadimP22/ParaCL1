#pragma once

#include <utility>

#include "TypedTokens.h"

namespace pcl {
    std::pair<bool, pcl::KeywordType> CheckKeyword(const char*, const char*);
};
