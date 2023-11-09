#include "Ut.h"

#include "StaticSourceBuffer.h"
#include "Lexer.h"

int main() {
    using namespace boost::ut;

    pcl::StaticSourceBuffer buffer{"(()  ) {  )}"};
    pcl::Lexer lexer{buffer};

    auto tokens = lexer.Lex();

    expect(tokens->GetTokensCount() == 7_i);
}
