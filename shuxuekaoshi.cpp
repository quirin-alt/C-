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
void menu()    //显示主界面
{
	printf(" ************************* 班级成绩管理系统************************ ");
    printf("\n                命令符 1  录入题目");
    printf("\n                命令符 2  查看删除题目");
	printf("\n                命令符 3  查看修改题目");
    printf("\n                命令符 4  开始做题");
    printf("\n                命令符 5  退出系统");
	printf("\n            请输入操作命令对应的命令符，并按回车确认：");
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
		default : printf("命令错误，请再次输入正确的命令符：");
			scanf("%d",&x);
			command(x);
		}
}
void entry()   //录入题目及答案
{
	char p[10];
	FILE *fp;
    int n,i=0;
	if((fp=fopen("question.txt","a"))==NULL)  //如果文件已经存在，可以追加学生信息
	{

	    if((fp=fopen("question.txt","w"))==NULL) // 文件不存在时，创建新文件，输入学生信息
		{ 
		    printf("文件打开失败！\n");
            return;
		}
	}
			fp=fopen("question.txt","a");
		printf("请输入题目及答案(用回车隔开)，如：(5*5)-6 19,如需取消则输入n：\n");
		printf("\n    题%d: ",i+1);
			scanf("%s",text.ques);
		while(strcmp(text.ques,"n"))    //当输入不是n时执行
		{
			scanf("%s",text.answer2);
			question[i]=text;
		   fprintf(fp,"%d %s %s %s ",0,question[i].ques,"0",question[i].answer2);//0 占一个结构体位，表学号无实用
		   i++;
		   printf("\n    %d: ",i+1);
			scanf("%s",text.ques);
		}
		if(i)
			printf("  题目录入成功！录入了%d题\n\n",i);
		if(!i)
			printf("  未录入题目，即将返回主界面...\n\n");
				fclose(fp);
				Sleep(1000);   //延时，真实
}
int reads(struct T question[]) // 读取学生文件中的内容
{
	FILE *fp;
    int i=0;
    if((fp=fopen("question.txt","r"))==NULL)//只读形式打不开
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
void change() //题目及答案修改
{
	FILE *fp;
    int i,n,m,count=0;
	n=reads(question);  //读取结构体个数以及读取文件
	if(!(n-1))
		printf("\n      题库为空，请先录入题目！\n\n");
	else
	{
	for(i=0;i<n-1;i++)
	 printf("\n %d: %s",i+1,question[i].ques);
    getchar();
	printf("\n请输入修改题目的题号,如1，如需取消则输入0：");
	scanf("%d",&m);
	while(m)  //题号不为零时循环
	{
		while(m>=n)
		{
			printf("无此题信息！请重新输入题号：\n");
			scanf("%d",&m);
		}
	printf("\n\n请输入修改后的题目及答案（用回车隔开）,如需取消则输入0：");
	text=question[m-1];   //保存一下question
	scanf("%s",question[m-1].ques);
	
	if(strcmp(question[m-1].ques,"0"))  //如果输入不是0
		{
			scanf("%s",question[m-1].answer2);
				 if((fp=fopen("question.txt","w"))==NULL)
	{ 
		printf("文件打开失败！\n");
        return ;
	}
	for(i=0;i<n-1;i++)
	fprintf(fp,"%d %s %s %s ",question[i].number,question[i].ques,question[i].answer1,question[i].answer2);
	getchar();
			count++;  //修改成功题数
			fclose(fp);
     printf("\n请输入修改题目的题号,如1，如需取消则输入0：");
	scanf("%d",&m);
	}
	if(!strcmp(question[m-1].ques,"0"))
	{
		if(!count)
		{
			printf("\n题目更改失败，即将返回主界面.");
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
	if(count)  //如果有更改成功
		{
		question[m-1]=text;
		printf("\n更改后：\n");
     for(i=0;i<n-1;i++)
	 printf("\n %d: %s %s",i+1,question[i].ques,question[i].answer2);
	 printf("              \n修改成功，共有%d处修改。\n\n",count);
	 Sleep(500);
		}
	if(!m&&!count)  // 如果没有修改成功
		{
			printf("题目更改失败，即将返回主界面.");		
				 for(i=0;i<10;i++)
	          {
	              printf(".");
	              Sleep(200);
	          }
		          printf("\n\n");
		}
	}
}
void exchange() //题目随机排序
{
	FILE *fp;
	int i,n,m;
	char x;
	n=reads(question);
	if(n<=10)
	{
		printf("题目数量小于10，不能进行考试！\n\n");
		Sleep(500);
	}
	else
	{
	for(i=0;i<n-1;i++)  //打乱顺序
	{
		m=rand()%(n-1);
      text=question[i];
	  question[i]=question[m];
	  question[m]=text;
	}
	if((fp=fopen("question.txt","w"))==NULL)
	{ 
		printf("文件打开失败！\n");
		Sleep(500);
        return ;
	}
	fp=fopen("question.txt","w");
	for(i=0;i<n-1;i++)
	fprintf(fp,"%d %s %s %s ",question[i].number,question[i].ques,question[i].answer1,question[i].answer2);
	getchar();
	fclose(fp);
	printf("\n考试规则如下：\n第一遍必须按照题目顺序进行作答，不得空题。题目全部答完后才可进行修改。\n");
	printf("是(y)否(n)确定答题：");
	scanf("%c",&x);
	while(x!='y'&&x!='n')  //命令输入错误则重新输入
	{
	printf("请重新输入命令符：");
	scanf("%c",&x);
	}
	if(x=='y')
	{
	printf("\n系统正在抽题，请稍后。");
	for(i=0;i<10;i++)
	{
	printf("。");
	Sleep(200);
	}
	printf("\n\n   抽选的10道题目为：\n");
	for(i=0;i<10;i++)
	 printf("\n      %d:   %s",i+1,question[i].ques);
	exam();  //考试函数
	}
	if(x=='n')
	{
		printf("已取消考试，正在返回主界面");
			for(i=0;i<10;i++)
	{
	printf("。");
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
	printf("\n第%d题：",i+1);
	printf("%s\n",question[i].ques);
	printf("answer:   ");
	scanf("%s",question[i].answer1);
	}
	getchar();
	printf("题目回答完毕，y修改，n提交：");
	scanf("%c",&m);
	while(m=='y')
	{
		printf("请输入要改的题号：");
		scanf("%d",&j);
		printf("请输入所改题目的答案：");
		scanf("%s",question[j-1].answer1);
		printf("答案修改完毕，y继续修改，n提交：");
		getchar();
	scanf("%c",&m);
			getchar();
	}
	grade=10*mark();
	printf("      系统评判中，请稍等.");
	for(i=0;i<20;i++)
	{
	printf(".");
	Sleep(200);
	}
	printf(" \n      成绩为%d",grade);
	if(grade>=60)
		printf("  合格！\n\n\n");
	if(grade<60)
		printf("  不合格！\n\n\n");
    Sleep(1000);
}
int mark()
{
	int i,n=0;
	for(i=0;i<10;i++)
		if(!strcmp(question[i].answer1,question[i].answer2))
		n++	;	//正确题目个数
	return n;
}
void del() //删除函数
{
	FILE *fp;
	int i,j,n;
	char m;
	n=reads(question);
	if((fp=fopen("question.txt","r"))==NULL||n==1)
		{
			printf("\n没有可删除的题目！\n\n");
	     return;
	   }
    else
	{
		fp=fopen("question.txt","r");
        for(i=0;!feof(fp);i++)  //提取文件
        fscanf(fp,"%d%s%s%s",&question[i].number,question[i].ques,question[i].answer1,question[i].answer2);		 
	}
    fclose(fp);
	for(i=0;i<n-1;i++)
	 printf("\n      %d:   %s",i+1,question[i].ques);
	printf("\n输入要删除的题号,0为取消删除：");
	scanf("%d",&j);
	if(j>n-1)
		printf("找不到此题目\n");
	else if(j==0)
	 {
		 printf("    即将返回主界面.");
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
	for(i=j-1;i<n-2;i++)  //后项前移
		question[i]=question[i+1];
			fp=fopen("question.txt","w");
				for(i=0;i<n-2;i++)
	fprintf(fp,"%d %s %s %s ",question[i].number,question[i].ques,question[i].answer1,question[i].answer2);
	fclose(fp);
	getchar();
	printf("删除成功！");
	printf("是否继续删除，是y，否n：");
	scanf("%c",&m);
	if(m=='y')
		del();
	if(m=='n')
	{
		printf("删除成功！\n\n");
		Sleep(500);
	}
	}
}