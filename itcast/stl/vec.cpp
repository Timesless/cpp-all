/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *  无参构造
 *  有参构造
 *  拷贝构造
 *  赋值
 *
 *  assign
 *
 *  insert
 *  erase
 *
 *
 */
#include <iostream>
#include <vector>

using namespace std;

template<class T> void printVector(const vector<T> &v) {
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}

class Person {
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};


/**
 * v.begin() 返回的是指针
 */
void test_vector_person() {
    vector<Person> v;
    Person p1("java", 15);
    Person p2("python", 20);
    Person p3("c", 43);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Person>::const_iterator it = v.cbegin(); it != v.cend(); ++it) {
        // (*it).name (*it).age
        cout << "name = " << it->name << ", age = " << it->age << endl;
    }
}

/**
 * v.cbegin() 返回指针
 * it = v.cbegin()
 * (*it) 是 Person*
 * name = (**it).name
 * age = (*it)->age;
 */
void test_vector_star() {
    vector<Person*> v;

    Person p1("java", 15);
    Person p2("python", 20);

    v.push_back(&p1);
    v.push_back(&p2);

    for (auto it = v.cbegin(); it != v.cend(); it++) {
        cout << "name = " << (**it).name << ", age = " << (*it)->age << endl;
    }

    // enhance for
    for (auto it : v) {
        cout << "name = " << it->name << ", age = " << it->age << endl;
    }
}

void test_vector_construct() {
    vector<int>v(10, 1);
    vector<int>v2(v.begin(), v.begin() + 6);
    vector<int>v3(v2);

}

/*
 * empty()
 * capactity()
 * size()
 * resize()
 * resize(int, E val)   // 若容量增长则以val填充
 *
 */
void test_vector_func() {
    vector<int> v(10, 1);
    printVector(v);
    v.resize(15, 0);
    printVector(v);

    v.erase(v.begin(), v.begin() + 4);
    v.push_back(100);
    printVector(v);
    v.pop_back();
    v.insert(v.begin() + 2, 2, 1000);
    printVector(v);

    cout << "first e = " << v.front() << endl;
    cout << "last e = " << v.back() << endl;

    v.erase(v.begin(), v.end());
    v.clear();
}

/*
 * 使用swap收缩空间
 */
void test_vector_swap() {
    vector<int> v(1000, 10);
    cout << "v size = " << v.size() << ", v capacity = " << v.capacity() << endl;

    v.resize(3);
    cout << "v size = " << v.size() << ", v capacity = " << v.capacity() << endl;

    cout << "以size = 3, capacity = 1000 拷贝构造 capacity = " << vector<int>(v).capacity() << endl;
    /*
     * 可以实现收缩vector空间
     * vector<int>(v) 以 v构建一个匿名vector，此时size = 3， capacity = 3
     */
    vector<int>(v).swap(v);

    vector<int> v2(1000, 1);
    v2.resize(10);
    v2.shrink_to_fit();
    cout << "1000 shrink_to_fit v2 size = " << v2.size() << ", v2.capacity = " << v2.capacity() << endl;
}

/*
 * 测试vector增长
 * 18次增长到131072
 */
void test_vector_increase() {
    int count = 0;
    int* head = nullptr;

    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        if (head != &v[0]) {
            head = &v[0];
            ++ count;
        }
        v.push_back(i);
    }
    cout << "v.capacity = " << v.capacity() << endl;
    cout << "vector increase to 100000 takes " << count << " times loop" << endl;


    // 利用reserve预留空间
    v.reserve(100000);
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    test_vector_person();
    test_vector_star();
    test_vector_func();
    test_vector_swap();
    test_vector_increase();

    return 0;
}

