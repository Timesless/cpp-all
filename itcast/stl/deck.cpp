/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *      双端队列deque「以数组实现」
 *      deque内部有一个中控器，维护每段缓冲区的内容，缓冲区中存放真实数据
 *      中控器维护每个缓冲区的地址，通过地址指向实际缓冲区「缓冲区是连续的，可以randomaccess」
 *
 *  构造函数基本同vector
 *
 *  operator=
 *  assign
 *  at
 *  []
 *  empty()
 *  size()
 *  capacity()
 *  resize(int)
 *  resize(int, E val);
 *
 *  erase(begin, end)
 *  erase(pos)
 *  push_back
 *  push_front
 *  pop_back
 *  pop_front
 *
 *  insert(pos, ele)
 *  insert(pos, n, ele)
 *  insert(pos, begin, end)
 *  clear()
 *
 *  sort()  对于支持随机访问迭代器的容器，都可以直接使用sort排序
 *
 */
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/**
 * 打印deque
 *
 * @tparam T 参数化类型
 * @param d deque
 */
template<class T> void printDeque(const deque<T> &d) {
    for (auto it : d) {
        cout << it << " ";
    }
    cout << endl;
}

void test_deque_construct() {
    deque<int> d;
    for (int i = 0; i < 10; ++i) {
        d.push_back(i);
    }
    printDeque(d);

    deque<int> d2(d.cbegin()+2, d.cend());
    printDeque(d2);

    // operator= 赋值运算符
    deque<int> d3 = d2;
    printDeque(d3);

    d3.assign(10, 100);
    printDeque(d3);
}

void test_deque_func() {
    deque<int> d(10, 1);
    d.insert(d.begin(), 2, 100);
    d.pop_back();
    d.pop_front();
    printDeque(d);

    deque<int> d2;
    d2.insert(d2.begin(), d.begin() + 2, d.begin() + 6);
    printDeque(d2);
}

/*
 * deque排序
 */
void test_deque_sort() {
    deque<int> d;
    d.push_back(10);
    d.push_back(8);
    d.push_back(20);
    d.push_back(6);
    d.push_back(14);
    d.push_back(3);
    printDeque(d);

    sort(d.begin(), d.end());
    printDeque(d);
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_deque_construct();
    test_deque_func();
    test_deque_sort();

    return 0;
}

