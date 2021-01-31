/**
 * @author yangzl
 * @date 2021/1/26
 * @desc
 *
 *      编译器至少給一个类添加4个方法
 *          1. 默认构造
 *          2. 默认析构
 *          3. 拷贝构造
 *          4. 赋值运算符「对属性进行简单的值拷贝」
 */

#include <iostream>

using namespace std;


/**
 * 自定义Integer，实现将空间开辟到堆
 */
class Integer {

    // 全局函数做友元
    friend ostream& operator<<(ostream &, Integer);
    friend istream& operator>>(istream &, Integer &);

public:
    // 无参构造
    Integer() {
        val = new int(0);
        cout << "默认构造函数" << endl;
    }
    // 有参构造
    explicit Integer(int v) {
        val = new int(v);
        cout << "有参构造函数被调用" << endl;
    }
    /*
     * 拷贝构造函数
     *  1. 使用一个已经创建完毕的对象来初始化一个新对象
     *  2. 值传递方式給函数参数传值
     *  3. 以值方式返回局部对象「Integer i; return i; // 返回i的值拷贝」
     */
    Integer(const Integer &o) {
        this->val = new int(*o.val);
    }

    // 析构函数
    ~Integer() {
        if (val != nullptr) {
            delete val;
            val = nullptr;
        }
        // cout << "析构函数被调用" << endl;
    }

    /**
     * *this->val += *other.val
     *
     * @param o other
     * @return
     */
    Integer& operator+(Integer &o) {
        *(this->val) += *(o.val);
        return *this;
    }

    // TODO
    Integer& operator-(Integer &o) {

    }

    /**
     * 重载赋值运算符「=」
     * 如果使用编译器提供的赋值运算符，那么是简单的值拷贝，析构函数会重复释放内存导致程序异常
     *
     * @param o other
     * @return
     */
    Integer& operator=(const Integer &o) {
        if (val != nullptr) {
            delete val;
            val = nullptr;
        }
        // 深拷贝
        val = new int(*o.val);
        return *this;
    }

    // 重载 prefix ++
    Integer& operator++() {
        *this->val += 1;
        return *this;
    }
    /**
     * 重载 suffix ++，必须提供一个int参数占位符代表重载后置++
     *
     * @return Integer
     */
    Integer operator++(int) {
        // 这是局部变量，不能返回其引用，所以返回Integer类型本身
        Integer tmp = *this;
        *this->val += 1;
        return tmp;
    }

    // TODO operator--
    // TODO operator--(int)

    /**
     * 关系运算符重载
     * ==, !=, >, <, >=, <=
     *
     * @param o
     * @return
     */
    bool operator==(Integer &o) {
        return *this->val == *o.val;
    }
    bool operator>(Integer &o) {
        return *this->val > *o.val;
    }
    bool operator<=(Integer &o) {
        return *this->val <= *o.val;
    }

private:
    int *val;
};

/*
 * 通过全局函数重载 << | >>
 */
ostream& operator<<(ostream &out, Integer v) {
    return out << *(v.val);
}
istream& operator>>(istream &in, Integer &v) {
    int &ref = *(v.val);
    return in >> ref;
}


// ()重载「仿函数」
class Printer {
public:
    void operator() (string str) {
        cout << str << endl;
    }
};



/**
 * 操作符、运算符重载
 *      1. operator<<
 *      2. operator>>
 *      3. operator++
 *      4. operator++(int)
 *      5. operator--
 *      6. operator--(int)
 *      7. operator=
 *      8. operator[]
 *      9. + / -
 *      10 == / !=
 *      11 > / <
 *
 * ()重载「仿函数」
 *
 * @param argc
 * @param argv
 * @return
 */

void test_overload() {
    Integer i1;
    Integer i2(i1);

    cout << "++(++i) = " << ++(++i1) << endl;
    cout << "i1 = " << i1 << endl;

    Integer i3;
    cout << "(i++)++ = " << ((i3++)++) << endl;
    cout << "i3 = " << i3 << endl;

    cout << "i1 + i3 = " << (i1 + i3) << endl;

    i1 = i2 = i3;
    cout << "i1 = i2 = i3 = " << i1 << endl;

    cout << "i1 == i2 ? " << (i1 == i2) << endl;
}

void test_func() {
    Printer p;
    p("hello cpp");

    Printer()("hello anonymous func");
}

int main(int argc, char *const argv[]) {

    test_overload();
    test_func();
    return 0;
}


