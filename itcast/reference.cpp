
/**
 * @author yangzl
 * @date 2021/1/23
 * @desc
 */

#include <iostream>

using namespace std;

void mySwap(int&, int&);
int& test_left_val();
// 声明和实现只能一个有默认参数
int func(int, int = 1, int = 1);

/**
 * 引用是一个指针常量，也可以理解为变量的别名
 *  const int *p：常量指针
 *  int* const p： 指针常量
 *
 * 引用可作为左值被赋值「我们使用时把引用就当作变量使用，编译器会自动解引用它」
 *
 *  int a = 10;
 *  int &ref = a;
 *  ref = 100;
 *
 *  常量引用
 *  const int &ref = 10 ==> int tmp = 10, const int &ref = tmp
 *  引用已经是底层常量指针了，再加上const修饰，则同时具备顶层常量指针和底层常量指针
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    int a = 10, b = 20;
    mySwap(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    int &c = test_left_val();
    cout << "c = " << c << endl;
    // 作为左值被赋值
    test_left_val() = 1000;
    cout << "c = " << c << endl;

    int rs = func(5);
    cout << "函数默认参数 rs = " << rs << endl;

    return 0;
}

void mySwap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * 引用可作为左值被赋值
 */
int& test_left_val() {
    static int c = 10;
    int &b = c;
    return b;
}

/*
 * 函数可以有默认参数
 */
int func(int a, int b, int c) {
    return a + b + c;
}