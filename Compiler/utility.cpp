#include "utility.h"

const std::unordered_map<std::string, TokenType> Token::keywords = {
    {"var", TokenType::K_Variable},    {"let", TokenType::K_Let},
    {"func", TokenType::K_Function},   {"if", TokenType::K_If},
    {"else", TokenType::K_Else},       {"for", TokenType::K_For},
    {"while", TokenType::K_While},     {"return", TokenType::K_Return},
    {"break", TokenType::K_Break},     {"continue", TokenType::K_Continue},
    {"switch", TokenType::K_Switch},   {"case", TokenType::K_Case},
    {"default", TokenType::K_Default}, {"struct", TokenType::K_Struct},
    {"class", TokenType::K_Class},     {"enum", TokenType::K_Enum},
    {"import", TokenType::K_Import},   {"true", TokenType::K_True},
    {"false", TokenType::K_False},     {"none", TokenType::K_None},
    {"super", TokenType::K_Super},     {"self", TokenType::K_Self},
    {"String", TokenType::K_String},   {"Int", TokenType::K_Integer},
    {"Float", TokenType::K_Float},     {"Bool", TokenType::K_Boolean},
};
