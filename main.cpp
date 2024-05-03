#include "gtest_lite.h"
#include "String.h"
#include <sstream>

int main() {
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

    GTEND(std::cerr);
    return 0;
}
