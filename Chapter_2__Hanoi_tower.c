#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to){
	if(n==1) printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else{
		hanoi_tower(n-1, from, to, tmp);
		printf("원판 %d를 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoi_tower(n-1, tmp, from, to);
	}
}

int main(){
	int n=0;
	
	printf("input a number ---> ");
	scanf("%d", &n);
	hanoi_tower(n, 'A', 'B', 'C');
	return 0;
}



