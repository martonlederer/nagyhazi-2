#ifndef NAGYHAZI_2_NAME_H
#define NAGYHAZI_2_NAME_H

#include "String.h"

class Name {
public:
    /**
     * Keresztnév, vezetéknév, becenév
     */
    String first, last, nickname;

    // konstruktorok
    Name(String first, String last);
    Name(String first, String last, String nickname);

    /**
     * Teljes név összeillesztése
     */
    String getFullName() const;
};

#endif //NAGYHAZI_2_NAME_H
