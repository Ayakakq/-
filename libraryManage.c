#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//���� �鼮 �ṹ��洢����
typedef struct book
{
	int id;
	char name[20];
	char author[20];
	float price;
}bk;

static int num = 0;

 addBook(bk list[]);//����鼮
 delBook();			//ɾ���鼮
 modifyBook();		//�޸��鼮��Ϣ
 queryBook();		//��ѯ�鼮��Ϣ
 void clean();		//cls����
 int cout();		//��ѯ�����ȱ


int main()

{
	bk bookList[10];
	int cmd;
	
	printf("\n\n\n==========================��ӭ����ͼ����Ϣ����ϵͳ=======================\n\n");

	while (1) {
		printf("		  	  ������Ҫ���еĲ���:\n\n");
			printf("1.����鼮	2.ɾ���鼮	3.�޸��鼮��Ϣ	4.��ѯ�鼮��Ϣ	5.�˳�ϵͳ\n");
			scanf("%d", &cmd);
			clean();

			

			switch (cmd)
	{
	case 1:  
		addBook(bookList);
		break;
	case 2:
		delBook(bookList);
		break;
	case 3:
		modifyBook(bookList);
		break;
	case 4:
		queryBook(bookList);
		break;
	case 5:
		return;
	default:
		printf("		  	  ������������������������룡\n\n\n");
		break;

	}
	}
	

	//		ƥ���֧����

	
	//printf("%d", cmd);

}

addBook(bk templist[])				//����鼮 
{
	printf("\nnum = %d\n", num);
	printf("������Ҫ����鼮�����ƣ�");
	scanf("%s", &templist[num].name);

	printf("\n\n������Ҫ����鼮�����ߣ�");
	scanf("%s", &templist[num].author);

	printf("\n\n������Ҫ����鼮�ļ۸�");
	scanf("%f", &templist[num].price);

	templist[num].id = num;

	printf("\n\n��%s����idΪ��%d", templist[num].name,num+1);
	num++;
	printf("\n\n�����������ϵͳ~~~\n\n\n");
	int a = getch();
	clean();
	return templist;
}

delBook(bk templist[])				//ɾ���鼮 
{
	int tempn, m, tempcmd, i;

	//int n = cout(templist);
	//printf("\n%d\n", n);
	printf("ͼ���б�id���£�\n");
	for (i = 0;i <= num;i++)
	{
		if (templist[i].id >= 0 && templist[i].id < 100)
			printf("\n\n��%s��------%d", templist[i].name, templist[i].id + 1);
		else
			printf("\n");

		printf("\n");
		//templist[i].id > 0 && templist[i].id < 100 ? printf("\n\n��%s��------%d\n", templist[i].name, templist[i].id):printf("\n");
	}
	printf("\n������Ҫɾ���鼮��id��");
	scanf("%d", &m);
	//templist[ m - 1].name = "��ͼ�����¼�";
	for (i = m - 1;i < num + 1;i++)
	{
		templist[i] = templist[m];
	}
	num--;
	for (i = 0;i < num;i++)
	{
		templist[i].id--;
	}
	printf("�¼ܳɹ�\n\n�����������~");
	tempn = getch();
	clean();
}

modifyBook(bk templist[])			//�޸��鼮��Ϣ 
{
	int tempn,tempm,tempcmd,i;
	
	int n = cout(templist);
	//printf("\n%d\n", n);
	printf("ͼ���б�id���£�\n");
	for (i = 0;i <= num;i++)
	{		
		if (templist[i].id >= 0 && templist[i].id < 100)
			printf("\n\n��%s��------%d", templist[i].name, templist[i].id+1);
		else
			printf("\n");

		printf("\n");
		//templist[i].id > 0 && templist[i].id < 100 ? printf("\n\n��%s��------%d\n", templist[i].name, templist[i].id):printf("\n");
	}
	printf("\n������Ҫ�޸ĵ��鼮id��");
	scanf("%d", &tempm);
	clean();
	tempn=tempm-1;
	printf("\n������Ҫ�޸��鼮���������ݣ�");
	printf("\n1.����		2.����		3.�۸�		\n");
	scanf("%d", &tempcmd);
	clean();
	switch (tempcmd)
	{
	case 1 :
	{
		printf("\n�������µ�������");
		scanf("%s", &templist[tempn].name);
		
		printf("\n��ͼ�����������~\n\n\n�����������---");
		int aa = getch();
		clean();
		break;
	}
	case 2:
	{
		printf("\n�������µ����ߣ�");
		scanf("%s", &templist[tempn].author);
		printf("\n�����߸������~\n\n\n�����������---");
		int aa = getch();
		clean();
		break;
	}
	case 3:
	{
		printf("\n�������µļ۸�");
		scanf("%s", &templist[tempn].price);
		printf("\n��ͼ��۸�������~\n\n\n�����������---");
		int aa = getch();
		clean();
		break;
	}
	default:
		printf("��������ȷ��ָ��~");
		break;
	}
	return templist;
}

queryBook(bk templist[])			//��ѯ�鼮��Ϣ 
{
	int i;
	//int n = cout(templist);
	printf("Ŀǰ����%d���飬������Ҫ�鿴�ڼ�����", num);
	scanf("%d", &i);
	printf("\n\n-----------------------");
	printf("\n\n��id�� %d", i);
	printf("\n\n������ ��%s��", templist[i - 1].name);
	printf("\n\n���ߣ� %s", templist[i - 1].author);
	printf("\n\n�۸� %.2f\n", templist[i - 1].price);
}

void clean()
{
	system("cls");
	printf("\n\n\n");
}

int cout(bk templist[])		//�������飬���ҿ�ȱ�����bk�ṹ�����飩
{
	int i, n;

	for (i = 0; i < 10; i++)
	{
		if (templist[i].id > 0 && templist[i].id < 100)
			i++;
		else
			return i;
			

	}
}