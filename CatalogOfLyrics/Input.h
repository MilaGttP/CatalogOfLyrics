
#pragma once

#include <iostream>

using std::istream;

char* InputString(istream& stream);

bool InputAndPasrseString(istream& stream, char*& pStr);
bool InputAndPasrseValue(istream& stream, const char* format, void* ptr);

bool InputAndParseMultilineText(istream& stream, char*& pStr);
void InputMultilineText(istream& stream, char*& pStr);