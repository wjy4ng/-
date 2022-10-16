#include <stdio.h>
#define ROWS 3
#define COLS 3

// 전치행렬 변환 함수
void matrix_transpose(int arr1[ROWS][COLS], int arr2[ROWS][COLS]){
	for(int r=0; r<ROWS; r++){
		for(int c=0; c<COLS; c++){
			arr2[c][r] = arr1[r][c]; // 행렬값 바꿈
		}
	}
}

// 행렬 출력 함수
void matrix_print(int arr[ROWS][COLS]){
	printf("------------\n");
	for(int r=0; r<ROWS; r++){
		for(int c=0; c<COLS; c++){
			printf("%d ", arr[r][c]);
		}
		printf("\n");
	}
	printf("------------\n");
}

// 메인 함수
int main(){
	int arr1[ROWS][COLS] = {{2,3,0},
							{8,9,1},
							{7,0,5}};
	int arr2[ROWS][COLS];

	matrix_transpose(arr1, arr2); // arr2 = (arr1)^T 와 같음
	matrix_print(arr1);
	matrix_print(arr2);

	return 0;
}
