#pragma once

#include <utility>

#include "TypedTokens.h"

namespace pcl {
    std::pair<bool, pcl::KeywordType> CheckKeyword(const char *begin, const char *end);
    std::pair<bool, pcl::BinaryOperatorType> CheckBinaryOperation(const char *it);
};
