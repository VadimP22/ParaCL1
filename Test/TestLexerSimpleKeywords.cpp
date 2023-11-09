#include "Ut.h"

#include "Lexer.h"
#include "StaticSourceBuffer.h"

int main() {
    using namespace boost::ut;

    pcl::StaticSourceBuffer buffer{"if ~ while true ~ ~false  print"};
    pcl::Lexer lexer{buffer};

    auto tokens = lexer.Lex();
    
    expect(tokens->GetTokensCount() == 5_i);
}
