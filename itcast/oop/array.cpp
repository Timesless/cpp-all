/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *      类模板数组实现
 *      1. size / capacity
 *      2. 数组保存所有元素，并开辟到堆
 *      3. 重载赋值运算符「=」
 *      4. 重载拷贝构造函数，避免值拷贝，析构时重复释放同一块内存
 *      5. 重载[]
 *      6. 提供尾插
 *      7. 提供删除
 *      8. 提供打印
 *
 *  TODO
 *      空引用返回
 */

#include <iostream>

using namespace std;

template<class E> class Array {

private:
    // E类型数组的指针
    E *elements;
    int size;
    int capacity;
public:
    explicit Array<E>(int cap) {
        elements = new E[capacity];
        size = 0;
        capacity = cap;
    }

    // 重载拷贝构造函数
    Array<E>(const Array<E> &o) {
        size = o.size;
        capacity = o.capacity;
        elements = new E[o.capacity];
        for (int i = 0; i < size; ++i) {
            elements[i] = o.elements[i];
        }
    }

    // 重载赋值运算符
    Array& operator=(const Array<E> &o) {
        // 先释放自身在堆空间的内存
        if (elements != nullptr) {
            delete[] elements;
            elements = nullptr;
            size = capacity = 0;
        }
        // 深拷贝
        size = o.size;
        capacity = o.capacity;
        elements = new E[o.capacity];
        for (int i = 0; i < size; ++i) {
            elements[i] = o.elements[i];
        }

        return *this;
    }

    // 重载[]
    E& operator[](int idx) {
        if (idx >= size || idx < 0) {
            cout << "IndexOutofBounds index = " << idx << endl;
            return elements[0];
        }
        return elements[idx];
    }

    void push_back(E val) {
        if (size >= capacity) {
            cout << "full array error" << endl;
            return;
        }
        elements[size++] = val;
    }

    E pop_back() {
        if (size == 0 || capacity == 0) {
            cout << "empty array error" << endl;
            return 0;
        }
        return elements[--size];
    }

    /**
     * 通过指针访问数组
     */
    void print() {
        E* start = elements;
        for (int i = 0; i < size; ++i) {
            cout << (*start++) << " ";
        }
        cout << endl;
    }

    ~Array() {
        if (elements != nullptr) {
            delete[] elements;
            // 指针置空防止野指针
            elements = nullptr;
        }
    }
};

/**
 * 类模板数组实现
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    Array<int> arr(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);

    Array<int> arr2 = arr;
    Array<int> arr3(arr);
    cout << "arr2 pop_back = " << arr2.pop_back() << endl;
    arr3.pop_back();
    arr3.pop_back();
    arr.print();
    arr2.print();
    arr3.print();

    cout << "arr[1] = " << arr[1] << endl;

    return 0;
}

