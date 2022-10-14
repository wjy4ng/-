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

int fib(int n);

int main(){
	int num;

	printf("input = ");
	scanf("%d", &num);

	for(int i=0; i<=num; i++){
		printf("%d ", fib(i));
	}
}

int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fib(n-1) + fib(n-2);
}
