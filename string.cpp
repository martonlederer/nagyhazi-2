//
// Created by Marton Lederer on 28/03/2024.
//

#include "string.h"
#include <cstring>

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

    if (size > 0) {
        data = new char[size + 1];
        strcpy(data, rhs);
    } else data = nullptr;

    return *this;
}

String String::operator+(const String& rhs) const {
    String tmp;
    delete[] tmp.data;

    tmp.size = size + rhs.size + 1;
    tmp.data = new char[tmp.size];

    strcpy(tmp.data, data);
    strcat(tmp.data, rhs.data);

    return tmp;
}

bool operator==(const char* lhs, const String& rhs) {
    return rhs == lhs;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.c_str();
}

std::istream& operator>>(std::istream& is, String& str) {
    str = "";
    char c;

    while (is >> c) {
        if (isspace(c)) {
            is.putback(c);
            break;
        }
        str = str + String(c);
    }

    return is;
}
