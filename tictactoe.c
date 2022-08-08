#include <stdio.h>

int slash(int n);		//�� �Լ�
void plane();			//��ǥ �Է¹޴� �Լ�
int coin(int n);		//��,��,���º� ���� �Լ�

int tic[10][10]={0};
int k,l,count=0;	//���� ���� ����
int cont1=0,cot1=0,cont2=0,cot2=0,con1=0,con2=0,con_1=0,con_2=0;

int main()
{
	int n;
	int i=0,j,k;
	int p;
	scanf("%d", &n);
	slash(n);				//�� ���
	for(j=0; j<n; j++)		//�� ������ ����ϴ� �ݺ���
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
	while (1)		//���� ���������� �ݺ�
	{
		plane();		//��ǥ �Է¹ޱ�
		slash(n);		//�Է¹��� ��ǥ ���
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

int slash(int n)				//�� ��� �Լ�
{
	int i;
	printf("---");
	for(i=0; i<n-1; i++)
	{
		printf("|---");
	}
	printf("\n");
}
void plane()					//��ǥ �Է¹޴� �Լ�
{
	if (count==0)				//x���� �Է¹ޱ�
	{
		printf("X�� ��ġ:");
		scanf("%d %d", &k, &l);
		if(tic[k][l]==0)		//��ĭ�̸� ��ǥ�� �� ����
		{
			tic[k][l]='X';
			count=1;
		}
		else
			printf("�߸��� ��ġ�Դϴ�.\n");		//��ĭ�� �ƴϸ� ���Է�
	}
	else
	{
		printf("O�� ��ġ:");		//x�Է��� o�Է��ϴ°� �ݺ�
		scanf("%d %d", &k, &l);
		if(tic[k][l]==0)
		{
			tic[k][l]='O';			//��ĭ�̸� ��ǥ�� �� ����
			count=0;
		}
		else
			printf("�߸��� ��ġ�Դϴ�.\n");		//��ĭ�� �ƴϸ� ���Է�
	}
}

int coin(int n)				//��, ��, ���º� �����Լ�
{
	int j=0,i=0,p=0;
	cont1=cont2=cot1=cot2=con1=con2=con_1=con_2=0;
	for(j=0; j<n; j++)		
	{
		for (i=0; i<n-1; i++)				//�������� ������ count�� ����
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
			if (tic[i][j]==tic[i+1][j] && tic[i][j]!=0)		//�������� ������ cot�� ����
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
	while(1)		//while������ �밢 ����
	{
		j=0,i=n-1;
		while(1)
		{
			if (tic[j][i]==tic[j+1][i-1] && tic[j][i]!=0)	//������ ������ ���� �Ʒ����� ������ con�� ����
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
			if (tic[j][i]==tic[j+1][i+1] && tic[j][i]!=0)	//���� ������ ������ �Ʒ����� ������ con_�� ����
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
	for(j=0; j<n; j++)				//���º�
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
		printf("���:X�� �¸�\n");
		cont1=cot1=con1=con_1=n+1;
	}
	else if(cont2==n-1 || cot2==n-1 || con2==n-1 || con_2==n-1)
	{
		printf("O�� �¸��Դϴ�.\n");
		cont2=cot2=con2=con_2=n+1;
	}
	else if(p==n*n)
	{
		printf("���: ���º�\n");
		cont1=n+1;
	}
}