#include<stdio.h>
#include<stdlib.h>


typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};
typedef struct Node * List;

List list_create (); 
void list_push (List * plist, Data x); 
Data list_pop (List * plist);   
Data list_get(List list); 
void list_print (List list); 
int list_size(List list); 
void list_clear(List * plist);

List list_create () {
    struct Node * p = malloc(sizeof(struct Node));

    p->next = NULL;
    return p;
}   
void list_push (List * plist, Data x) {
    struct Node * p = malloc(sizeof(struct Node));
    p->val = x;
    p->next = * plist;
    * plist = p;
}
Data list_pop (List * plist) {
    struct Node * p = * plist;
    
    Data res = p->val;
    * plist = p->next;
    free(p);
    return res;
}
void list_print (List list) {
    for(struct Node * p = list; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
}
Data list_get(List list){
    struct Node * p = list;
    return p->val;
}

int list_size(List list) {
    int n = 0;
    for (struct Node * p = list; p != NULL; p = p->next)
        n++;
    return n;
}

/*void list_clear(List * plist) {

}*/

int list_is_empty(List list) {
    return list == NULL;
}

void test0()
{
    List list = list_create();
    list_print(list);                               // ?????? ??????
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    list_push(&list, 21);
    list_print(list);                               // 21
    list_push(&list, 17);
    list_print(list);                               // 17 21
    list_push(&list, 3);
    list_print(list);                               // 3 17 21
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 0
    printf("size = %d\n", list_size(list));         // size = 3

    Data x = list_pop(&list);
    printf("pop %d\n", x);                          // pop 3
    list_print(list);                               // 17 21
    printf("size = %d\n", list_size(list));         // size = 2

    /*list_clear(&list);
    list_print(list);                               // ?????? ??????
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0*/
}

int main()
{
    test0();
    return 0;
}

