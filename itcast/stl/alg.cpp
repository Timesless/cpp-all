/**
 * @author yangzl
 * @date 2021/1/31
 * @desc
 *
 *      常用算法
 *          「func：仿函数 / 函数」
 *          for_each(begin, end, func)
 *          transform(src.begin, src.end, dest.begin, func)
 *
 *          find
 *          find_if
 *          adjacent_find   // 查找相邻重复元素
 *          binary_search
 *
 *          count
 *          count_if
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T> void printVector(vector<T> &v) {
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}


/*
 * 1. 提供函数
 * 2. 提供仿函数
 */
template<class T> void print_v(T t) {
    cout << t << " ";
}
void test_alg_foreach() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for_each(v.begin(), v.end(), print_v<int>);
    cout << endl;
}

/*
 * 1. 提供函数
 * 2. 提供仿函数
 */
template<class T> T cube(T t) {
    return t * t * t;
}
template<class T> class Square {
public:
    T operator()(T t) {
        return t * t;
    }
};
void test_alg_transform() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2;
    v2.resize(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), cube<int>);
    printVector(v2);

    transform(v1.begin(), v1.end(), v2.begin(), Square<int>());
    printVector(v2);
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_alg_foreach();
    test_alg_transform();

    return 0;
}

