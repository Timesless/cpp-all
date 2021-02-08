/**
 * @author yangzl
 * @date 2021/1/31
 * @desc
 *
 *      1. 结构体
 *      2. 联合体 / 共用体
 *
 *      c: char *name = "hello"
 *      c++11: char *name = (char*)"hello" / const char *name = "hello";
 */
#include <iostream>

using namespace std;

/*
 * 结构体
 * 字段默认public
 */
typedef struct cat {
    const char *name;
    int age;
    const char *color;
} Cat;

/*
 * 联合体
 */
typedef union dog {

} Dog;


void test_struct() {
    Cat cat{
        "tom",
        2,
        "rainbow"
    };
    cout << "cat name = " << cat.name << ", cat.age = " << cat.age << ", cat.color = " << cat.color << endl;

    Cat cat2 = Cat{
        "jerry",
        1,
        "pink"
    };
    cout << "cat2 name = " << cat2.name << endl;

    const char *name = "jerry";
    char name2[6] = "jerry";
    cout << "name = " << name << ", name2 = " << name2 << endl;
}


void test_union() {

}
/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_struct();
    test_union();

    return 0;
}

