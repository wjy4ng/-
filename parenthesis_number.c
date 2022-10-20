#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define SIZE 10

// 스택 구조체 선언
typedef struct{
	int data[MAX_STACK_SIZE];
	int top;
} StackType;

// 함수 프로토타입 선언
void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, char item);
int pop(StackType *s);
int peek(StackType *s);

// 메인 함수
int main(){
	StackType s;
	int count=0;
	char arr[SIZE];

	printf("수식: ");
	scanf("%s", arr);

	printf("괄호 수: ");
	for(int i=0; i<SIZE; i++){
		if(arr[i]=='('){
			push(&s, ++count);
			printf("%d ", count);
		} else if(arr[i]==')')
			printf("%d ", pop(&s));
		else{
			printf("\n");
			return 0;
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

void push(StackType *s, char item){
	if(is_full(s)){ // 스택이 가득찼으면 비정상 강제 종료
		printf("스택 가득참!\n");
		exit(1);
	}
	s->data[++(s->top)] = item;
}

int pop(StackType *s){
	if(is_empty(s)){ // 스택이 비어있으면 비정상 강제 종료
		printf("스택이 비어있음!");
		exit(1);
	}
	return (s->data[(s->top)--]);
}

int peek(StackType *s){
	return s->data[(s->top)];
}
