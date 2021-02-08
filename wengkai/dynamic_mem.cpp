/**
 * @author yangzl
 * @date 2021/1/31
 * @desc
 *      韩顺平 -> c动态内存分配
 *      内存4区
 *          1. 代码段
 *          2. 全局段 / 静态段
 *          3. 堆
 *              void* malloc(usigned int)「memeory allocation」
 *              void* calloc(usigned int, unsigend int)
 *              void* realloc(void *, usigned int)
 *              void free(void*)
 *          4. 堆栈
 *      void*：表示纯地址
 *
 *      只能归还申请内存的首地址，p++后free会抛出异常
 */

#include <iostream>
#include <cstdlib>
using namespace std;

void test_dynamic_memeroy_allocation() {
    int a = 1;
    // p3为纯地址
    void *p3 = &a;

    int *arr = (int*) malloc(sizeof(int) * 10);
    arr[1] = 10;
    cout << "arr[1] = " << arr[1] << endl;

    free(arr);
}

using namespace std;

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_dynamic_memeroy_allocation();
    return 0;
}

