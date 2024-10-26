#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
struct Node {
    int data;
    struct Node* next;
};

// 创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入节点到链表末尾
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 删除节点
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;

    // 如果头节点是要删除的节点
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // 改变头指针
        free(temp);
        return;
    }

    // 搜索要删除的节点
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果未找到节点
    if (temp == NULL) return;

    // 断开链表
    prev->next = temp->next;
    free(temp);
}

// 查找节点
struct Node* findNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 打印链表
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // 插入节点
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Initial List: ");
    printList(head); // 输出: 10 -> 20 -> 30 -> 40 -> NULL

    // 查找节点
    struct Node* foundNode = findNode(head, 30);
    if (foundNode) {
        printf("Found: %d\n", foundNode->data); // 输出: Found: 30
    } else {
        printf("Not Found\n");
    }

    // 删除节点
    deleteNode(&head, 20);
    printf("After Deleting 20: ");
    printList(head); // 输出: 10 -> 30 -> 40 -> NULL

    // 释放链表
    freeList(head);
    return 0;
}
