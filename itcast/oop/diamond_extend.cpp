/**
 * @author yangzl
 * @date 2021/1/29
 * @desc
 *
 *      1. 继承
 *      2. 继承父类变量的访问
 *      3. 菱形继承的解决
 */

#include <iostream>

using namespace std;

/**
 * 父类
 * private 属性不能被子类使用
 */
class Base {
public:
    int p1;

    Base() {
        p1 = p2 = p3 = 0;
        cout << "base 构造器" << endl;
    }

    void fun() {
        cout << "base fun" << endl;
    }

    void fun(int v) {
        cout << "base fun(int)" << endl;
    }

protected:
    int p2;
private:
    int p3;
};

/**
 * public继承：访问修饰符不变
 * protected继承：父类public，protected属性被子类继承为protected
 * private继承：父类public，protected属性被子类继承为private
 */
class Sub1 : public Base {

};

class Sub2 : protected Base {

};

class Sub3 : private Base {

};


void test_sub1() {
    Sub1 s;
    s.p1 = 10;
    // s.p2 = 10;

    cout << "sizeof sub = " << sizeof(s) << endl;
}

void test_sub2() {
    Sub2 s;
    // s.p1 = 10; protected无法在类外访问
}

// private继承
void test_sub3() {
    Sub3 s;
    // s.p1 = 10;
}


class Son : public Base {
public:
    int p1;

    Son() {
        p1 = 100;
    }

    void fun() {
        cout << "son fun" << endl;
    }
};

void test_son() {
    Son s;
    cout << "s.p1 = " << s.p1 << endl;
    cout << "s.parent.p1 = " << s.Base::p1 << endl;

    /*
     * 子类与父类同名，通过作用域访问
     */
    s.fun();
    s.Base::fun();
    s.Base::fun(1);
}

/**
 * 多继承
 */
class GrandSon : public Sub1, public Son {

};

void test_grandson() {
    GrandSon s;
    cout << "son p1 = " << s.Son::p1 << endl;
    cout << "sub p1 = " << s.Sub1::p1 << endl;
    // Son 16 + Sub1 12 = 28
    cout << "sizeof grandson = " << sizeof(s) << endl;
}


/**
 * 菱形继承，
 *  导致属性有两份，浪费RAM
 *      通过虚继承解决「继承一个vbptr（虚基类指针，指向一个vbtable，即指向同一内存空间）」
 */
 class Animal {
 public:
     int age;
 };

 class Sheep: virtual public Animal {

 };

 class Camel: virtual public Animal {

 };

 class SheepCamel: public Sheep, public Camel {

 };

 /**
  * 菱形继承测试
  */
 void test_dimaond_extends() {
     SheepCamel sc;
     sc.Sheep::age = 10;
     sc.Camel::age = 20;

     // Sheep::age, Camel::age, this->age都指向同一个内存空间
     cout << "sheep age = " << sc.Sheep::age << endl;
     cout << "camel age = " << sc.Camel::age << endl;
     cout << "sheepCamel age = " << sc.age << endl;
 }


/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {
    test_sub1();
    // test_sub2();
    // test_sub3();

    test_son();

    test_grandson();

    test_dimaond_extends();
    return 0;
}