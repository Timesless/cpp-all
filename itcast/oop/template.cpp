/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *  模板编程
 *      1. 函数模板
 *      2. 类模板
 *          2.1 类模板作为函数参数
 *          2.2 类模板与继承
 */
#include <iostream>

using namespace std;

/**
 * 交换值
 * template<typename T> void my_swap
 *     自动类型推导必须符合参数列表
 *         char c = 'a', int b = 10;
 *         // 错误 my_swap(b, c);
 *         // 正确 my_swap<int>(b, c);
 *
 * @tparam T
 * @param t1
 * @param t2
 */
template<class T> void my_swap(T &t1, T &t2) {
    T tmp = t1;
    t1 = t2;
    t2 = tmp;
}

void test_tempalte_func() {
    int a = 10, b = 20;
    // 自动类型推导
    my_swap(a, b);
    // 显示调用
    my_swap<int>(a, b);
    cout << "a = " << a << ", b = " << b << endl;
}

/**
 * 类模板
 *  参数可以有默认类型
 *
 * @tparam T
 * @tparam U
 */
template<class T, class U = int> class Person {
public:
    T name;
    U age;

    Person(T t, U u) {
        name = t;
        age = u;
    }

    void print() {
        cout << "name = " << name << ", age = " << age << endl;
    }
};

/**
 * 类模板作为函数参数
 *  1. 显示指定类型
 *  2. 类模板参数，参数化
 *  3. 类参数化
 *
 * @param p
 */
void printPerson1(Person<string, int> &p) {
    cout << "p.name = " << p.name << ", p.age = " << p.age << endl;
}

template<class T, class U>
void printPerson2(Person<T, U> &p) {
    cout << "p.name = " << p.name << ", p.age = " << p.age << endl;
}

template<class T> void printPerson3(T &p) {
    cout << "p 类型 = " << (typeid(p).name()) << endl;
}

void test_template_class() {
    Person<string, int> p("hello", 12);
    p.print();

    printPerson1(p);
    printPerson2(p);
    printPerson3(p);
}


template<class T> class Base {
    T m;
};

/**
 * 如果子类无法确定父类的参数化类型，那么编译器无法开辟空间「无法得知开辟多少空间」
 *  所以必须指定一个具化类型
 */
class Sub1 : public Base<int> {


template<class B, class S> class Sub2 : public Base<B> {
public:
    S s;
};

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {
    test_tempalte_func();
    test_template_class();

    return 0;
}

