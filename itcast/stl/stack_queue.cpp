/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *      1. 栈
 *          无参构造
 *          拷贝构造
 *          operator=
 *          empty
 *          size
 *          push
 *          pop
 *          top
 *      2. 队列
 *          无参构造
 *          拷贝构造
 *          operator=
 *          empty
 *          size
 *          front
 *          back
 *          push
 *          pop
 *
 *
 */
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void test_stack() {
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(3);
    cout << "stack.size = " << s.size()  << endl;
    s.pop();
    cout << "s.top = " << s.top() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void test_queue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "q.front = " << q.front() << ", q.back = " << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *const argv[]) {

    test_stack();
    test_queue();

    return 0;
}
