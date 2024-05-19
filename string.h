//
// Created by Marton Lederer on 28/03/2024.
//

#ifndef NAGYHAZI_2_STRING_H
#define NAGYHAZI_2_STRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>
#include "memtrace.h"

/**
 * Dinamikus string osztály
 */
class String {
    size_t size; // string mérete, '\0' nélkül
    char* data; // a string C stringként
    static bool sep;
public:
    /**
     * Paraméter nélküli konstruktor
     */
    String() : size(0), data(nullptr) {}

    /**
     * String készítése C stringből
     */
    String(const char* str) : size(strlen(str)) {
        data = new char[size + 1];
        strcpy(data, str);
    }

    /**
     * String készítése char-ból
     */
    String(const char c) : size(1) {
        data = new char[size + 1];
        data[0] = c;
        data[1] = '\0';
    }

    /**
     * Másoló konstruktor
     */
    String(const String& rhs);

    // destruktor
    ~String() {
        delete[] data;
    }

    /**
     * C string/char array készítése String példányból
     */
    const char* c_str() const;

    /**
     * Méret visszaadása (lezáró nulla nélkül)
     */
    size_t len() const { return size; }

    // operátorok
    bool operator==(const String& rhs) const;
    bool operator==(const char* rhs) const;
    bool operator!=(const char* rhs) const { return !operator==(rhs); }
    String& operator=(const String& rhs);
    String& operator=(const char* rhs);
    String operator+(const String& rhs) const;
    char& operator[](size_t idx) const;

    /**
     * Substring készítése adott indextől, adott hosszúságban
     */
    String sub(size_t idx, size_t len) const;

    /**
     * Karakter beállítása, ahol olvasáskor véget ér a string
     */
    static void setSep(bool val);

    /**
     * Szétválasztó karakter visszaadása
     */
    static bool getSep();
};

// globális operátorok
bool operator==(const char* lhs, const String& rhs);
std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);

#endif //NAGYHAZI_2_STRING_H
