#include "TypedTokens.h"
#include "Ut.h"

#include "Lexer.h"
#include "StaticSourceBuffer.h"

int main() {
    using namespace boost::ut;
    
    pcl::StaticSourceBuffer source{"+-= ="};
    pcl::Lexer lexer{source};

    auto tokens = lexer.Lex();

    expect(tokens->GetTokensCount() == 4);

    for (auto it = tokens->Begin(), end = tokens->End(); it != end; ++it)
        expect((*it)->GetKind() == pcl::BinaryOperatorToken::Kind);
}
