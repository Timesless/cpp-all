//
// Created by yangzl on 2021/1/16.
//

#include <iostream>

using namespace std;

typedef struct _u0 {
    // 前导位占3b，可表示8种情况
    unsigned int LEADING: 3;
    unsigned int FLAG1: 1;
    unsigned int FLAG2: 1;
    //
    unsigned int FLAG3: 1;
    // trait
    unsigned int TRAIT: 26;
} UO;

void printBin(unsigned int);

/**
 * 位段，相当于多个标志位掩码
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    UO uu = (UO){
        .LEADING = 2, .FLAG1 = 1, .FLAG2 = 1, .TRAIT = 0
    };
    printf("sizeof uu = %d\n", sizeof(uu));
    printBin(*(int*)&uu);
    return 0;
}

void printBin(unsigned int number) {
    unsigned int mask = 1u << 31;
    for(; mask; mask >>= 1) {
        printf("%d", number & mask ? 1 : 0);
    }
    printf("\n");
}