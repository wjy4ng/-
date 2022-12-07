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

// 노드 구조체
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// 노드 ADT 구현
ListNode* insert_first(ListNode *head, element value);
void print_list(ListNode *head);
ListNode* reverse(ListNode *head);
void split(ListNode *head);


// 메인 함수
int main(){
	ListNode *A_head = NULL;
	int size=0, arr[MAX_ArraySize];

	printf("입력 값 크기 : ");
	scanf("%d", &size);

	printf("정수를 입력하시오: ");
	for(int i=0; i<size; i++) scanf("%d", &arr[i]); // 정수 입력 받기
	for(int i=size-1; i>=0; i--) A_head = insert_first(A_head, arr[i]); // A 리스트에 넣기

	printf("\nsplit 함수 사용 전 A : ");
	print_list(A_head); // A 리스트 출력
	
	split(A_head); // 분리 함수 호출

	printf("split 함수 사용 후 A : ");
	print_list(A_head); // split 함수가 A를 변경시키지 않음

	return 0;
}

void split(ListNode *head){
	ListNode *B_head = NULL; // B 헤드 포인터 생성
	ListNode *C_head = NULL; // C 헤드 포인터 생성
	ListNode *D_head = NULL; // D 헤드 포인터 생성
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 단순 연결 리스트 객체 생성
	int count=1; // 3으로 나눌 값

	p = head; // split 함수가 A를 변경하지 않도록 p 생성 후 A를 복사
	while(p != NULL){
		if(count % 3 == 1) B_head = insert_first(B_head, p->data); // 1, 4, 7번째
		else if(count % 3 == 2) C_head = insert_first(C_head, p->data); // 2, 5, 8번째
		else D_head = insert_first(D_head, p->data); // 3, 6, 9번째

		count++;
		p = p->link;
	}

	printf("B: "); print_list(reverse(B_head)); // 리스트는 역순을 취해주어야 알맞은 순서로 나옴
	printf("C: "); print_list(reverse(C_head));
	printf("D: "); print_list(reverse(D_head));
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

ListNode* reverse(ListNode *head){
	ListNode *p, *q, *r;

	p = head;
	q = NULL;
	while(p != NULL){
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

