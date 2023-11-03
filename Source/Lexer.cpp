#include "Lexer.h"

#include <utility>

//TODO: For debugging purposes. Remove when get working
#include <iostream>

#include "ISourceBuffer.h"
#include "TokenizedBuffer.h"
#include "TypedTokens.h"

void PrintSequence(const char* begin, const char* end) {   
    std::cout << "SEQUENCE: ";

    for (auto it = begin; it != end; ++it)
        std::cout << *it;

    std::cout << std::endl;
}

bool IsSymbol(char sym) {
    if (sym >= 65 && sym <= 90)
        return true;

    if (sym >= 97 && sym <= 122)
        return true;

    return false;
}

bool IsNumber(char sym) {
    if (sym >= 48 && sym <= 57)
        return true;

    return false;
}

std::pair<bool, pcl::KeywordType> HandleKeyword() {
    //TODO
    return std::pair(false, pcl::KeywordType::If);
}

void HandleSequence(pcl::TokenizedBuffer* buffer, const char* begin, const char* end) {
    PrintSequence(begin, end);
}

pcl::TokenizedBuffer* pcl::Lexer::Lex() {
    auto buffer = new TokenizedBuffer{};

    auto last_non_valiable = source_buffer_.Begin();
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

            // if (*it == ';')
                // PrintSequence(it, it);
        }

    }
    HandleSequence(buffer, sequence_begin + 1, source_buffer_.End());

    return buffer;
}
