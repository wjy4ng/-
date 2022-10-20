#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100
#define SIZE 10

// 스택 구조체 선언
typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 함수 프로토타입 선언
void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, int item);
element pop(StackType *s);
element peek(StackType *s);

// 메인 함수
int main(int argc, char* argv[]){
	StackType s;
	char arr[SIZE];
	int count=0;

	init_stack(&s);
	printf("문자열을 입력하시오: ");
	scanf("%s", arr);

	for(int i=0; i<SIZE; i++){
		char ch = tolower(arr[i]);		
		if(is_empty(&s) || ch == peek(&s)){
			count++;
			push(&s, ch);
		}
		else if(ch != peek(&s)){
			printf("%d%c", count, peek(&s));
			count=0;
			while(!is_empty(&s)) pop(&s);
			i--;
		}
	}
}



void init_stack(StackType *s){ 
	(s->top) = -1; // -1 : 스택이 비어있다는 의미
}

int is_empty(StackType *s){ // top이 비어있으면 True
	return ((s->top) == -1);
}

int is_full(StackType *s){ // top이 꽉 찼으면 True
	return ((s->top)==MAX_STACK_SIZE-1);
}

void push(StackType *s, int item){
	if(is_full(s)){ // 스택이 가득찼으면 비정상 강제 종료
		printf("스택 가득참!\n");
		exit(1);
	}
	s->data[++(s->top)] = item;
}

element pop(StackType *s){
	if(is_empty(s)){ // 스택이 비어있으면 비정상 강제 종료
		printf("스택이 비어있음!");
		exit(1);
	}
	return (s->data[(s->top)--]);
}

element peek(StackType *s){
	return s->data[(s->top)];
}

