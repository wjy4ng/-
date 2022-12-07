/*
	* 학번 및 이름 : 202101354 정보통신공학과 양원준
	* 목적 및 개요 : 2-2학기 자료구조및알고리즘 과제 <교재 연결리스트I 연습문제 변형>
	* 과제수행날짜 : 2022.12.05(월)
	* 사용언어 : C언어
	* 프로그램 작성환경 및 실행환경 :
	*	OS : Kali GNU/Linux Rolling 2022.3
	*	IDE : vim editor 9.0
	*	Compiler gcc 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ArraySize 100

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, element value);
void print_list(ListNode *head);
void split(ListNode *head, int size);


int main(){
	ListNode *A_head = NULL;
	int size=0, arr[MAX_ArraySize];

	printf("입력 값 크기 : "); // 만약 5를 넣으면
	scanf("%d", &size);

	printf("정수를 입력하시오 : ");
	for(int i=0; i<size; i++) scanf("%d", &arr[i]); // 만약 1, 2, 3, 4, 5를 넣으면
	for(int i=0; i<size; i++) A_head = insert_first(A_head, arr[i]);

	split(A_head, size); // 이제 A에서 B,C,D를 분리해야 함

	return 0;
}

void split(ListNode *head, int size){
	ListNode *B_head = NULL; // B 헤드 포인터 생성
	ListNode *C_head = NULL; // C 헤드 포인터 생성
	ListNode *D_head = NULL; // D 헤드 포인터 생성
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 단순 연결 리스트 객체 생성

	p = head; // split 함수가 A를 변경하지 않도록 p 생성 후 A를 복사
	while(p != NULL){
		int count = size % 3; // 총 5번 입력했으니 5%3=2, 처음값은 나머지가 2인 C에 넣고, 다음값은 size-1이니 4%3=1이니 1에 넣고... 반복
		if(count % 3 == 1) B_head = insert_first(B_head, p->data); // 1, 4, 7번째
		else if(count % 3 == 2) C_head = insert_first(C_head, p->data); // 2, 5, 8번째
		else D_head = insert_first(D_head, p->data); // 3, 6, 9번째

		size--;
		p = p->link;
	}

	printf("B: "); print_list(B_head);
	printf("C: "); print_list(C_head);
	printf("D: "); print_list(D_head);
}

ListNode* insert_first(ListNode *head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode *head){
	for(ListNode *p=head; p!=NULL; p=p->link){
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

