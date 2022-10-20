#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct{
	short r;
	short c;
} element;

typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
void push_loc(StackType *s, int r, int c);
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]);

element here={1,0}, entry={1,0};
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

int main(){
	int r,c;
	StackType s;
	init_stack(&s);
	here=entry;
	while(maze[here.r][here.c] != 'x'){
		r=here.r;
		c=here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r-1, c);
		push_loc(&s, r+1, c);
		push_loc(&s, r, c-1);
		push_loc(&s, r, c+1);
	
		if(is_empty(&s)){
			printf("실패\n");
			return 0;
		}
		else here = pop(&s);
	}
	printf("성공");
	return 0;
}


void push_loc(StackType *s, int r, int c){
	if(r<0 || c<0) return;
	if(maze[r][c] != '1' && maze[r][c] != '.'){
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
	printf("\n");
	for(int r=0; r<MAZE_SIZE; r++){
		for(int c=0; c<MAZE_SIZE; c++){
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}







void init_stack(StackType *s){ 
	(s->top) = -1; // -1 : 스택이 비어있다는 의미
}

int is_empty(StackType *s){ // top이 비어있으면 True
	return ((s->top) == -1);
}

int is_full(StackType *s){ // top이 꽉 찼으면 True
	return ((s->top)==MAX_STACK_SIZE-1);
}

void push(StackType *s, element item){
	if(is_full(s)){ // 스택이 가득찼으면 비정상 강제 종료
		printf("스택 가득참!\n");
		exit(1);
	}
	s->data[++(s->top)] = item;
}

element pop(StackType *s){
	if(is_empty(s)){ // 스택이 비어있으면 비정상 강제 종료
		printf("스택이 비어있음!");
		exit(1);
	}
	return (s->data[(s->top)--]);
}

