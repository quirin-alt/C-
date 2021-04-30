#include <bits/stdc++.h>
int sum;                     //题目数
int operation;               //四则运算or二则运算
int lnumber;                 //行题目数
int nnumber;                 //当前行题目数
int ifdecimal;               //是否有小数
int ifbrackets;              //是否有扩号
int iffile;                  //是否输出到文件
int smallest;                //最小数
int largest;                 //最大数
FILE *file;                  //文件地址
char perators[4][4] = {"+","-","*","/"}; //运算符号
void Screen () //屏幕生成函数
{
    /*随机生成数字*/
    int number_first = (rand() % (largest - smallest)) + smallest;
    int number_second = (rand() % (largest - smallest)) + smallest;
    int number_last = (rand() % (largest - smallest)) + smallest;
    /*随机生成运算符*/
    int number_operator_first = rand() % operation;
    int number_operator_second = rand() % operation;
    /*是否有括号*/
    int number_brackets = 0;
    if(ifbrackets == 1)
        number_brackets = rand() % 2;
 
    if (!ifdecimal)
    {
        printf ("%3d %s ", number_first, perators[number_operator_first]);
        if (number_brackets)
            printf ("(");
        else
            printf (" ");
        printf ("%3d %s %3d", number_second, perators[number_operator_second], number_last);
        if (number_brackets)
            printf (")");
        else
            printf (" ");
    }
    else
    {
        printf ("%5g %s ", number_first + (rand()%100) / 100.0, perators[number_operator_first]); //将整数型转换成浮点型
        if (number_brackets)
            printf ("(");
        else
            printf (" ");
        printf ("%5g %s %5g ", number_second + (rand()%100) / 100.0, perators[number_operator_second], number_last + (rand()%100) / 100.0);
        if (number_brackets)
            printf (")");
        else
            printf (" ");
    }
}
void OutputScreen() //屏幕输出函数
{
    printf ("题目生成：\n");
    while(sum--)
    {
        nnumber++;
        Screen();
        printf("=");
        if(nnumber == lnumber)
        {
            printf ("\n");
            nnumber = 0;
        }
        else
            printf ("     ");
    }
}
void OutputFile() //屏幕输出函数
{
	char file_name[100];
    printf ("请输入文件名：\n");
    scanf ("%s", file_name);
    if((file=fopen(file_name,"w"))==NULL)
    {
        printf("文件打开失败！\n");
        return ;
    }
   
    while(sum--)
    {
        nnumber++;
       
    int number_first = (rand() % (largest - smallest)) + smallest;
    int number_second = (rand() % (largest - smallest)) + smallest;
    int number_last = (rand() % (largest - smallest)) + smallest;
    /*随机生成运算符*/
    int number_operator_first = rand() % operation;
    int number_operator_second = rand() % operation;
    /*是否有括号*/
    int number_brackets = 0;
    if(ifbrackets == 1)
        number_brackets = rand() % 2;
 
    if (!ifdecimal)
    {
        fprintf (file,"%3d %s ", number_first, perators[number_operator_first]);
        if (number_brackets)
            fprintf (file,"(");
        else
            fprintf (file," ");
        fprintf (file,"%3d %s %3d", number_second, perators[number_operator_second], number_last);
        if (number_brackets)
            fprintf (file,")");
        else
            fprintf (file," ");
    }
    else
    {
        fprintf (file,"%5g %s ", number_first + (rand()%100) / 100.0, perators[number_operator_first]); //将整数型转换成浮点型
        if (number_brackets)
            fprintf (file,"(");
        else
            fprintf (file," ");
        fprintf (file,"%5g %s %5g ", number_second + (rand()%100) / 100.0, perators[number_operator_second], number_last + (rand()%100) / 100.0);
        if (number_brackets)
            fprintf (file,")");
        else
            fprintf (file," ");
    }
        fprintf(file,"=");
        if(nnumber == lnumber)
        {
            fprintf (file,"\n");
            nnumber = 0;
        }
        else
            fprintf (file,"     ");
    }
    printf("生成文件成功！！"); 
}

    void Menu () //功能选择菜单
{
    printf ("请输入生成的题目数（1-10000）：\n");
    scanf ("%d", &sum);
    if (sum < 1 || sum > 10000)
    {
        printf ("输入错误！\n");
        return;
    }
    printf ("请输入是否有乘除法：是输入1，否输入0\n");
    scanf ("%d", &operation);
    if (operation < 0 || operation > 1)
    {
        printf ("输入错误！\n");
        return;
    }
    if (operation == 1)
        operation = 4;
    else
        operation = 2;
    printf ("请输入数的范围a,b（0-30000）：a,b以空格隔开，保证a<b\n");
    scanf ("%d%d", &smallest, &largest);
    if (smallest < 0 || largest > 30000 || smallest >= largest)
    {
        printf ("输入错误！\n");
        return;
    }
    printf ("请输入是否有小数：是输入1，否输入0\n");
    
    scanf ("%d", &ifdecimal);
    if (ifdecimal < 0 || ifdecimal > 1)
    {
        printf ("输入错误！\n");
        return;
    }
    printf ("请输入是否有括号：是输入1，否输入0\n");
    scanf ("%d", &ifbrackets);
    if (ifbrackets < 0 || ifbrackets > 1)
    {
        printf ("输入错误！\n");
        return;
    }
    printf ("请输入每行的题目数（1-5）：\n");
    scanf ("%d", &lnumber);
    if (lnumber < 1 || lnumber > 5)
    {
        printf ("输入错误！\n");
        return;
    }
    printf ("请输入是否输出到文件：是输入1，否输入0\n");
    scanf ("%d", &iffile);
    if (iffile < 0 || iffile > 1)
    {
        printf ("输入错误！\n");
        return;
    }
    if(!iffile)
        OutputScreen();
    else
        OutputFile();
} 
int main()
{
	Menu(); 
}
