// 2011313682 Youngbin Song
#include <stdio.h>
#include <stdlib.h>

/* You can modify from here */
#define SMALL(X,Y) ((X<Y) ? X : Y);
#define BIG(X,Y) ((X<Y) ? Y : X); //�� ���� ��Һ񱳸� ���� ����

int test_cases(int X, int Y, int n, int *D, int **matrix) {
	int i=0, j=0, k=0; //����� ������ ���� ����
	int arr[10000]={0}; // ��� 0���� ������ 1���� �迭�� ����Ͽ� matrix �迭 �� ���� ���ϰ�, ���ÿ� ���� ���� ���ε� Ȯ���ϰ��� �Ѵ�.
	int p; // ���� 1���� �迭�� �̿��� �۾����� �������� ����� ���� �ʿ�

	matrix[0][0]=X; 
	matrix[n-1][n-1]=Y; //X, Y�� matrix�迭 �� �������̹Ƿ� ���� �Է��Ѵ�

	while(i<n){
		matrix[n-1-j][i]=D[i];
		i++;
		j++;
	} // ����������, Dn�� ���� �������̹Ƿ� ���� �Է��Ѵ�.

	arr[X]+=1;
	arr[Y]+=1;
	for(i=0; i<n; i++){
		arr[D[i]]+=1; 
		if(arr[D[i]]>1)
			goto INF;
	}
	//1���� �迭�� �ּҰ��� ����� �������� ���ο� �Է°��� ���� ���̹Ƿ�, ���� �Էµ� ��(X,Y,Dn)�� �ش��ϴ� �迭�ּ� ���� ���� 1�� �����Ѵ�.
	//���� ��� X=5, Y=50, D1=20, D2=21, D3=22, D4=23�� ���, arr[5], arr[50], arr[20], arr[21], arr[22], arr[23]�� ���� 1�� �����Ѵ�.
	//�߰���, arr[D[i]]���� 1���� ũ�ٸ�, �ߺ��� ���� �Էµ� ���̹Ƿ� ��� INFEASIBLE�� ����ϰ��� ���ǹ��� �����Ͽ���.
	
	while (k<n-2){ //�������� �迭 ���� ����. cross value(D1~Dn)�� �������� �ؼ� ���� ��� ���� n-2�� ���� �ٲ㰡�� �����ؾ���
		i=0;
		j=0;
		while(i<n-k-1){ //cross value ������ ä�������� ����
			p=SMALL(matrix[n-k-2-j+1][i], matrix[n-k-2-j][i+1])-1; //ä������ϴ� �迭�� ��ġ �������� �ٷ� �Ʒ��� ��, �ٷ� ������ ������ �۾ƾ� �ϹǷ� �� ���� �� �������� 1�� �� �� p�� �����Ѵ�.
			while(1){
				if(arr[p]==0){ //���� 1���� �迭�� p�ּҿ� 0�� ����Ǿ��ִٸ�, matrix �� �� ���� �������� �ʴ´ٴ� ���̴�.
					matrix[n-k-2-j][i]=p;//���� p���� matrix���� ������ ��,
					arr[p]+=1;//arr[p]�� 1�� ���ϰ� �ݺ����� Ż���Ѵ�. 1�� ���ϴ� ������, ���Ŀ� �� ���� �����Ͽ�����, �̹� ���� ���̶�� ������ �����ϱ� ���ؼ���.
					break;
				}
				else{ //���� arr[p]�� ���� 0�� �ƴ϶��, �� ���� �̹� ���� ���̶�� ���� �� �� �ִ�.
					p--; //���� p���� 1�� ���鼭 ���� ���� ���� ���������� �ٽ� ��ģ��.
					if(p<=X) //p�� ���� X���� �۰ų� ���� ���, �� �̻� �迭 �� ä�� �� �ִ� ���� ������ ����ٴ� ���̴�.(X�� �迭�� �ּҰ��̹Ƿ�)
						goto INF;//�� ��� ��� INFEASIBLE����� ���� �ش� ���̺�� �̵��Ѵ�.

				}
			}
			i++;
			j++;
		}
		i=0;
		j=0;
		while(i<n-k-1){ //���� ������ ������ ��Ŀ����, �ٸ� �������� ���� ������ �� ������ �ٸ��Ƿ� ���� ���踦 �����Ͽ� ����Ѵ�.
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

	return 1; //���� ��, �迭 ���.
INF:
	return 0; //���� �Ұ���, infeasible ���.
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
