//
// Created by Marton Lederer on 28/03/2024.
//

#include "String.h"

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

    if (size > 0) {
        strcpy(tmp.data, data);
        strcat(tmp.data, rhs.data);
    } else strcpy(tmp.data, rhs.data);

    return tmp;
}

char& String::operator[](size_t idx) const {
    if (idx > size) {
        throw std::out_of_range ("Túl nagy index");
    }
    return data[idx];
}

bool operator==(const char* lhs, const String& rhs) {
    return rhs == lhs;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.c_str();
}

String String::sub(size_t idx, size_t len) const {
    String tmp = "";

    for (size_t i = 0; i < len; i++)
        tmp = tmp + operator[](i + idx);

    return tmp;
}

std::istream& operator>>(std::istream& is, String& str) {
    char ch;
    is >> std::noskipws;

    while (is >> ch && !isspace(ch))
        str = str + ch;

    is >> std::skipws;
    is.putback(ch);

    return is;
}
