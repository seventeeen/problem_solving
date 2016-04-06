// 2011313682 Youngbin Song
#include <stdio.h>
#include <stdlib.h>

/* You can modify from here */
#define SMALL(X,Y) ((X<Y) ? X : Y);
#define BIG(X,Y) ((X<Y) ? Y : X); //두 수의 대소비교를 위해 정의

int test_cases(int X, int Y, int n, int *D, int **matrix) {
	int i=0, j=0, k=0; //연산용 세가지 변수 선언
	int arr[10000]={0}; // 모두 0으로 구성된 1차원 배열을 사용하여 matrix 배열 내 값을 정하고, 동시에 구현 가능 여부도 확인하고자 한다.
	int p; // 추후 1차원 배열을 이용한 작업수행 과정에서 계산을 위해 필요

	matrix[0][0]=X; 
	matrix[n-1][n-1]=Y; //X, Y는 matrix배열 내 고정값이므로 먼저 입력한다

	while(i<n){
		matrix[n-1-j][i]=D[i];
		i++;
		j++;
	} // 마찬가지로, Dn값 역시 고정값이므로 먼저 입력한다.

	arr[X]+=1;
	arr[Y]+=1;
	for(i=0; i<n; i++){
		arr[D[i]]+=1; 
		if(arr[D[i]]>1)
			goto INF;
	}
	//1차원 배열의 주소값을 사용해 구현가능 여부와 입력값을 정할 것이므로, 현재 입력된 값(X,Y,Dn)에 해당하는 배열주소 내에 정수 1을 저장한다.
	//예를 들어 X=5, Y=50, D1=20, D2=21, D3=22, D4=23일 경우, arr[5], arr[50], arr[20], arr[21], arr[22], arr[23]에 각각 1을 저장한다.
	//추가로, arr[D[i]]값이 1보다 크다면, 중복된 값이 입력된 것이므로 즉시 INFEASIBLE을 출력하고자 조건문을 삽입하였다.
	
	while (k<n-2){ //본격적인 배열 구성 과정. cross value(D1~Dn)를 기준으로 해서 양쪽 모두 각각 n-2번 줄을 바꿔가며 수행해야함
		i=0;
		j=0;
		while(i<n-k-1){ //cross value 위쪽을 채워나가는 과정
			p=SMALL(matrix[n-k-2-j+1][i], matrix[n-k-2-j][i+1])-1; //채우고자하는 배열의 위치 기준으로 바로 아래의 값, 바로 우측의 값보다 작아야 하므로 두 값중 더 작은값에 1을 뺀 후 p에 저장한다.
			while(1){
				if(arr[p]==0){ //만약 1차원 배열의 p주소에 0이 저장되어있다면, matrix 내 그 값이 존재하지 않는다는 것이다.
					matrix[n-k-2-j][i]=p;//따라서 p값을 matrix내에 저장한 후,
					arr[p]+=1;//arr[p]에 1을 더하고 반복문을 탈출한다. 1을 더하는 이유는, 이후에 이 값에 접근하였을때, 이미 사용된 값이라는 정보를 전달하기 위해서다.
					break;
				}
				else{ //만약 arr[p]의 값이 0이 아니라면, 그 값은 이미 사용된 값이라는 것을 알 수 있다.
					p--; //따라서 p에서 1을 빼면서 다음 값에 대한 검증과정을 다시 거친다.
					if(p<=X) //p의 값이 X보다 작거나 같을 경우, 더 이상 배열 내 채울 수 있는 수의 범위를 벗어났다는 것이다.(X가 배열의 최소값이므로)
						goto INF;//이 경우 즉시 INFEASIBLE출력을 위해 해당 레이블로 이동한다.

				}
			}
			i++;
			j++;
		}
		i=0;
		j=0;
		while(i<n-k-1){ //위의 과정과 동일한 매커니즘, 다만 시작점과 진행 방향이 위 과정과 다르므로 변수 관계를 조정하여 계산한다.
			p=BIG(matrix[i+k][n-j-1], matrix[i+1+k][n-j-2])+1;
			while(1){
				if(arr[p]==0){
					matrix[i+1+k][n-j-1]=p;
					arr[p]+=1;
					break;
				}
				else{
					p++;
					if(p>=Y)
						goto INF;

				}
			}
			i++;
			j++;
		}
		k++;
	}

	return 1; //과정 끝, 배열 출력.
INF:
	return 0; //구현 불가능, infeasible 출력.
}


/* You can modify to here */

int main(void) {
	// your code goes here
	int X,Y,n;
	int *D, **matrix,i,j;
	
	
	printf("What is X and Y?");
	scanf("%d %d",&X, &Y);
	printf("What is n?");
	scanf("%d",&n);
	D=(int*)calloc(n,sizeof(int));
	printf("What are Ds?");
	for (i=0; i<n; i++) {
		scanf("%d ",&D[i]);	
	}
	
	
	
	matrix=(int**)calloc(n,sizeof(int*));
	for (i=0; i<n; i++) {
		matrix[i]=(int*)calloc(n,sizeof(int));
	}
	
	printf("\n");
	if (test_cases(X,Y,n,D,matrix)==0) {
		printf("Infeasible!\n");
	} else {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {	
				printf("%d ", matrix[i][j]);	
			}
			printf("\n");
		}
	}
	
	
	
	
	for (i=0; i<n; i++) {
		free(matrix[i]);
	}
	free(matrix);
	free(D);
	
	
	return 0;
}
