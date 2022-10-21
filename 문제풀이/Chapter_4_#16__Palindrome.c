#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100
#define SIZE 30

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
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);
void error(char *message);

// 메인 함수
int main(int argc, char* argv[]){
	StackType s;
	char arr[SIZE];
	int i=0;

	init_stack(&s);
	printf("input ---> ");
	scanf("%s", arr); // madam

	// 입력 문자열을 전부 스택에 넣음
	for(int j=0; j<SIZE; j++){
		char tmp = tolower(arr[j]);
		if(tmp >= 'a' && tmp <= 'z'){
			push(&s, tmp);
		}
	}

	// 스택에서 하나씩 꺼내면서 arr와 같은지 비교
	while(!is_empty(&s)){
		char tmp = pop(&s);
		if(tmp != arr[i]){
			printf("회문이 아닙니다");
			return 0;
		}
		i++;
	}
	printf("회문입니다\n");
	return 0;
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
