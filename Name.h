#ifndef NAGYHAZI_2_NAME_H
#define NAGYHAZI_2_NAME_H

#include "String.h"
#include <cstring>

class Name {
public:
    /**
     * Keresztnév, vezetéknév, becenév
     */
    String first, last, nickname;

    // konstruktorok
    Name(const String& full, const String& nickname);
    Name(const String& first, const String& last, const String& nickname) : first(first), last(last), nickname(nickname) {}

    /**
     * Teljes név összeillesztése
     */
    String getFullName() const;
};

#endif //NAGYHAZI_2_NAME_H
