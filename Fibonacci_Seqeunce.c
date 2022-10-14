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

// 피보나치 함수 프로토타입 선언
int fib(int n);

int main(){
	int num;

	printf("input = ");
	scanf("%d", &num); // 반복문을 실행하기 위해 입력값 num을 받는다

	for(int i=0; i<=num; i++){ // num 만큼 반복
		printf("%d ", fib(i)); // 0~num 까지 피보나치 함수에 대입
	}
}

int fib(int n){
	if(n==0) return 0; // n이 0이면 0을 반환하여 출력
	if(n==1) return 1; // n이 1이면 1을 반환하여 출력
	return fib(n-1) + fib(n-2); // n부터 스택에 쌓이고 이어 n-1, n-2도 스택에 계속해서 쌓임
}
