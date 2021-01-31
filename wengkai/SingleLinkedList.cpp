//
// Created by yangzl on 2021/1/14.
//

#include <iostream>

using namespace std;


// 定义节点
typedef struct _node {
    int val;
    struct _node *next;
} Node;

// 单链表
typedef struct _list {
    // 首尾节点指针
    Node *head, *tail;
    int size;
} SingleLinkedList;

// 函数原型
// void addFirst(SingleLinkedList *, int);
void addLast(SingleLinkedList *, int);
void printList(SingleLinkedList *);

/**
 * 单链表
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    auto head = (Node) {
        -1, nullptr
    };
    auto tail = (Node) {
        -1, nullptr
    };
    auto list = (SingleLinkedList) {
        &head, &tail, 0
    };

    addLast(&list, 2);
    printList(&list);

    return 0;
}


// 尾插
void addLast(SingleLinkedList *list, int val) {
    auto h = list->head;
    while (h->next) {
        h = h->next;
    }
    // TODO malloc free
    auto newNode = (Node){
            val, nullptr
    };
    h->next = &newNode;
}

void printList(SingleLinkedList *list) {

    for(auto h = list->head->next; h; h = h->next) {
        cout << h->val << " -> " << endl;
    }
}