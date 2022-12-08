/*
	* 학번 및 이름 : 202101354 정보통신공학과 양원준
	* 목적 및 개요 : 2-2학기 자료구조및알고리즘 과제 <교재 연결리스트II 연습문제>
	* 과제수행날짜 : 2022.12.06(화)
	* 사용언어 : C언어
	* 프로그램 작성환경 및 실행환경 :
	*	OS : Kali GNU/Linux Rolling 2022.3
	*	IDE : vim editor 9.0
	*	Compiler gcc 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ArraySize 100

// Define Singly Linked List
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// Define Abstract Data Type
ListNode* insert_last(ListNode* head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;

	if(head == NULL){
		head = p;
		p->link = head;
	}
	else{
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}

void print_list(ListNode *head){
	ListNode *p;

	if(head == NULL) return;
	p = head->link;
	do{
		printf("%d->", p->data);
		p = p->link;
	} while(p!=head);
	printf("%d->\n", p->data); // 헤드 포인터 출력
}

// Define search()
ListNode* search(ListNode *head, element value){
	ListNode *p;

	if(head==NULL) return 0;
	p = head;
	do{
		if(p->data == value) return p;
		p = p->link;
	} while(p!=head);
	return 0;
}

// main
int main(){
	ListNode *head = NULL;
	int size=0, arr[MAX_ArraySize], value=0;
	int* result;

	printf("입력 값 크기 : ");
	scanf("%d", &size);

	printf("정수를 입력하시오: ");
	for(int i=0; i<size; i++) scanf("%d", &arr[i]); // 정수 입력 받기
	for(int i=0; i<size; i++) head = insert_last(head, arr[i]); // 리스트에 넣기

	printf("리스트 : "); print_list(head);

	printf("탐색하려는 값 : ");
	scanf("%d", &value);

	result = (int *)search(head, value);
	if(result != 0) printf("%d이/가 리스트에 존재합니다.\n", value);
	else printf("%d이/가 리스트에 존재하지 않습니다.\n", value);
	return 0;
}

