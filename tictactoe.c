#include <stdio.h>

int slash(int n);		//줄 함수
void plane();			//좌표 입력받는 함수
int coin(int n);		//승,패,무승부 판정 함수

int tic[10][10]={0};
int k,l,count=0;	//전역 변수 선언
int cont1=0,cot1=0,cont2=0,cot2=0,con1=0,con2=0,con_1=0,con_2=0;

int main()
{
	int n;
	int i=0,j,k;
	int p;
	printf("Enter game board size: ");
	scanf("%d", &n);
	slash(n);				//줄 출력
	for(j=0; j<n; j++)		//현 게임판 출력하는 반복문
	{
		for (k=0; k<n; k++)
		{
			printf(" %c", tic[j][k]);
			for(i=1; i<n; i++)
			{
				printf(" | %c", tic[j][i]);
			}
			break;
		}
		printf("\n");
		slash(n);
	}
	while (1)		//게임 끝날때까지 반복
	{
		plane();		//좌표 입력받기
		slash(n);		//입력받은 좌표 출력
		for(j=0; j<n; j++)
		{
			for (k=0; k<n; k++)
			{
				printf(" %c", tic[j][k]);
				for(i=1; i<n; i++)
				{
					printf(" | %c", tic[j][i]);
				}
				break;
			}
			printf("\n");
			slash(n);
		}
		coin (n);
		if (cont1==n+1 || cont2==n+1)
			break;
	}
	return 0;
}

int slash(int n)				//줄 출력 함수
{
	int i;
	printf("---");
	for(i=0; i<n-1; i++)
	{
		printf("|---");
	}
	printf("\n");
}
void plane()					//좌표 입력받는 함수
{
	if (count==0)				//x먼저 입력받기
	{
		printf("X의 위치:");
		scanf("%d %d", &k, &l);
		if(tic[k][l]==0)		//빈칸이면 좌표에 값 저장
		{
			tic[k][l]='X';
			count=1;
		}
		else
			printf("잘못된 위치입니다.\n");		//빈칸이 아니면 재입력
	}
	else
	{
		printf("O의 위치:");		//x입력후 o입력하는걸 반복
		scanf("%d %d", &k, &l);
		if(tic[k][l]==0)
		{
			tic[k][l]='O';			//빈칸이면 좌표에 값 저장
			count=0;
		}
		else
			printf("잘못된 위치입니다.\n");		//빈칸이 아니면 재입력
	}
}

int coin(int n)				//승, 패, 무승부 판정함수
{
	int j=0,i=0,p=0;
	cont1=cont2=cot1=cot2=con1=con2=con_1=con_2=0;
	for(j=0; j<n; j++)		
	{
		for (i=0; i<n-1; i++)				//가로줄이 같으면 count값 증가
		{
			if (tic[j][i]==tic[j][i+1] && tic[j][i]!=0)
			{
				if (tic[j][i]=='X')
					cont1++;
				else if(tic[j][i]=='O')
					cont2++;
			}
			else
				break;
		}
		for (i=0; i<n-1; i++)
		{
			if (tic[i][j]==tic[i+1][j] && tic[i][j]!=0)		//세로줄이 같으면 cot값 증가
			{
				if (tic[i][j]=='X')
					cot1++;
				else if(tic[i][j]=='O')
					cot2++;
			}
			else
				break;
		}
	}
	while(1)		//while문으로 대각 판정
	{
		j=0,i=n-1;
		while(1)
		{
			if (tic[j][i]==tic[j+1][i-1] && tic[j][i]!=0)	//오른쪽 위부터 왼쪽 아래까지 같으면 con값 증가
			{
				if (tic[j][i]=='X')
					con1++;
				else if(tic[j][i]=='O')
					con2++;
			}
			else if(i==0)
				break;
			else
				break;
			j++,i--;
		}
		j=0,i=0;
		while(1)
		{
			if (tic[j][i]==tic[j+1][i+1] && tic[j][i]!=0)	//왼쪽 위부터 오른쪽 아래까지 같으면 con_값 증가
			{
				if (tic[j][i]=='X')
					con_1++;
				else if(tic[j][i]=='O')
					con_2++;
			}
			else if(i==n-1)
				break;
			else
				break;
			i++,j++;
		}
		break;
	}
	for(j=0; j<n; j++)				//무승부
	{
		for(i=0; i<n; i++)
		{
			if (tic[j][i]!=0)
				p++;
			else
				p=0;
		}
	}
	
	if (cont1==n-1 || cot1==n-1 || con1==n-1 || con_1==n-1)
	{
		printf("결과: X의 승리\n");    //X win
		cont1=cot1=con1=con_1=n+1;
	}
	else if(cont2==n-1 || cot2==n-1 || con2==n-1 || con_2==n-1)
	{
		printf("결과: O의 승리\n");     //O win
		cont2=cot2=con2=con_2=n+1;
	}
	else if(p==n*n)
	{
		printf("결과: 무승부\n");    //draw
		cont1=n+1;
	}
}
