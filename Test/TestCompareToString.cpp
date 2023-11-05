#include "Ut.h"

#include <string>

#include "LexerUtils.h"

int main() {
    using namespace boost::ut;    
    std::string case1{"String1"};
    
    bool result1 = pcl::CompareToString(
        case1.begin().base(),
        case1.end().base(),
        "String1"
    );
    expect(result1 == true);

    bool result2 = pcl::CompareToString(
        case1.begin().base(),
        case1.end().base(),
        "Str1ng1"
    );
    expect(result2 == false);

    bool result3 = pcl::CompareToString(
        case1.begin().base(),
        case1.end().base(),
        "Stri"
    );
    expect(result3 == false);

    bool result4 = pcl::CompareToString(
        case1.begin().base(),
        case1.end().base(),
        "String1fe"
    );
    expect(result4 == false);
}
