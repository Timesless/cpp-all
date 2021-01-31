/**
 * @author yangzl
 * @date 2021/1/31
 * @desc
 *
 *      1. 数组与指针
 *      2. 函数与指针
 *          不能返回局部变量的引用和指针
 */

#include <iostream>

using namespace std;


/*
 * 数组与指针
 */
void bubble_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
void test_array_pointer() {
    int *arr = new int[10];
    cout << "sizeof arr = " << sizeof(arr) << ", size of arr[0] = " << sizeof(arr[0]) << endl;
    for (int i = 0; i < 10; ++i) {
        arr[i] = 10 - i;
    }

    // 通过指针访问数组元素
    int *p = arr;
    for (int i = 0; i < 10; ++i) {
        cout << *(p++) << " ";
    }
    cout << endl;

    cout << "排序......." << endl;
    bubble_sort(arr, 10);
    p = arr;
    for (int i = 0; i < 10; ++i) {
        cout << *(p++) << " ";
    }
    cout << endl;

    delete[] arr;
}

/*
 * 函数与指针
 */
void my_swap(int &v1, int &v2) {
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}
void test_func_pointer() {
    int a = 10, b = 20;
    my_swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_array_pointer();
    test_func_pointer();

    return 0;
}
