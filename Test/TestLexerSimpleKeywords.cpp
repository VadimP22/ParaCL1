#include "Ut.h"

#include "Lexer.h"
#include "StaticSourceBuffer.h"

int main() {
    using namespace boost::ut;

    pcl::StaticSourceBuffer buffer{"if sequence1~ while two true theree four~ ~five false  print six seven"};
    pcl::Lexer lexer{buffer};

    auto tokens = lexer.Lex();
    
    expect(tokens->GetTokensCount() == 5_i);
}
