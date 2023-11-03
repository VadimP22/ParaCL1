#include "Ut.h"

#include "Lexer.h"
#include "StaticSourceBuffer.h"

int main() {
    using namespace boost::ut;

    pcl::StaticSourceBuffer buffer{"sequence1; two theree four; ;five   six seven"};
    pcl::Lexer lexer{buffer};

    auto tokens = lexer.Lex();
    
    return 0;
}
