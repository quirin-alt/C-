#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
	void menu();
	void command(int x);
	void entry();
	void change();
	void exchange();
	void exam();
	void del();
	int mark();
	int reads(struct T str[]);
struct T
{
	int number;
	char ques[10];
	char answer1[5];
	char answer2[5];
};
struct T question[100];
struct T text;
int main()
{
	while(1)
	{
		int y;
		menu(); 
		scanf("%d",&y);
	    command(y);
	}
	return 0;
}
void menu()    //��ʾ������
{
	printf(" ************************* �༶�ɼ�����ϵͳ************************ ");
    printf("\n                ����� 1  ¼����Ŀ");
    printf("\n                ����� 2  �鿴ɾ����Ŀ");
	printf("\n                ����� 3  �鿴�޸���Ŀ");
    printf("\n                ����� 4  ��ʼ����");
    printf("\n                ����� 5  �˳�ϵͳ");
	printf("\n            ��������������Ӧ��������������س�ȷ�ϣ�");
}
void command(int x)
{
	switch(x)
		{
		case 1:entry();break;
		case 2:del();break;
		case 3:change();break;
        case 4:exchange();break;
	    case 5:exit(0);break;
		default : printf("����������ٴ�������ȷ���������");
			scanf("%d",&x);
			command(x);
		}
}
void entry()   //¼����Ŀ����
{
	char p[10];
	FILE *fp;
    int n,i=0;
	if((fp=fopen("question.txt","a"))==NULL)  //����ļ��Ѿ����ڣ�����׷��ѧ����Ϣ
	{

	    if((fp=fopen("question.txt","w"))==NULL) // �ļ�������ʱ���������ļ�������ѧ����Ϣ
		{ 
		    printf("�ļ���ʧ�ܣ�\n");
            return;
		}
	}
			fp=fopen("question.txt","a");
		printf("��������Ŀ����(�ûس�����)���磺(5*5)-6 19,����ȡ��������n��\n");
		printf("\n    ��%d: ",i+1);
			scanf("%s",text.ques);
		while(strcmp(text.ques,"n"))    //�����벻��nʱִ��
		{
			scanf("%s",text.answer2);
			question[i]=text;
		   fprintf(fp,"%d %s %s %s ",0,question[i].ques,"0",question[i].answer2);//0 ռһ���ṹ��λ����ѧ����ʵ��
		   i++;
		   printf("\n    %d: ",i+1);
			scanf("%s",text.ques);
		}
		if(i)
			printf("  ��Ŀ¼��ɹ���¼����%d��\n\n",i);
		if(!i)
			printf("  δ¼����Ŀ����������������...\n\n");
				fclose(fp);
				Sleep(1000);   //��ʱ����ʵ
}
int reads(struct T question[]) // ��ȡѧ���ļ��е�����
{
	FILE *fp;
    int i=0;
    if((fp=fopen("question.txt","r"))==NULL)//ֻ����ʽ�򲻿�
        return 1;
    else
	{
		fp=fopen("question.txt","r");
        for(i=0;!feof(fp);i++)
        fscanf(fp,"%d%s%s%s",&question[i].number,question[i].ques,question[i].answer1,question[i].answer2);		 
	}
    fclose(fp);
    return i;
}
void change() //��Ŀ�����޸�
{
	FILE *fp;
    int i,n,m,count=0;
	n=reads(question);  //��ȡ�ṹ������Լ���ȡ�ļ�
	if(!(n-1))
		printf("\n      ���Ϊ�գ�����¼����Ŀ��\n\n");
	else
	{
	for(i=0;i<n-1;i++)
	 printf("\n %d: %s",i+1,question[i].ques);
    getchar();
	printf("\n�������޸���Ŀ�����,��1������ȡ��������0��");
	scanf("%d",&m);
	while(m)  //��Ų�Ϊ��ʱѭ��
	{
		while(m>=n)
		{
			printf("�޴�����Ϣ��������������ţ�\n");
			scanf("%d",&m);
		}
	printf("\n\n�������޸ĺ����Ŀ���𰸣��ûس�������,����ȡ��������0��");
	text=question[m-1];   //����һ��question
	scanf("%s",question[m-1].ques);
	
	if(strcmp(question[m-1].ques,"0"))  //������벻��0
		{
			scanf("%s",question[m-1].answer2);
				 if((fp=fopen("question.txt","w"))==NULL)
	{ 
		printf("�ļ���ʧ�ܣ�\n");
        return ;
	}
	for(i=0;i<n-1;i++)
	fprintf(fp,"%d %s %s %s ",question[i].number,question[i].ques,question[i].answer1,question[i].answer2);
	getchar();
			count++;  //�޸ĳɹ�����
			fclose(fp);
     printf("\n�������޸���Ŀ�����,��1������ȡ��������0��");
	scanf("%d",&m);
	}
	if(!strcmp(question[m-1].ques,"0"))
	{
		if(!count)
		{
			printf("\n��Ŀ����ʧ�ܣ���������������.");
				 for(i=0;i<10;i++)
	{
	printf(".");
	Sleep(200);
	}
		 printf("\n\n");
			break;
		}
	}
	}
	if(count)  //����и��ĳɹ�
		{
		question[m-1]=text;
		printf("\n���ĺ�\n");
     for(i=0;i<n-1;i++)
	 printf("\n %d: %s %s",i+1,question[i].ques,question[i].answer2);
	 printf("              \n�޸ĳɹ�������%d���޸ġ�\n\n",count);
	 Sleep(500);
		}
	if(!m&&!count)  // ���û���޸ĳɹ�
		{
			printf("��Ŀ����ʧ�ܣ���������������.");		
				 for(i=0;i<10;i++)
	          {
	              printf(".");
	              Sleep(200);
	          }
		          printf("\n\n");
		}
	}
}
void exchange() //��Ŀ�������
{
	FILE *fp;
	int i,n,m;
	char x;
	n=reads(question);
	if(n<=10)
	{
		printf("��Ŀ����С��10�����ܽ��п��ԣ�\n\n");
		Sleep(500);
	}
	else
	{
	for(i=0;i<n-1;i++)  //����˳��
	{
		m=rand()%(n-1);
      text=question[i];
	  question[i]=question[m];
	  question[m]=text;
	}
	if((fp=fopen("question.txt","w"))==NULL)
	{ 
		printf("�ļ���ʧ�ܣ�\n");
		Sleep(500);
        return ;
	}
	fp=fopen("question.txt","w");
	for(i=0;i<n-1;i++)
	fprintf(fp,"%d %s %s %s ",question[i].number,question[i].ques,question[i].answer1,question[i].answer2);
	getchar();
	fclose(fp);
	printf("\n���Թ������£�\n��һ����밴����Ŀ˳��������𣬲��ÿ��⡣��Ŀȫ�������ſɽ����޸ġ�\n");
	printf("��(y)��(n)ȷ�����⣺");
	scanf("%c",&x);
	while(x!='y'&&x!='n')  //���������������������
	{
	printf("�����������������");
	scanf("%c",&x);
	}
	if(x=='y')
	{
	printf("\nϵͳ���ڳ��⣬���Ժ�");
	for(i=0;i<10;i++)
	{
	printf("��");
	Sleep(200);
	}
	printf("\n\n   ��ѡ��10����ĿΪ��\n");
	for(i=0;i<10;i++)
	 printf("\n      %d:   %s",i+1,question[i].ques);
	exam();  //���Ժ���
	}
	if(x=='n')
	{
		printf("��ȡ�����ԣ����ڷ���������");
			for(i=0;i<10;i++)
	{
	printf("��");
	Sleep(200);
	}
		printf("\n\n");
		return;
	}
	}
}
void exam()
{
	int i,j,grade;
	char m;
	for(i=0;i<10;i++)
	{
	printf("\n��%d�⣺",i+1);
	printf("%s\n",question[i].ques);
	printf("answer:   ");
	scanf("%s",question[i].answer1);
	}
	getchar();
	printf("��Ŀ�ش���ϣ�y�޸ģ�n�ύ��");
	scanf("%c",&m);
	while(m=='y')
	{
		printf("������Ҫ�ĵ���ţ�");
		scanf("%d",&j);
		printf("������������Ŀ�Ĵ𰸣�");
		scanf("%s",question[j-1].answer1);
		printf("���޸���ϣ�y�����޸ģ�n�ύ��");
		getchar();
	scanf("%c",&m);
			getchar();
	}
	grade=10*mark();
	printf("      ϵͳ�����У����Ե�.");
	for(i=0;i<20;i++)
	{
	printf(".");
	Sleep(200);
	}
	printf(" \n      �ɼ�Ϊ%d",grade);
	if(grade>=60)
		printf("  �ϸ�\n\n\n");
	if(grade<60)
		printf("  ���ϸ�\n\n\n");
    Sleep(1000);
}
int mark()
{
	int i,n=0;
	for(i=0;i<10;i++)
		if(!strcmp(question[i].answer1,question[i].answer2))
		n++	;	//��ȷ��Ŀ����
	return n;
}
void del() //ɾ������
{
	FILE *fp;
	int i,j,n;
	char m;
	n=reads(question);
	if((fp=fopen("question.txt","r"))==NULL||n==1)
		{
			printf("\nû�п�ɾ������Ŀ��\n\n");
	     return;
	   }
    else
	{
		fp=fopen("question.txt","r");
        for(i=0;!feof(fp);i++)  //��ȡ�ļ�
        fscanf(fp,"%d%s%s%s",&question[i].number,question[i].ques,question[i].answer1,question[i].answer2);		 
	}
    fclose(fp);
	for(i=0;i<n-1;i++)
	 printf("\n      %d:   %s",i+1,question[i].ques);
	printf("\n����Ҫɾ�������,0Ϊȡ��ɾ����");
	scanf("%d",&j);
	if(j>n-1)
		printf("�Ҳ�������Ŀ\n");
	else if(j==0)
	 {
		 printf("    ��������������.");
		 for(i=0;i<10;i++)
	{
	printf(".");
	Sleep(200);
	}
		 printf("\n\n");
        return;
     }
	else
	{
	for(i=j-1;i<n-2;i++)  //����ǰ��
		question[i]=question[i+1];
			fp=fopen("question.txt","w");
				for(i=0;i<n-2;i++)
	fprintf(fp,"%d %s %s %s ",question[i].number,question[i].ques,question[i].answer1,question[i].answer2);
	fclose(fp);
	getchar();
	printf("ɾ���ɹ���");
	printf("�Ƿ����ɾ������y����n��");
	scanf("%c",&m);
	if(m=='y')
		del();
	if(m=='n')
	{
		printf("ɾ���ɹ���\n\n");
		Sleep(500);
	}
	}
}