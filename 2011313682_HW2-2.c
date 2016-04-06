// 2011313682 Youngbin Song
#include <stdio.h>

/* You can modify from here */

int Card_Value (char N1, char S1, char N2, char S2, char N3, char S3){ // 한 플레이어 card set의 value를 integer 형태로 반환하는 함수

int i, k=0; //연산을 위한 변수
int DV=0; // double value, 즉 한 숫자가 두번 나올경우. 특수한 상황을 위한 변수이다.
int c=0; //카드의 구성(중복여부)에 따라 3가지 케이스로 나누기 위해 사용할 변수
int a[10]={0}; // 숫자를 배열안에 주소형태로 저장하므로써 오름차순 정렬, 카드 중복여부 판단을 동시에 할 수 있다.
int s[3]={0}; // 족보계산용
int FS=50, ST=40, FL=30, TR=20, PA=10; // 각각 족보의 점수를 지정한다. n*10의 형태인 이유는, 일의 자리수에 high cad value를 더하여 계산을 명확히 하기 위해서이다.
//또, 숫자를 하나 변경 가능한 문제의 특성상 페어 미만의 족보는 나올 수 없으므로 무시한다.
int score=0; //플러시 여부 검사 전의 점수

a[N1-'0']++; //입력값이 char형태이므로 
a[N2-'0']++;
a[N3-'0']++;

for(i = 0; i < 10; i++){
	if(a[i]==0)
		c++; //배열 내 0의 개수를 통해 모든 카드가 같은 숫자인지, 두개는 같고 하나는 다른 숫자인지, 모두 다른 숫자인지 판단할 수 있다. 
	else if(a[i]==2){
		DV=s[k]=i; // 두 카드는 숫자가 같고 한 카드는 숫자가 다르면서 스트레이트가 불가능 할 때는 트리플로 변환해야 하는데 그 때의 high card value를 얻기 위해 필요하다
		k++;
	}
	else{
		s[k]=i; // 카드의 숫자가 배열 s에 오름차순으로 정렬됨, 족보계산을 위해 사용
		k++;
	}
}

switch(c){
case 9: //모든 카드의 숫자값이 같은 경우, 트리플 이상의 족보를 만들 수 없음(플러쉬는 사후검사)
	score = TR+s[0];
	break;
case 8: // 두개의 카드가 같은 숫자값을 갖고, 하나만 다른 경우. 스트레이트 또는 트리플을 만들 수 있다.
	if(s[1]-s[0] == 2)
		score = ST+s[1];
	else if(s[1]-s[0] == 1){
		if(s[1]==9) // high card value가 10을 넘는 것을 방지하기 위한 조건문
			score = ST+s[1];
		else
			score = ST+s[1]+1;
	}
	else
		score = TR+DV; // 스트레이트가 불가능한 경우 트리플로 만든다.
	break;
case 7: // 모두 다른 숫자값을 갖는 경우. 스트레이트 또는 페어가 만들어질 수 있다.
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
		score = PA+s[2]; // 스트레이트가 불가능 할 경우(ex>3, 6, 9), 가장 높은값에 맞춰 카드 하나를 바꿔야 최상의 족보 만들어짐.
	break;
}

if(S1==S2 && S2==S3){ //플러쉬 여부를 검사한다.
	if(score<FL) // 문양이 모두 같은 경우, 플러쉬보다 낮은 점수를 가지고 있다면 즉시 플러쉬+9의 점수로 대체한다. 
		return FL+9; 
	else
		return score+10; //플러쉬보다 높은 점수를 가지고 있을 경우는 곧 스트레이트인 경우인데, 플러쉬까지 만족한다면 플러쉬 스트레이트이므로, 점수에 10을 더함
}
else // 플러쉬가 아니면 기존 점수 그대로 반환
	return score;




}
int Foker_hands(char BN1, char BS1, char BN2, char BS2, char BN3, char BS3,char WN1, char WS1, char WN2, char WS2, char WN3, char WS3) {
	
	printf("%c%c %c%c %c%c %c%c %c%c %c%c \n", BN1, BS1, BN2, BS2, BN3, BS3,WN1, WS1, WN2, WS2, WN3, WS3 );

	if(Card_Value(BN1, BS1, BN2, BS2, BN3, BS3) < Card_Value(WN1, WS1, WN2, WS2, WN3, WS3)) // White(후자)가 이겼을 경우
		return 1;
	else if(Card_Value(BN1, BS1, BN2, BS2, BN3, BS3) > Card_Value(WN1, WS1, WN2, WS2, WN3, WS3)) // Black(전자)가 이겼을 경우
		return -1;
	else // 점수가 같을 경우
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
