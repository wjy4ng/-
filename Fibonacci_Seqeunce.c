/*
	* 학번 및 이름 : 202101354 정보통신공학과 양원준
	* 목적 및 개요 : 2-2학기 자료구조및알고리즘 과제 <피보나치 수열>
	* 과제수행날짜 : 2022.10.14(금)
	* 사용언어 : C언어
	* 프로그램 작성환경 및 실행환경 :
	*	OS : Kali GNU/Linux Rolling 2022.3
	*	IDE : vim editor 9.0
	*	Compiler gcc 11.3.0
*/



#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 1 // 스택 최대 사이즈 ( result값만 들어감 )

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
void push(StackType *s, int item);
element pop(StackType *s);


// 메인 함수
int main(int argc, char* argv[]){
	StackType s;
	int num;
	int temp1=1, temp2=0, result=0;

	printf("input a number ---> ");
	scanf("%d", &num); // 피보나치 수를 몇번째 항까지 구할건지 입력받음

	init_stack(&s); // 스택 초기화
	printf("0 "); // 피보나치 첫번째항 0을 미리 출력
	push(&s, temp1); // 스택에 temp1(=1) 넣음 ( 다음 반복문에서 pop할때 스택이 비어있으면 안되기 때문 )

	for(int i=0; i<num; i++){ // num 번쨰 항만큼 반복
		temp1 = pop(&s); // 스택에서 중간값(=fib(n-1))을 가져옴
		printf("%d ", temp1);

		result = temp1 + temp2; // (=(fib(n-1) + fib(n-2))) 와 같음
		push(&s, result); // 그 값을 스택에 넣음
		temp2 = temp1; // 끝값(=fib(n-2))에 중간값 대입 
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



