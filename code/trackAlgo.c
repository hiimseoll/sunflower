// 기초적인 단계 알고리즘 개념 설계

#include <stdio.h>
#include <windows.h>

void sensing(); 		// 8*8 배열 온도 측정
void upperTracking();	// 상하 움직임
void lowerTracking();	// 좌우 움직임
void mode();			// 선풍기 모드

//int heatArr[8][8];
int targetI = 4;	// Centre of array;	/	target
int targetN = 3;	// Centre of array;	/	target
int maxI = 0, maxN = 0;

	int heatArr[8][8] = {
		{11, 11, 10, 12, 13, 14, 11, 15},
		{13, 11, 10, 12, 11, 14, 11, 15},
		{10, 11, 10, 12, 13, 14, 11, 15},
		{10, 11, 11, 11, 13, 18, 11, 15},
		{10, 11, 10, 12, 13, 14, 11, 15},
		{15, 12, 10, 12, 13, 12, 15, 15},
		{10, 12, 23, 12, 13, 14, 30, 12},
		{45, 11, 10, 11, 13, 11, 11, 11}
	};

int main(){

	for(;;){
		sensing();			// 세 함수 별도 Thread로 실행
		upperTracking();
		lowerTracking(); 	




		Sleep(500);
	}
}

void sensing(){
	system("cls");
	int maxTemp = 0;
	// int sensorArr[8][8] = {
	// 	{11, 11, 10, 12, 13, 14, 11, 15},
	// 	{13, 11, 10, 12, 11, 14, 11, 15},
	// 	{10, 11, 10, 12, 13, 14, 11, 15},
	// 	{10, 11, 11, 11, 13, 18, 11, 15},
	// 	{10, 11, 10, 12, 13, 14, 11, 15},
	// 	{15, 12, 10, 12, 13, 12, 15, 15},
	// 	{10, 12, 23, 12, 13, 14, 30, 12},
	// 	{10, 11, 10, 11, 13, 11, 11, 15}
	// };
	for(int i = 0; i < 8; i++){
		for(int n = 0; n < 8; n++){
			//heatArr[i][n] = sensorArr[i][n];
			printf("%d ", heatArr[i][n]);
			if(heatArr[i][n] > maxTemp){
				maxTemp = heatArr[i][n];
				maxI = i; maxN = n;
			}
		}
		printf("\n");
	}
	printf("max: %d\nmaxI: %d, maxN: %d\n", maxTemp, maxI, maxN);
	return;
}

void upperTracking(){
	int temp = heatArr[maxI][maxN];

	if(maxI > targetI){
		heatArr[maxI][maxN] = heatArr[maxI - 1][maxN];
		heatArr[maxI - 1][maxN] = temp;

		//Upper motor activate counter clockwise
		printf("Upper motor activate counter clockwise\n");
	}
	else if(maxI < targetI){
		heatArr[maxI][maxN] = heatArr[maxI + 1][maxN];
		heatArr[maxI + 1][maxN] = temp;

		//Upper motor activate clockwise
		printf("Upper motor activate clockwise\n");	
	}
	else{
		printf("Upper motor deactivate\n");
	}
	return;
}
void lowerTracking(){
	int temp = heatArr[maxI][maxN];

	if(maxN > targetN){
		heatArr[maxI][maxN] = heatArr[maxI][maxN - 1];
		heatArr[maxI][maxN - 1] = temp;

		//Lower motor activate counter clockwise
		printf("Lower motor activate counter clockwise\n");
	}
	else if(maxN < targetN){
		heatArr[maxI][maxN] = heatArr[maxI][maxN + 1];
		heatArr[maxI][maxN + 1] = temp;

		//Lower motor activate clockwise
		printf("Lower motor activate clockwise\n");	
	}
	else{
		printf("Lower motor deactivate\n");
	}
	return;
}