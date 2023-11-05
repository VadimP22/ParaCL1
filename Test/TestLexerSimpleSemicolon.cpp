#include "Ut.h"

#include "Lexer.h"
#include "StaticSourceBuffer.h"

int main() {
    using namespace boost::ut;

    pcl::StaticSourceBuffer buffer{"while;;while if; while ;while true false"};
    pcl::Lexer lexer{buffer};

    auto tokens = lexer.Lex();

    expect(tokens->GetTokensCount() == 11_i);
}
