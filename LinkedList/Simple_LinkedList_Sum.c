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

// 2개의 리스트를 합하는 함수
ListNode* concat_list(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL) return head2;        // head1이 NULL이면 head2를 반환
    else if (head2 == NULL) return head1;   // head2가 NULL이면 head1을 반환
    else {
        ListNode *p;
        p = head1;                          // p에 head1을 연결
        while (p->link != NULL)             // p->link가 NULL이 될 때까지 반복
            p = p->link;                    // p가 끝까지 가도록 이동
        p->link = head2;                    // p를 head2 처음에 연결
        return head1;
    }

}
// 테스트 프로그램
int main(void)
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *sum = NULL;
    for(int i = 0; i < 5; i++){
        head1 = insert_first(head1, i);
        print_list(head1);
    }
    for(int i = 0; i < 5; i++){
        head2 = insert_first(head2, i);
        print_list(head2);
    }
    sum = concat_list(head1, head2);
    print_list(sum);
    return 0;
}