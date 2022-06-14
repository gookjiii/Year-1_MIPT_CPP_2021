#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Data;

typedef struct{
	int n;
	int size;
    int * a;
} Stack;

Stack * stack_create(int size);
void stack_push(Stack * s, Data x);
Data stack_pop(Stack * s);
Data stack_get(Stack * s);
void stack_print(Stack * s);
int  stack_size(Stack * s);
int  stack_is_empty(Stack * s);
void stack_clear(Stack * s);
void stack_destroy(Stack * s);

Stack * stack_create(int size)
{
    Stack * s = malloc(sizeof(Stack));
    s->n = 0;
    s->size = size;
    s->a = malloc(sizeof(Data)*s->size);
    return s;
}
void stack_push(Stack * s, Data x)
{
    if (s->n == s->size) {
        s->size += 10;
        s->a = realloc(s->a, sizeof(Data)*s->size);
    }
    s->a[s->n] = x;
    s->n ++;
}
Data stack_pop(Stack * s)
{
    s->n --;
    return s->a[s->n];
}
Data stack_get(Stack * s)
{
    return s->a[s->n - 1];
}
void stack_print(Stack * s)
{
    int i;
    for (i=0; i<s->n; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}
int  stack_size(Stack * s)
{
    return s->n;
}
int  stack_is_empty(Stack * s)
{
    return s->n == 0;
}
void stack_clear(Stack * s)
{
    free(s->a);
    s->a = NULL;
    s->size = 0;
    s->n = 0;
}
void stack_destroy(Stack * s)
{
    free(s->a);
    free(s);
}

int main()
{
	Stack *s = stack_create(2);
	char ch;
	while((ch = getchar())) 
		if(ch == '0' || ch == '1') {
			stack_push(s,ch-'0'); 
		} else if(ch == '|') {
				while(stack_size(s) >= 2) {
					Data a, b;
					a = stack_pop(s);
					b = stack_pop(s);
					stack_push(s,a|b);
				}
		} else if (ch == '&') {
				while(stack_size(s) >= 2) {
					Data a, b;
					a = stack_pop(s);
					b = stack_pop(s);
					stack_push(s,a&b);
				}
		} else if (ch == '!') {
				Data a = stack_pop(s);
			 	stack_push(s,!a);
		} else {
			break;
		}
	stack_print(s);
	stack_destroy(s);
}
