//
// Created by Marton Lederer on 28/03/2024.
//

#include "string.h"

// másoló konstruktor
String::String(const String& rhs) {
    size = rhs.len();
    data = new char[size + 1];
    strcpy(data, rhs.data);
}

// C string visszaadása
const char* String::c_str() const {
    if (data == nullptr) return "";
    return data;
}

// operátorok

bool String::operator==(const String& rhs) const {
    if (size != rhs.len()) return false;

    for (size_t i = 0; i < size; i++)
        if (data[i] != rhs.c_str()[i]) return false;

    return true;
}

bool String::operator==(const char* rhs) const {
    const String tmp = String(rhs);
    return *this == tmp;
}

String& String::operator=(const String& rhs) {
    if (&rhs == this) return *this;
    return operator=(rhs.c_str());
}

String& String::operator=(const char* rhs) {
    delete[] data;
    size = strlen(rhs);
    data = new char[size + 1];
    strcpy(data, rhs);

    return *this;
}

bool operator==(const char* lhs, const String& rhs) {
    return rhs == lhs;
}
