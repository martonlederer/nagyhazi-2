#include <sstream>
#include <unistd.h>

#include "String.h"
#include "PhoneNumber.h"
#include "Name.h"
#include "List.hpp"
#include "Contact.h"
#include "Loader.h"

// teszt környezet definiálása makróval
#ifndef TEST_ENV
#define TEST_ENV
#endif

#if defined(TEST_ENV) || defined(CPORTA)
#include "gtest_lite.h"
#endif

int main() {
// teszt üzemmód
#if defined(TEST_ENV) || defined(CPORTA)
    GTINIT(std::cin);

    //
    // class String test
    //

    // nulla paraméteres konstruktor
    TEST(String, String(void)) {
        String str;

        EXPECT_EQ((size_t) 0, str.len()) << "Len != 0" << std::endl;
        EXPECT_STREQ("", str.c_str()) << "C_str != \"\"" << std::endl;
    } END;

    // egyparaméteres (char) konstruktor
    TEST(String, String(char)) {
        String str = 'c';

        EXPECT_EQ((size_t) 1, str.len()) << "Len != 1" << std::endl;
        EXPECT_STREQ("c", str.c_str()) << "C_str != \"c\"" << std::endl;
    } END;

    // egyparaméteres (C string) konstruktor
    TEST(String, String(str)) {
        const char* base = "hello";
        String str = base;

        EXPECT_EQ(strlen(base), str.len()) << "Nem jó hossz" << std::endl;
        EXPECT_STREQ(base, str.c_str()) << "Nem jó érték" << std::endl;
    } END;

    // másoló konstruktor
    TEST(String, String(String&)) {
        const char* base = "hi";
        String str1 = base;
        String str2 = str1;

        EXPECT_EQ(str1.len(), str2.len()) << "Nem jó hossz" << std::endl;
        EXPECT_STREQ(str1.c_str(), str2.c_str()) << "Nem jó érték" << std::endl;
    } END;

    // == operátor
    TEST(String, operator==) {
        String str1 = "hello";
        String str2 = "word";
        String str3 = "hello";

        EXPECT_FALSE(str1 == str2) << "Nem egyenlőre egyenlő (str)" << std::endl;
        EXPECT_TRUE(str1 == str3) << "Egyenlőre nem egyenlő (str)" << std::endl;

        String str4 = 'c';
        char c1 = 'c';
        char c2 = 'd';

        EXPECT_TRUE(str4 == c1) << "Egyenlőre nem egyenlő (char)" << std::endl;
        EXPECT_FALSE(str4 == c2) << "Nem egyenlőre egyenlő (char)" << std::endl;
    } END;

    // értékadó operátor
    TEST(String, operator=) {
        const char* val = "egy str";

        String a = val, b = "masik", c = "harmadik";

        EXPECT_STRNE(a.c_str(), b.c_str());

        b = a;
        EXPECT_STREQ(val, b.c_str());

        c = b = a;
        EXPECT_NE(a.c_str(), b.c_str());
        EXPECT_STREQ(b.c_str(), val);
        EXPECT_STREQ(c.c_str(), val);
    } END;

    // összefűző operátor
    TEST(String, operator+) {
        String a = "Hello ", b = "World";
        String res = a + b;

        EXPECT_STREQ(res.c_str(), "Hello World");
    } END;

    std::stringstream ss;
    const char* val = "streamelt ertek";

    // << operátor
    TEST(String, operator<<) {
        String str = val;
        ss << str;

        EXPECT_STREQ(val, ss.str().c_str());
    } END;

    // >> operátor
    TEST(String, operator>>) {
        String str;
        ss >> str;

        EXPECT_STREQ(val, str.c_str());
    } END;

    //
    // class PhoneNumber test
    //

    TEST(PhoneNumber, all) {
        PhoneNumber num = PhoneNumber("+36308731649");

        EXPECT_EQ(36, num.getCountryCode());
        EXPECT_STREQ("+36 30 873 1649", num.toString().c_str());
        EXPECT_STREQ("🇭🇺 Magyarorszag", num.getCountry().c_str());
    } END;

    //
    // class Name test
    //

    TEST(Name, No Nickname) {
        Name name = Name("John", "Doe");

        EXPECT_STREQ("Doe John", name.getFullName().c_str());
    } END;

    TEST(Name, With Nickname) {
        Name name = Name("John", "Doe", "Laci");

        EXPECT_STREQ("Doe John (Laci)", name.getFullName().c_str());
    } END;

    TEST(Name, Parse Full) {
        Name name = Name("Lederer Marton");

        EXPECT_STREQ("Marton", name.first.c_str());
        EXPECT_STREQ("Lederer", name.last.c_str());
    } END;

    //
    // class List test
    //

    TEST(List, Empty) {
        List<int> list;

        EXPECT_EQ((size_t) 0u, list.size());

        list.push(3);
        list.push(1);

        EXPECT_EQ((size_t) 2u, list.size()) << "push() nem adta hozza az elemeket" << std::endl;
        EXPECT_EQ(3, list[0]);
        EXPECT_EQ(1, list[1]);

        list.remove(0);

        EXPECT_EQ((size_t) 1u, list.size()) << "remove() nem szedte ki az elemet" << std::endl;
        EXPECT_EQ(1, list[0]);
    } END;

    TEST(List, Not Empty) {
        int base[2] = { 1, 2 };
        List<int> list = List<int>(base, 2);

        EXPECT_EQ((size_t) 2u, list.size()) << "List(array, len) nem hozta letre a megfelelő hosszusagu listat" << std::endl;
        EXPECT_EQ(1, list[0]);
        EXPECT_EQ(2, list[1]);

        list.remove(1);

        EXPECT_EQ((size_t) 1u, list.size());
        EXPECT_EQ(1, list[0]);
    } END;

    TEST(List, iterator) {
        int base[2] = { 1, 2 };
        List<int> list = List<int>(base, 2);

        size_t i = 0;
        for (List<int>::iterator it = list.begin(); it != list.end(); ++it) {
            EXPECT_EQ(base[i++], *it) << "Az iterator nem jo erteket adott vissza" << std::endl;
        }
    } END;

    //
    // class Contact test
    //

    TEST(Contact, all) {
        Contact c = Contact(
            "Lederer Marton",
            PhoneNumber("+36708341340"),
            "Marci",
            "1034 Budapest, Prater utca 5.",
            PhoneNumber("+3618427433")
        );

        EXPECT_STREQ("Marton", c.getName().first.c_str());
        EXPECT_STREQ("Lederer Marton (Marci)", c.getName().getFullName().c_str());
        EXPECT_STREQ("+36 70 834 1340", c.getNumber().toString().c_str());
        EXPECT_STREQ("1034 Budapest, Prater utca 5.", c.getAddress().c_str());
        EXPECT_STREQ("+36 1 842 7433", c.getWorkNumber().toString().c_str());
    } END;

    //
    // class Loader test
    //

    TEST(Loader, contacts) {
        Loader manager = Loader();
        Contact* c1 = new Contact("Doe John", PhoneNumber("+36601387744"));

        manager.addContact(c1);
        manager.list();
        manager.countryStats();
        EXPECT_EQ((size_t) 1u, manager.getContacts().size());

        manager.removeContact(0);
        manager.list();
        manager.countryStats();
        EXPECT_EQ((size_t) 0u, manager.getContacts().size());
    } END;

    TEST(Loader, save) {
        Loader manager = Loader();
        Contact* c1 = new Contact("Doe John", PhoneNumber("+36601387744"));

        manager.addContact(c1);

        manager.save();
        EXPECT_NE(-1, access("contacts.txt", F_OK));
    } END;

    TEST(Loader, save) {
        Loader manager = Loader();
        manager.load();

        EXPECT_NE((size_t) 0u, manager.getContacts().size());
    } END;

    GTEND(std::cerr);
#else
    // normál üzemmód (console app)
#endif
    return 0;
}
