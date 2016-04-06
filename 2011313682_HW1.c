#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5 //Input can be changed

int count=0;

int access_value(int x, int y) {
	int **input,i;
	input=(int**)calloc(LENGTH,sizeof(int*));
	for (i=0; i<LENGTH; i++) {
		input[i]=(int*)calloc(LENGTH,sizeof(int));
	}
	
	count++;
	
	//Input can be changed
	input[0][0]= 1;
	input[0][1]= 2;
	input[0][2]= 3;
	input[0][3]= 4;
	input[0][4]= 10;
	input[1][0]= 5;
	input[1][1]= 6;
	input[1][2]= 7;
	input[1][3]= 8;
	input[1][4]= 11;
	input[2][0]= 6;
	input[2][1]= 8;
	input[2][2]= 14;
	input[2][3]= 15;
	input[2][4]= 20;
	input[3][0]= 7;
	input[3][1]= 16;
	input[3][2]= 18;
	input[3][3]= 21;
	input[3][4]= 23;
	input[4][0]= 25;
	input[4][1]= 27;
	input[4][2]= 28;
	input[4][3]= 30;
	input[4][4]= 50;
	/*
	The input array is
  1   2   3   4  10 
  5   6   7   8  11 
  6   8  14  15  20 
  7  16  18  21  23 
 25  27  28  30  50 
	
	*/
	
	return input[x][y];
	
}

void cal_single(int k) {
	int i; //연산용 변수 선언
	int min; //최소 기준값으로 삼을 변수 선언
	int max=LENGTH-1; //최대 기준값으로 삼을 변수 선언
	int mid; //중간 기준값으로 삼을 변수 선언

	for(i=0; i<LENGTH; i++){

		min=0;
		
		while(min<=max){
			
			mid=((max-min)>>1)+min;
			
			if(access_value(i,mid)>k)
				max=mid-1;
			else if(access_value(i,mid)<k)
				min=mid+1;
			else{
				printf("single k(%d)값의 좌표는 (%d,%d) \n", k, i, mid);
				goto END; // k하나를 찾은 후엔 다음 연산 불필요하므로 함수 종료를 위한 goto문
			}
		}
	}
	printf("single k(%d)값이 없습니다 \n", k); //모든 연산이후에도 k값이 없을때 출력

	END:
	return;
}

void cal_all(int k) {
	int i, j; //연산용 변수 선언
	int min; // 최소 기준값으로 삼을 변수
	int max=LENGTH-1; // 최대 기준값으로 삼을 변수
	int mid; //중간값으로 삼을 변수

	for(i=0; i<LENGTH; i++){

		min=0;
		
		while(min<=max){
			
			mid=((max-min)>>1)+min; //중간값 설정 (비트연산 활용)
		
			if(access_value(i,mid)>k){
				max=mid-1;
			}
			else if(access_value(i,mid)<k)
				min=mid+1;
			else{ //중간값이 k와 같을 경우
				for(j=max-min+1 ; min<=j; min++){ //중간값이 k와 같을경우 당시의 최소값, 최대값 사이의 배열을 모두 연산하되, k보다 높은 값이 등장하면 그 좌표를 최대기준값으로 초기화 시킨후 반복문 탈출
					if(access_value(i,min)<k)
						continue;
					else if(access_value(i,min)==k)
						printf("(%d, %d) ", i, min);
					else{
						max=min-1;
						break;
					}
				}
			}
		}
	}
	return;
}


int main(void) {
	int i,j,k;

	k=7;
	printf("k is %d.\n",k);

	count=0;
	printf("\nFinding any single k\n");
	cal_single(k);
	printf("\nCount=%d\n",count);

	count=0;
	printf("\nFinding all k\n");
	cal_all(k);
	printf("\nCount=%d\n",count);

}
