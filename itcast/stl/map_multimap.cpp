/**
 * @author yangzl
 * @date 2021/2/8
 * @desc
 *
 *  map 构造
 *      1. map<int, int> m
 *      2. 拷贝构造 map<int, int> m2(m)
 *      3. 赋值构造 map<int, int> m3 = m2;
 *
 *      map元素中每个元素都是pair『对组』
 *      所有元素按key自动排序『底层以二叉树实现』
 *
 *      map不允许重复的key
 *      multimap允许重复的key
 */
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


void test_map() {
    auto p1 = make_pair<int, int>(1, 1);
    auto p2 = make_pair<int, int>(2, 4);

    map<int, int> m1;
    m1.insert(p2);
    m1.insert(p1);
    m1.insert(make_pair(4, 16));
    m1.insert(pair<int, int>(3, 9));
    /*
     * []方式 访问也会创建新的对组
     * 例如：
     *  cout << m1[6] << endl;
     *  此时 m1[6] = 0;
     */
    m1[5] = 25;
    m1[6];

    // lambda 遍历
    for_each(m1.begin(), m1.end(), [](pair<int, int> p){
       cout << "k = " << p.first << ", v = " << p.second << endl;
    });

}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_map();

    return 0;
}

