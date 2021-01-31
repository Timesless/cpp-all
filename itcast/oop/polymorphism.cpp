/**
 * @author yangzl
 * @date 2021/1/29
 * @desc
 *
 *  1. 多态
 *  2. 纯虚函数与抽象类
 *      抽象类无法实例化对象
 *  3. 虚析构与纯虚析构
 *      父类指针释放子类对象
 *
 *      动态多态，通过virtual关键字开启动态分派机制「Java默认动态分派」
 *      虚方法「vbtable」
 *
 *      C++ 空类占用1字节
 *      添加虚方法之后占用4字节「vfptr 指向 vftable」
 *
 *      **父类指针 / 引用指向子类对象
 *          Animal &animal = cat
 */

#include <iostream>
#include <string>

using namespace std;

class Animal {

public:
    void static_say() {
        cout << "animal say" << endl;
    }

    virtual void dynamic_say() {
        cout << "dynamic animal say" << endl;
    }
};

class Cat : public Animal {
public:
    void static_say() {
        cout << "cat say" << endl;
    }

    virtual void dynamic_say() {
        cout << "dynamic cat say" << endl;
    }
};

/**
 * 默认分派机制为静态分派
 *      通过virtual关键字开启动态分派
 *
 * @param a
 */
void static_speak(Animal &a) {
    a.static_say();
}

void dynamic_speak(Animal &a) {
    a.dynamic_say();
}


void test_polymorphism() {
    Cat cat;
    static_speak(cat);

    dynamic_speak(cat);
}



class Base {
public:
    // 纯虚函数
    virtual void func() = 0;

    Base() {
        cout << "base 构造" << endl;
    }

    /*
     * 使用虚析构解决父类指针指向子类对象时，不调用子类析构方法
     * 纯虚析构
     *      virtual ~Base() = 0;
     * 需要在类外提供实现
     *      Base::~Base() {
     *          cout << "base 析构实现" << endl;
     *      }
     */
    virtual ~Base() {
        cout << "base 析构" << endl;
    }
};

class Sub : public Base {

public:
    void func() {
        cout << *name << "重写纯虚函数" << endl;
    }

    string *name;

    Sub(string name) {
        this->name = new string(name);
    }

    ~Sub() {
        if (name != nullptr) {
            delete name;
            name = nullptr;
        }
        cout << "son 析构" << endl;
    }
};

void test_pure_virtual_func() {

    /*
     * 父类指针指向子类对象，当父类析构函数执行时并不调用子类析构函数
     *  子类有变量在堆空间开辟将会导致内存泄漏
     *  TODO
     */
    Base *b = new Sub("Tom");
    b->func();
    delete b;
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    test_polymorphism();

    test_pure_virtual_func();

    return 0;
}
