#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{    // 노드 타입을 구조체로 정의한다.
    element data;
    struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 노드 Pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head; 
}

ListNode* delete_first(ListNode *head)
{
    ListNode *removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

// Pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head)
{
    for(ListNode *p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

// 리스트를 역순으로 만드는 연산
ListNode* reverse(ListNode *head)
{
    // 순회 포인터로 p, q, r을 사용
    ListNode *p, *q, *r;

    p = head;   // p는 역순으로 만들 리스트
    q = NULL;   // q는 역순으로 만들 노드
    while (p != NULL){
        r = q;      // r은 역순으로 된 리스트

        q = p;      // r은 q, q는 p를 차례로 따라간다.
        p = p->link;
        q->link = r;    // q의 링크 방향을 바꾼다.
    }
    return q;
}
// 테스트 프로그램
int main(void)
{
    ListNode *head = NULL;
    ListNode *result = NULL;
    for(int i = 0; i < 4; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    result = reverse(head);
    print_list(head);
    return 0;
}