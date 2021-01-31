/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *  函数原型
 *      string& operator=(const char *s);
 *      string& operator=(const string &s);
 *      string& operator=(char c);  //单个字符赋值給字符串
 *
 *      string& assign(const char *s);
 *              assign(const char *s, int n);   s前n个字符赋值給当前字符串
 *              assign(const string &s);
 *              assign(int n, char c);  // n个c赋值給当前字符串
 */
#include <iostream>
#include <string>

using namespace std;


void test_string() {
    string s1;
    s1.assign(5, 'c');
    string s2("hello");
    string s3 = "c++";
    string s4(5, 'd');
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
}

/**
 * 字符串拼接
 *  +=
 *  append
 *
 */
void test_string_concat() {
    string s1 = "i ";
    s1 += "love ";

    s1.append("play game ");

    cout << s1 << endl;
}

/*
 * find
 * rfind
 * replace
 * insert
 * erase「擦除」
 * substr
 */
void test_string_func() {

    string s1 = "abccdsdf";
    cout << "s1.find ccd = " << s1.find("ccd") << endl;

    s1[2] = 'x';
    cout << "s1.at(2) = " << s1.at(2) << endl;

    s1.at(3) = 'x';
    cout << "s1 = " << s1 << endl;

}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    test_string();
    test_string_concat();
    test_string_func();

    return 0;
}

