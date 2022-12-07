#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

// 스택 구조체 선언
typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 함수 프로토타입 선언
void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);
void error(char *message);

// 메인 함수
int main(int argc, char* argv[]){
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

void push(StackType *s, element item){
	if(is_full(s)){ // 스택이 가득찼으면 비정상 강제 종료
		error("스택 포화상태!");
	}
	s->data[++(s->top)] = item;
}

element pop(StackType *s){
	if(is_empty(s)){ // 스택이 비어있으면 비정상 강제 종료
		error("스택 공백상태!");
	}
	return (s->data[(s->top)--]);
}

element peek(StackType *s){
	return s->data[(s->top)];
}

void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}
