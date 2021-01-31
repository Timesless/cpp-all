/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *      set 二叉树实现，不可以包含重复元素
 *          对于自定义数据类型，set必须指定排序规则才能insert
 *      multiset    可以包含重复元素
 *
 *  无参构造
 *  拷贝构造
 *  operator=
 *
 *  empty
 *  size
 *  swap
 *
 *  insert
 *  clear
 *  erase(pos)
 *  erase(begin, end)
 *  erase(ele)
 *
 *  find(key)   // 返回迭代器
 *  count(key)
 */
#include <iostream>
#include <set>

using namespace std;

template<class T> void printSet(const set<T> &s) {
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}

template<class T> void printMultiset(const multiset<T> &ms) {
    for (auto it : ms) {
        cout << it << " ";
    }
    cout << endl;
}


// 仿函数改变set排序规则
class SetCompare {
public:
    bool operator() (int a, int b) {
        return a > b;
    }
};
void test_set() {
    set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(4);
    s.insert(6);
    s.insert(2);
    printSet(s);

    set<int>::iterator it = s.find(5);
    if (it != s.end()) {
        cout << "查找到 key = " << *it << endl;
    }
    int cnt = s.count(2);
    cout << "s.count 2 = " << cnt << endl;

    // auto ret = s.insert(2);
    pair<set<int>::iterator, bool> ret = s.insert(2);
    if (ret.second) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败" << endl;
    }

    // 改变排序规则

    set<int, SetCompare> s3;
    s3.insert(1);
    s3.insert(2);
    s3.insert(4);
    for (set<int, SetCompare>::const_iterator it = s3.cbegin(); it != s3.cend(); it ++) {
        cout << *it << " ";
    };
    cout << endl;

}

void test_multiset() {
    cout << "====================" << endl;
    multiset<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(4);
    s.insert(6);
    s.insert(2);
    s.insert(2);
    printMultiset(s);

    s.erase(5);
    s.insert(s.begin(), 9);
    s.insert({1, 5, 9});

    printMultiset(s);
}


void test_pair() {
    cout << "===================" << endl;
    pair<int, int> p(1, 1);
    pair<int, int> p2 = make_pair(2, 4);

    cout << "p.first = " << p.first << ", p.second = " << p.second << endl;
    cout << "p2.first = " << p2.first << ", p2.second = " << p2.second << endl;
}


/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_set();
    test_multiset();
    test_pair();

    return 0;
}

