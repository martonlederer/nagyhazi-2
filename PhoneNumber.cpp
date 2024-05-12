//
// Created by Marton Lederer on 06/05/2024.
//
#include "PhoneNumber.h"

Country countries[] = {
    {"1", "🇺🇸 Egyesult Allamok"},
    {"44", "🇬🇧 Egyesult Kiralysag"},
    {"91", "🇮🇳 India"},
    {"86", "🇨🇳 Kina"},
    {"81", "🇯🇵 Japan"},
    {"49", "🇩🇪 Nemetorszag"},
    {"33", "🇫🇷 Franciaorszag"},
    {"7", "🇷🇺 Oroszorszag"},
    {"55", "🇧🇷 Brazilia"},
    {"39", "🇮🇹 Olaszorszag"},
    {"82", "🇰🇷 Del-Korea"},
    {"34", "🇪🇸 Spanyolorszag"},
    {"61", "🇦🇺 Ausztralia"},
    {"52", "🇲🇽 Mexiko"},
    {"49", "🇨🇦 Kanada"},
    {"971", "🇦🇪 Egyesult Arab Emirsegek"},
    {"234", "🇳🇬 Nigeria"},
    {"27", "🇿🇦 Del-Afrika"},
    {"65", "🇸🇬 Szingapur"},
    {"43", "🇦🇹 Ausztria"},
    {"32", "🇧🇪 Belgium"},
    {"359", "🇧🇬 Bulgaria"},
    {"385", "🇭🇷 Horvatorszag"},
    {"357", "🇨🇾 Ciprus"},
    {"420", "🇨🇿 Cseh Koztarsasag"},
    {"45", "🇩🇰 Dania"},
    {"372", "🇪🇪 Esztorszag"},
    {"358", "🇫🇮 Finnorszag"},
    {"33", "🇫🇷 Franciaorszag"},
    {"49", "🇩🇪 Nemetorszag"},
    {"30", "🇬🇷 Gorogorszag"},
    {"36", "🇭🇺 Magyarorszag"},
    {"353", "🇮🇪 Irorszag"},
    {"370", "🇱🇹 Litvania"},
    {"352", "🇱🇺 Luxemburg"},
    {"356", "🇲🇹 Malta"},
    {"31", "🇳🇱 Hollandia"},
    {"48", "🇵🇱 Lengyelorszag"},
    {"351", "🇵🇹 Portugalia"},
    {"40", "🇷🇴 Romania"},
    {"421", "🇸🇰 Szlovakia"},
    {"386", "🇸🇮 Szlovenia"},
    {"46", "🇸🇪 Svedorszag"},
    {"41", "🇨🇭 Svajc"},
    {"90", "🇹🇷 Torokorszag"},
    {"380", "🇺🇦 Ukrajna"}
};

PhoneNumber::PhoneNumber(const String& raw) {
    for (size_t i = 0; i < 46; i++) {
        size_t dialCodeLen = strlen(countries[i].dialCode);
        for (size_t j = 0; j < dialCodeLen; j++) {
            if (raw[j + 1] != countries[i].dialCode[j]) break;
            if (j == dialCodeLen - 1) {
                country = countries[i].dialCode;
                num = String(raw.c_str() + i + 2);
                return;
            }
        }
    }

    if (country.len() == 0) num = raw;
}

String PhoneNumber::toString() const {
    String full = '+';
    full = full + country + " " + num;
    return full;
}

String PhoneNumber::getCountry() const {
    for (auto & c : countries)
        if (strcmp(c.dialCode, country.c_str()) == 0)
            return { c.name };

    return { "" };
}
