// 2011313682 Youngbin Song
#include <stdio.h>

/* You can modify from here */

int Card_Value (char N1, char S1, char N2, char S2, char N3, char S3){ // �� �÷��̾� card set�� value�� integer ���·� ��ȯ�ϴ� �Լ�

int i, k=0; //������ ���� ����
int DV=0; // double value, �� �� ���ڰ� �ι� ���ð��. Ư���� ��Ȳ�� ���� �����̴�.
int c=0; //ī���� ����(�ߺ�����)�� ���� 3���� ���̽��� ������ ���� ����� ����
int a[10]={0}; // ���ڸ� �迭�ȿ� �ּ����·� �����ϹǷν� �������� ����, ī�� �ߺ����� �Ǵ��� ���ÿ� �� �� �ִ�.
int s[3]={0}; // ��������
int FS=50, ST=40, FL=30, TR=20, PA=10; // ���� ������ ������ �����Ѵ�. n*10�� ������ ������, ���� �ڸ����� high cad value�� ���Ͽ� ����� ��Ȯ�� �ϱ� ���ؼ��̴�.
//��, ���ڸ� �ϳ� ���� ������ ������ Ư���� ��� �̸��� ������ ���� �� �����Ƿ� �����Ѵ�.
int score=0; //�÷��� ���� �˻� ���� ����

a[N1-'0']++; //�Է°��� char�����̹Ƿ� 
a[N2-'0']++;
a[N3-'0']++;

for(i = 0; i < 10; i++){
	if(a[i]==0)
		c++; //�迭 �� 0�� ������ ���� ��� ī�尡 ���� ��������, �ΰ��� ���� �ϳ��� �ٸ� ��������, ��� �ٸ� �������� �Ǵ��� �� �ִ�. 
	else if(a[i]==2){
		DV=s[k]=i; // �� ī��� ���ڰ� ���� �� ī��� ���ڰ� �ٸ��鼭 ��Ʈ����Ʈ�� �Ұ��� �� ���� Ʈ���÷� ��ȯ�ؾ� �ϴµ� �� ���� high card value�� ��� ���� �ʿ��ϴ�
		k++;
	}
	else{
		s[k]=i; // ī���� ���ڰ� �迭 s�� ������������ ���ĵ�, ��������� ���� ���
		k++;
	}
}

switch(c){
case 9: //��� ī���� ���ڰ��� ���� ���, Ʈ���� �̻��� ������ ���� �� ����(�÷����� ���İ˻�)
	score = TR+s[0];
	break;
case 8: // �ΰ��� ī�尡 ���� ���ڰ��� ����, �ϳ��� �ٸ� ���. ��Ʈ����Ʈ �Ǵ� Ʈ������ ���� �� �ִ�.
	if(s[1]-s[0] == 2)
		score = ST+s[1];
	else if(s[1]-s[0] == 1){
		if(s[1]==9) // high card value�� 10�� �Ѵ� ���� �����ϱ� ���� ���ǹ�
			score = ST+s[1];
		else
			score = ST+s[1]+1;
	}
	else
		score = TR+DV; // ��Ʈ����Ʈ�� �Ұ����� ��� Ʈ���÷� �����.
	break;
case 7: // ��� �ٸ� ���ڰ��� ���� ���. ��Ʈ����Ʈ �Ǵ� �� ������� �� �ִ�.
	if(s[2]-s[1] == 2)
		score = ST+s[2];
	else if(s[2]-s[1] == 1){
		if(s[2]==9)
			score = ST+s[2];
		else
			score = ST+s[2]+1;
	}
	else if(s[1]-s[0] == 2)
		score = ST+s[1];
	else if(s[1]-s[0] == 1)
		score = ST+s[1]+1; 
	else
		score = PA+s[2]; // ��Ʈ����Ʈ�� �Ұ��� �� ���(ex>3, 6, 9), ���� �������� ���� ī�� �ϳ��� �ٲ�� �ֻ��� ���� �������.
	break;
}

if(S1==S2 && S2==S3){ //�÷��� ���θ� �˻��Ѵ�.
	if(score<FL) // ������ ��� ���� ���, �÷������� ���� ������ ������ �ִٸ� ��� �÷���+9�� ������ ��ü�Ѵ�. 
		return FL+9; 
	else
		return score+10; //�÷������� ���� ������ ������ ���� ���� �� ��Ʈ����Ʈ�� ����ε�, �÷������� �����Ѵٸ� �÷��� ��Ʈ����Ʈ�̹Ƿ�, ������ 10�� ����
}
else // �÷����� �ƴϸ� ���� ���� �״�� ��ȯ
	return score;




}
int Foker_hands(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3,char WN1, char WS1, char WN2, char WS2, char WN3, char WS3) {
	
	printf("%c%c %c%c %c%c %c%c %c%c %c%c \n", BN1, BS1, BN2, BS2, BN3, BS3,WN1, WS1, WN2, WS2, WN3, WS3 );

	if(Card_Value(BN1, BS1, BN2, BS2, BN3, BS3) < Card_Value(WN1, WS1, WN2, WS2, WN3, WS3)) // White(����)�� �̰��� ���
		return 1;
	else if(Card_Value(BN1, BS1, BN2, BS2, BN3, BS3) > Card_Value(WN1, WS1, WN2, WS2, WN3, WS3)) // Black(����)�� �̰��� ���
		return -1;
	else // ������ ���� ���
		return 0;
}


int main(void) {
	// your code goes here
	int result;
	char BN1, BS1, BN2, BS2, BN3, BS3, WN1, WS1, WN2, WS2, WN3, WS3;
	
	
	scanf("%c%c %c%c %c%c %c%c %c%c %c%c", &BN1, &BS1, &BN2, &BS2, &BN3, &BS3, &WN1, &WS1, &WN2, &WS2, &WN3, &WS3);

	result = Foker_hands(BN1, BS1, BN2, BS2, BN3, BS3,WN1, WS1, WN2, WS2, WN3, WS3);
	
	if (result==1)
		printf("White wins.\n");
	else if (result==-1)
		printf("Black wins.\n");
	else
		printf("Tie.\n");
	return 0;
}
