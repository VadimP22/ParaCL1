#include "TypedTokens.h"

#ifdef DEBUG_MODE
void pcl::Dump(BinaryOperatorType type, std::ostream &out) {
    switch (type) {
        case BinaryOperatorType::Assignment:
            out << "Assignment";
            break;
        case BinaryOperatorType::Addition:
            out << "Addition";
            break;
        case BinaryOperatorType::Subtraction:
            out << "Subtraction";
            break;
        case BinaryOperatorType::Multiplication:
            out << "Multiplication";
            break; 
        case BinaryOperatorType::Division:
            out << "Division";
            break;
        case BinaryOperatorType::Equal:
            out << "Equal";
            break;
        case BinaryOperatorType::NotEqual:
            out << "NotEqual";
            break;
        case BinaryOperatorType::Greater:
            out << "Greater";
            break;
        case BinaryOperatorType::GreaterOrEqual:
            out << "GreaterOrEqual";
            break;
        case BinaryOperatorType::Less:
            out << "Less";
            break;
        case BinaryOperatorType::LessOrEqual:
            out << "LessOrEqual";
            break;
        default:
            out << "BinaryOperatorTypeUndefined";
            break;
        //TODO
    }
}
#endif
