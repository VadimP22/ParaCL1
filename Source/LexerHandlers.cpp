#include "LexerHandlers.h"

#include "LexerUtils.h"
#include "TypedTokens.h"

std::pair<bool, pcl::KeywordType> pcl::HandleKeyword(
        const char* begin,
        const char* end) {
    bool is_while = pcl::CompareToString(begin, end, "while");
    bool is_if = pcl::CompareToString(begin, end, "if");
    bool is_print = pcl::CompareToString(begin, end, "print");
    bool is_true = pcl::CompareToString(begin, end, "true");
    bool is_false = pcl::CompareToString(begin, end, "false");

    if (is_while)
        return std::pair(true, pcl::KeywordType::While);

    if (is_if)
        return std::pair(true, pcl::KeywordType::If);

    if (is_print)
        return std::pair(true, pcl::KeywordType::Print);

    if (is_true)
        return std::pair(true, pcl::KeywordType::True);

    if (is_false)
        return std::pair(true, pcl::KeywordType::False);

    return std::pair(false, pcl::KeywordType::If);
}
