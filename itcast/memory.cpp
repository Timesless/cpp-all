
/**
 * @author yangzl
 * @date 2021/1/23
 * @desc
 */

#include <iostream>

using namespace std;

void test_new_array();

/**
 * C 内存区域
 *
 *  自底向上依次为：
 *      1. 代码段「存储代码」
 *      2. 全局段「全局区：存储全局变量、全局常量、静态变量、字符串常量」
 *      3. 堆「堆中数据由程序员控制其生命周期，malloc、calloc、realloc申请，free释放」
 *      4. 堆栈「形参、局部变量等，栈中变量由编译器控制其生命周期」
 *
 *  new 返回指针
 *  delete 释放堆区申请的空间
 *
 * @param argc
 * @param argv
 * @return
 */

int ga = 10, gb = 10;
const int cga = 10, cgb = 10;

int main(int argc, char *const argv[]) {

    int la = 10, lb = 10;
    const int cla = 10, clb = 10;

    static int sa = 10, sb = 10;

    // int *p1 = (int *) malloc(4), *p2 = (int *) malloc(4);
    // C++ 使用new，释放内存使用delelte
    int *p1 = new int(10), *p2 = new int(10);

    cout << "局部变量、局部常量地址： la = " << (&la) << "lb = " << &lb << " cla = " << &cla << " clb = " << &clb << endl;

    cout << "堆区变量地址为 p1 = " << &p1 << " p2 = " << &p2 << endl;

    cout << "静态变量、全局变量、全局常量 地址为：ga = " << &ga << " gb = " << &gb <<
         " cga = " << &cga << " cgb = " << &cgb << " sa = " << &sa << " sb = " << &sb << endl;

    // TODO ?
    delete p1, p2;

    cout << *p2 << endl;
    cout << *p2 << endl;

    test_new_array();

    return 0;
}


void test_new_array() {
    int *arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = 100 + i;
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}