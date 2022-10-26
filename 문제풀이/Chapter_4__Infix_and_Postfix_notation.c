/*

	* 1. 중위 표기식 -> 후위 표기식
	* 2. 후위 표기식 계산

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

// 스택 구조체 생성
typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 ADT 함수 프로토타입 선언
void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, char ch);
element pop(StackType *s);
int peek(StackType *s);
void postfix_notation(char ch[]);
void infix_to_postfix(char ch[]);
int prec(char ch);





// 메인 함수
int main(){
	char *ch = "(2+3)*4+9";

	printf("중위 표기식 : %s", ch);
	printf("\n============================\n");

	printf("후위 표기식 : ");
	infix_to_postfix(ch);

	printf("\n============================\n");
	printf("후위 표기식 계산 : ");
	postfix_notation(ch);
	return 0;
}





// 스택 초기화 함수
void init_stack(StackType *s){
	(s->top) = -1;
}

// 스택 비어있는지 확인하는 함수
int is_empty(StackType *s){
	return ((s->top)==-1);
}

// 스택 가득찼는지 확인하는 함수
int is_full(StackType *s){
	return ((s->top)==MAX_STACK_SIZE-1);
}

// 스택에 삽입시키는 함수
void push(StackType *s, char ch){
	if(is_full(s)){
		printf("스택 가득참!\n");
		exit(1);
	}
	s->data[++(s->top)] = ch;
}

// 스택에서 삭제시키는 함수
element pop(StackType *s){
	if(is_empty(s)){
		printf("스택 비어있음!\n");
		exit(1);
	}
	return (s->data[(s->top)--]);
}

// 스택의 top 값을 엿보는 함수
int peek(StackType *s){
	return (s->data[(s->top)]);
}

// 연산자 우선순위 비교 함수
int prec(char ch){
	switch(ch){
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}



// 중위 표기식 -> 후위 표기식 변환 함수
void infix_to_postfix(char ch[]){
	StackType s;
	char tmp;

	init_stack(&s);
	for(int i=0; i<strlen(ch); i++){
		switch(ch[i]){
		case '+': case '-': case '/': case '*':
			while(!is_empty(&s) && (prec(ch[i]) <= prec(peek(&s)))) printf("%c", pop(&s)); // 우선순위 비교, 더 크거나 같으면 출력
			push(&s, ch[i]); // 아니면 연산자 스택에 삽입
			break;

		case '(':
			push(&s, ch[i]); break;

		case ')':
			tmp = pop(&s);
			while(tmp != '('){
				printf("%c", tmp);
				tmp = pop(&s);
			} break;

		default:
			printf("%c", ch[i]); break;
		}
	}
}



// 후위 표기식 계산 함수
void postfix_notation(char ch[]){
	StackType s;
	int tmp1=0;
	char tmp2, tmp3;

	init_stack(&s);

	for(int i=0; i<strlen(ch); i++){
		if(ch[i] != '+' && ch[i] != '-' && ch[i] != '/' && ch[i] != '*'){ // 피연산자일때
			tmp1 = ch[i] - '0';
			push(&s, tmp1);
		}
		else{ // 연산자이면
			tmp2 = pop(&s);
			tmp3 = pop(&s);

			switch(ch[i]){
			case '+': push(&s, tmp2+tmp3); break;
			case '-': push(&s, tmp2-tmp3); break;
			case '/': push(&s, tmp2/tmp3); break;
			case '*': push(&s, tmp2*tmp3); break;
			}
		}
	}
	printf("%d", peek(&s));
}


