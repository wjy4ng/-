#include <stdio.h>
#define MAX_TERMS 10

// 행, 열, 값 요소
typedef struct{
	int row;
	int col;
	int value;
} element;

// 희소행렬 구조체 선언
typedef struct SparseMatrix{
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

void matrix_print(SparseMatrix a){ // 행렬 출력
	printf("-----------------\n");
	for(int i=0; i<a.terms; i++) printf("(%d, %d, %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
	printf("-----------------\n");
}

SparseMatrix matrix_transpose(SparseMatrix a){ // 희소행렬로 변환
	SparseMatrix b;
	int bindex; // b 행렬의 인덱스번호
	b.cols = a.rows;
	b.rows = a.cols;
	b.terms = a.terms;

	for(int i=0; i<b.terms; i++){ // b 행렬이 채워지는 과정을 나타내기 위해 0으로 초기화
		b.data[i].row = 0;
		b.data[i].col = 0;
		b.data[i].value = 0;
	}

	if(a.terms > 0){ // 항의 개수가 0보다 크면
		bindex=0;
		for(int c=0; c<a.cols; c++){ // a의 열 중 가장 큰 수가 5이므로 0~5까지 비교할것임
			for(int i=0; i<a.terms; i++){ // a 항의 개수가 7개이므로 한줄한줄 비교할것임
				if(a.data[i].col == c){ // a 항의 한줄의 열이 c와 같으면
					b.data[bindex].row = a.data[i].col; // 행렬 위치 바꿈
					b.data[bindex].col = a.data[i].row; // 행렬 위치 바꿈
					b.data[bindex].value = a.data[i].value;
					bindex++; // b 행렬 다음줄로
					printf("b process\n"); 
					matrix_print(b); // b 행렬 채워지는 과정 출력
				}
			}
		}
	}
	return b;
}

int main(){
	SparseMatrix m = {
		{{0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2}},
		6,
		6,
		7
	};
	SparseMatrix result;

	result = matrix_transpose(m);
	printf("\n전 후 비교\n======================================\n");
	matrix_print(m);
	matrix_print(result);

	return 0;
}

