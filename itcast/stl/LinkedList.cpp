/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *  双向循环链表
 *      节点「由数据域，指针域构成」
 *          data, prev, next
 *          back.next = front
 *          front.prev = back
 *  插入 / 删除 O(1)
 *  插入，删除不影响迭代器，因为是通过指针来连接的
 *  不支持[], at, 迭代器不能跳跃式访问
 *
 *      默认构造
 *      拷贝构造
 *      operator=
 *      区间构造「list<E> l(o.begin, o.end)」
 *      assign
 *      swap(other)
 *
 *      size
 *      empty
 *      resize
 *
 *      front
 *      back
 *
 *      push_back
 *      pop_back
 *      push_front
 *      pop_front
 *      insert(pos, ele)
 *      insert(pos, n, ele)
 *      insert(pos, begin, end)
 *      erase(begin, end)
 *      erase(pos)
 *      remove(ele) //删除所有与ele匹配的值
 *
 */
#include <iostream>
#include <list>

using namespace std;

template<class T> void printList(const list<T> &l) {
    for (auto it : l) {
        cout << it << " ";
    }
    cout << endl;
}

void test_list() {
    list<int> l;
    l.push_back(1);
    l.push_back(5);
    l.push_back(3);
    l.push_back(4);
    printList(l);

    list<int> l2(5, 1);
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
}

void test_list_api() {
    list<int> l(10, 1);
    l.push_back(10);
    l.push_front(10);
    printList(l);

    l.pop_front();
    l.pop_front();

    l.push_back(10);
    l.insert(l.end(), 2, 2);
    printList(l);

    l.erase(++l.begin());
    l.remove(2);
    printList(l);

    cout << "l.fornt = " << l.front() << ", l.back = " << l.back() << endl;

    l.clear();
}

/*template<class T> bool list_compare(const T t1, const T t2) {
    return t1 > t2;
}*/
bool list_compare(int t1, int t2) {
    return t1 > t2;
}
void test_list_sort() {

    list<int> l;
    l.push_back(1);
    l.push_back(6);
    l.push_back(3);
    l.push_back(9);
    l.push_back(4);
    printList(l);
    l.reverse();
    printList(l);

    l.sort(list_compare);
    printList(l);
}


class Person {
public:
    string name;
    int age;
    int height;

    Person(string name, int age, int height) {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

void printPersonList(list<Person> &l) {
    for (auto it : l) {
        cout << "name = " << it.name << ", age = " << it.age << ", height = " << it.height << endl;
    }
}
bool compare_person(const Person &p1, const Person &p2) {
    return p1.age == p2.age ? (p1.height > p2.height) : p1.age < p2.age;
}
void test_list_person() {
    list<Person> l;
    Person p1("曹操", 46, 167);
    Person p2("刘备", 45, 171);
    Person p3("赵子龙", 45, 178);
    Person p4("关羽", 44, 178);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);

    l.sort(compare_person);
    printPersonList(l);
}


/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_list();
    test_list_api();
    test_list_sort();
    test_list_person();

    return 0;
}

