#include <stdio.h>
#define MAX_TERMS 101

struct{
	int coef;
	int expon;
} terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};

int avail=6; // 배열 마지막 다음부분

char compare(int a, int b){
	if(a>b) return '>';
	else if(a==b) return '=';
	else return '<';
}

void attach(float coef, int expon){
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void print_poly(int x1, int x2){
	for(int i=x1; i<x2; i++) printf("%dx^%d + ", terms[i].coef, terms[i].expon);
	printf("%dx^%d\n", terms[x2].coef, terms[x2].expon);
}

void poly_add(int a1, int a2, int b1, int b2, int *c1, int *c2){
	float tempcoef;
	*c1 = avail;

	while(a1 <= a2 && b1 <= b2){
		switch(compare(terms[a1].expon, terms[b1].expon)){
		case '>':
			attach(terms[a1].coef, terms[a1].expon);
			a1++;
			break;	
		case '=':
			tempcoef = terms[a1].coef + terms[b1].coef;
			attach(tempcoef, terms[a1].expon);
			a1++; b1++;
			break;
		case '<':
			attach(terms[b1].coef, terms[b1].expon);
			b1++;
			break;
		}
	}
	*c2 = avail-1;
}


int main(void){
	int A1=0, A2=2;
	int B1=3, B2=5;
	int C1, C2;

	print_poly(A1, A2);
	print_poly(B1, B2);
	printf("-----------------------------------------------------------\n");

	poly_add(A1, A2, B1, B2, &C1, &C2);
	print_poly(C1, C2);

	return 0;
}

