/*
	* 학번 및 이름 : 202101354 정보통신공학과 양원준
	* 목적 및 개요 : 2-2학기 자료구조및알고리즘 과제 <큐를 이용한 고객서비스 시뮬레이션>
	* 과제수행날짜 : 2022.10.15(토)
	* 사용언어 : C언어
	* 프로그램 작성환경 및 실행환경 :
	*	OS : Kali GNU/Linux Rolling 2022.3
	*	IDE : vim editor 9.0
	*	Compiler gcc 11.3.0
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 5

// 고객 구조체 생성
typedef struct{
	int id;
	int arrival_time;
	int service_time;
	int togle; // 일반고객 0, VIP고객 1
} element;

// 원형큐 타입 고객 배열 구조체 생성
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 사용자 함수 프로토타입 선언
void init_queue(QueueType *q);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, element item);
element dequeue(QueueType *q);

// 메인 함수
int main(){
	int minutes=50000; // 50,000분 동안 시뮬레이션을 돌림
	int service_time=0, service_customer, service_togle; // 현재 서비스중인 고객의 정보
	int vip_count=0, vip_wait=0; // vip 고객 수, 대기시간
	int general_count=0, general_wait=0; // 일반 고객 수, 대기시간
	int total_count=0, total_wait=0; // 전체 고객 수, 대기시간
	int random=0;
	QueueType queue; // 원형큐 타입의 구조체 객체 생성

	init_queue(&queue); // 큐 초기화
	srand(time(NULL)); // 난수 초기화
	
	for(int clock=0; clock<minutes; clock++){ // 50,000번 반복
		printf("현재시각 = %d\n", clock);
		
		random = rand()%10; // 0~9까지 중 난수 하나 저장
		if(random < 3){ // VIP고객=0, 일반고객=1,2 라고 가정
			element customer;

			if(random==0){ // 10% 확률로 VIP 고객 발생
				customer.togle = 1; // vip 전용 토글
				vip_count++; // vip 고객 수 증가
			}
			else{
				customer.togle = 0; // 일반 전용 토글
				general_count++; // 일반 고객 수 증가
			}
				
			customer.id = total_count++;
			customer.arrival_time = clock; // 현재 시간을 도착 시간으로 저장
			customer.service_time = rand()%3+1; // 1~3분 중 랜덤 고객 업무 소요 시간
	
			enqueue(&queue, customer); // 고객을 대기열에 넣음
	
			if(customer.togle == 1) printf("VIP");
			else printf("일반");
			printf(" 고객%d이 %d 분에 들어옵니다. 업무 처리 시간 = %d 분\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if(service_time > 0){ // 현재 누군가가 업무처리중임
			if(service_togle == 1) printf("VIP");
			else printf("일반");
	
			printf(" 고객%d 업무처리중입니다.\n", service_customer);
			service_time--;
		}
		else{
			if(!is_empty(&queue)){ // 대기열에 고객이 있으면 대기번호가 가장 빠른 고객을 하나 꺼냄
				element customer = dequeue(&queue); // 그 고객의 정보를 저장
				service_customer = customer.id;
				service_togle = customer.togle; // 고객이 vip인지 일반 고객인지 확인
				service_time = customer.service_time;
				
				if(service_togle==1){ // vip 고객일 경우, vip 대기시간 증가
					vip_wait += clock-customer.arrival_time;
					printf("VIP");
				}
				else{ // 일반 고객일 경우, 일반 대기시간 증가
					general_wait += clock-customer.arrival_time;
					printf("일반");
				}	

				printf("고객%d이 %d 분에 업무 시작, 대기시간은 %d 분\n", customer.id, clock, clock-customer.arrival_time);
			}
		}
		total_wait = vip_wait + general_wait; // 전체 대기 시간
	}

	printf("\n\n==================================================================\n\n");
	printf("일반고객 || 전체대기시간=%d분 || 방문수=%d명 || 평균대기시간=", general_wait, general_count);
	if(general_count>0)	printf("%d분\n\n", general_wait/general_count);
	else printf("0분\n\n"); // 분모가 0일 경우, 즉 일반 고객이 없었을 경우

	printf("VIP고객  || 전체대기시간=%d분 || 방문수=%d명 || 평균대기시간=", vip_wait, vip_count);
	if(vip_count>0) printf("%d분\n\n", vip_wait/vip_count);
	else printf("0분\n\n"); // 위와 동일

	printf("전체고객 || 전체대기시간=%d분 || 방문수=%d명 || 평균대기시간=", total_wait, total_count);
	if(total_count>0) printf("%d분\n\n", total_wait/total_count);
	else printf("0분\n\n"); // 위와 동일
	
	printf("==================================================================\n\n");
	return 0;
}


// 큐 초기화 함수
void init_queue(QueueType *q){
	q->front = q->rear = 0;
}

// 큐 비어있는지 확인하는 함수
int is_empty(QueueType *q){
	return (q->front == q->rear);
}

// 큐 가득찼는지 확인하는 함수
int is_full(QueueType *q){
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 큐 리어에 데이터 삽입하는 함수
void enqueue(QueueType *q, element item){
	if(is_full(q)){
		printf("큐가 포화상태입니다.");
		//exit(1);  <------------------------- 대기열이 꽉찼음에도 고객이 들어오는 경우
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 큐 프론트의 데이터 삭제하는 함수
element dequeue(QueueType *q){
	if(is_empty(q)){
		printf("큐가 공백상태입니다.");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

