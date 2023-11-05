#include "Lexer.h"

#include <utility>

#include "ISourceBuffer.h"
#include "LexerHandlers.h"
#include "TokenizedBuffer.h"
#include "LexerUtils.h"
#include "TypedTokens.h"

void HandleSingleSymbol(pcl::TokenizedBuffer *buffer, const char* it) {
    if (*it == ';')
        buffer->Push(new pcl::DelemiterToken);
    if (*it == '(')
        buffer->Push(new pcl::BracketOpenToken);
    if (*it == ')')
        buffer->Push(new pcl::BracketCloseToken);
    if (*it == '{')
        buffer->Push(new pcl::ScopeOpenToken);
    if (*it == '}')
        buffer->Push(new pcl::ScopeCloseToken);
}

void HandleSequence(pcl::TokenizedBuffer* buffer, const char* begin, const char* end) {
    auto keyword = pcl::HandleKeyword(begin, end);
    if (keyword.first) {
        buffer->Push(new pcl::KeywordToken(keyword.second));
        return;
    }

}

pcl::TokenizedBuffer* pcl::Lexer::Lex() {
    auto buffer = new TokenizedBuffer{};

    const char * sequence_begin = source_buffer_.Begin() - 1;
    const char * sequence_end = source_buffer_.Begin();
    int sequence_length = 0;
        
    for (auto it = source_buffer_.Begin(), end =source_buffer_.End();
            it != end; ++it) {     
        if (IsSymbol(*it)) {
            sequence_length += 1;
            sequence_end = it;
        } else {
            if (sequence_length > 0) {
                HandleSequence(buffer, sequence_begin + 1, sequence_end + 1);
            }

            sequence_begin = it;
            sequence_end = it;
            sequence_length = 0;

            HandleSingleSymbol(buffer, it);
           
        }

    }
    HandleSequence(buffer, sequence_begin + 1, source_buffer_.End());

    return buffer;
}
