/**
 * @author yangzl
 * @date 2021/1/31
 * @desc
 *      内置函数对象「仿函数」
 *      #include <functional>
 *          1. 算数仿函数
 *              template<class T> T plus<T>
 *                                  minus<T>
 *                                  multiplies<T>
 *                                  divides<T>
 *                                  modulus<T>
 *                                  negate<T>   // 取反
 *          2. 关系仿函数
 *              template<class T> bool greater<T>
 *                                     greater_equal<T>
 *                                     less<T>
 *                                     less_equal<T>
 *                                     equal<T>
 *
 *          3. 逻辑仿函数
 *              logic_or
 *              logic_add
 *              logic_not
 *
 */
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

// 自定义仿函数
class MyFunc {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

template<class T> void printVector(vector<T> &v) {
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}


void test_func_athmetic() {
    negate<> n;
    cout << n(50) << endl;

    plus<> p;
    cout << "10 + 20 = " << p(10, 20) << endl;
}

void test_func_relation() {
    // 二元谓词
    greater<> g;
    cout << "5 > 10 ? " << g(5, 10) << endl;

    vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    // 匿名greater仿函数对象
    // sort(v.begin(), v.end(), greater<>());
    sort(v.begin(), v.end(), MyFunc());
    printVector(v);
}

void test_func_logic() {
    logical_not<> n;
    cout << "!1 = " << n(1) << endl;
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_func_athmetic();
    test_func_relation();
    test_func_logic();

    return 0;
}


