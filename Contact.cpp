//
// Created by Marton Lederer on 12/05/2024.
//

#include "Contact.h"

std::ostream& operator<<(std::ostream& os, const Contact& c) {
    return os << c.getName().getFullName() << '\n'
        << " - Privat: " << c.getNumber().toString() << '\n'
        << " - Munkahelyi: " << c.getWorkNumber().toString() << '\n'
        << " - Cim: " << c.getAddress() << std::endl;
}
