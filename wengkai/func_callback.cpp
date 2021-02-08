/**
 * @author yangzl
 * @date 2021/1/31
 * @desc    韩顺平 -> 函数与指针，回调函数
 *
 *      1. 函数指针「指向函数的指针」
 *      2. 回调函数
 *          为什么可以这样呢？
 *          一个函数总是占用一段连续的内存区域，函数原型在表达式中可作为该函数所在内存区域的首地址
 *              同数组「数组首元素地址即数组地址」
 *          把函数的首地址赋值给一个指针变量，这个指针成为函数指针「可调用该函数」
 *
 *      returnType (*pointerName)(param list);
 *      返回类型    指针名称        参数列表
 */
#include <iostream>

using namespace std;

// max函数
int max(int a, int b) {
    return a > b ? a : b;
}

void test_func_pointer() {
    // max_star 是函数指针 指向max函数首地址
    int (*max_star)(int, int) = max;
    // (*max_star)(2, 3) 等价，取地址也是函数地址，同数组
    cout << max_star(2, 3) << endl;
    cout << (*max_star)(2, 3) << endl;
}

int get_random() {
    return rand() % 10;
}
void init_array_withrandom(int *arr, int len, int(*func)()) {
    for (int i = 0; i < len; ++i) {
        arr[i] = func();
    }
}
void test_func_callback() {
    int arr[10];
    // 回调函数
    int(*func)() = get_random;
    // init_array_withrandom(arr, 10, get_random);
    init_array_withrandom(arr, 10, func);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_func_pointer();
    cout << "=================" << endl;
    test_func_callback();

    return 0;
}
