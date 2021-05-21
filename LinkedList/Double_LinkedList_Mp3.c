#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct DlistNode {  // 이중연결 노드 타입
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

DlistNode* current; //전역변수

void init(DlistNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DlistNode *before, element data)
{
    DlistNode *newnode = (DlistNode *)malloc(sizeof(DlistNode));
    strcpy(newnode->data, data);
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// 노드 removed를 삭제한다.
void ddelete(DlistNode* head, DlistNode* removed)
{
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DlistNode* phead)
{
    DlistNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink){
        if (p == current)
            printf("<-| #%s# |-> ", p->data);
        else
            printf("<-| %s |-> ", p->data);
    }
    printf("\n");
}

// 이중 연결 리스트 테스트 프로그램
int main(void)
{
    char ch;
    DlistNode* head = (DlistNode *)malloc(sizeof(DlistNode));
    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");

    current = head->rlink;
    print_dlist(head);
    do {
        printf("\n명령어를 입력하시오(<,>,q): ");
        ch = getchar();
        if (ch == '<'){
            current = current->llink;
            if (current == head)
                current = current->llink;
        }
        else if (ch == '>') {
            current = current->rlink;
            if (current == head)
                current = current->rlink;
        }
        print_dlist(head);
        getchar();
    } while (ch != 'q');
    free(head);
    {
        /* code */
    }
    

    return 0;
}