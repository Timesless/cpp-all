/**
 * @author yangzl
 * @date 2021/2/8
 * @desc
 *
 *  lambda使用
 *      1. 无参无返回值
 *      2. 无参有返回值
 *      3. 有参有返回值
 *      4. 指针 / 引用
 */
#include <iostream>

using namespace std;

class Stu {
public:
    string name;
    int age;
    string sex;

    Stu(string name, int age, string sex) {
        this->name = name;
        this->age = age;
        this->sex = sex;
    }

    ~Stu() {
        cout << "析构函数调用" << endl;
    }
};

/*
 *  lambda 基本使用
 */
void test_lambda() {
    [] {
        cout << "无参无返回值 λ式" << endl;
        cout << "lambda 自调用" << endl;
    }();

    auto f2 = []() -> int {
        cout << "无参有返回值 λ式" << endl;
        return 2;
    };
    f2();

    auto f3 = [](int p1, int p2) {
        cout << "有参无返回值 λ式" << endl;
    };
    f3(1, 2);

    auto f4 = [](int p1, int p2) -> int {
        cout << "有参有返回值 λ式" <<endl;
        return p1 * p2;
    };
    cout << "返回值 = " << f4(10, 10) << endl;

    auto f5 = [](Stu &s) {
        s.name = "lambda name";
    };
    auto s = Stu{"hh", 1, "1"};
    cout << "s.name = " << s.name << endl;
    f5(s);
    cout << "s.name = " << s.name << endl;
}

void test_lambda2() {
    int id = 42;
    // 需要捕获id
    auto f1 = [id]() mutable {
        cout << "id = " << (id++) << endl;
    };
    f1();
    f1();
    f1();
    cout << "outer id = " << id << endl;
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_lambda();
    cout << "=========================================" << endl;
    test_lambda2();

    return 0;
}




