#include <bits/stdc++.h>
int sum;                     //��Ŀ��
int operation;               //��������or��������
int lnumber;                 //����Ŀ��
int nnumber;                 //��ǰ����Ŀ��
int ifdecimal;               //�Ƿ���С��
int ifbrackets;              //�Ƿ�������
int iffile;                  //�Ƿ�������ļ�
int smallest;                //��С��
int largest;                 //�����
FILE *file;                  //�ļ���ַ
char perators[4][4] = {"+","-","*","/"}; //�������
void Screen () //��Ļ���ɺ���
{
    /*�����������*/
    int number_first = (rand() % (largest - smallest)) + smallest;
    int number_second = (rand() % (largest - smallest)) + smallest;
    int number_last = (rand() % (largest - smallest)) + smallest;
    /*������������*/
    int number_operator_first = rand() % operation;
    int number_operator_second = rand() % operation;
    /*�Ƿ�������*/
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
        printf ("%5g %s ", number_first + (rand()%100) / 100.0, perators[number_operator_first]); //��������ת���ɸ�����
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
void OutputScreen() //��Ļ�������
{
    printf ("��Ŀ���ɣ�\n");
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
void OutputFile() //��Ļ�������
{
	char file_name[100];
    printf ("�������ļ�����\n");
    scanf ("%s", file_name);
    if((file=fopen(file_name,"w"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        return ;
    }
   
    while(sum--)
    {
        nnumber++;
       
    int number_first = (rand() % (largest - smallest)) + smallest;
    int number_second = (rand() % (largest - smallest)) + smallest;
    int number_last = (rand() % (largest - smallest)) + smallest;
    /*������������*/
    int number_operator_first = rand() % operation;
    int number_operator_second = rand() % operation;
    /*�Ƿ�������*/
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
        fprintf (file,"%5g %s ", number_first + (rand()%100) / 100.0, perators[number_operator_first]); //��������ת���ɸ�����
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
    printf("�����ļ��ɹ�����"); 
}

    void Menu () //����ѡ��˵�
{
    printf ("���������ɵ���Ŀ����1-10000����\n");
    scanf ("%d", &sum);
    if (sum < 1 || sum > 10000)
    {
        printf ("�������\n");
        return;
    }
    printf ("�������Ƿ��г˳�����������1��������0\n");
    scanf ("%d", &operation);
    if (operation < 0 || operation > 1)
    {
        printf ("�������\n");
        return;
    }
    if (operation == 1)
        operation = 4;
    else
        operation = 2;
    printf ("���������ķ�Χa,b��0-30000����a,b�Կո��������֤a<b\n");
    scanf ("%d%d", &smallest, &largest);
    if (smallest < 0 || largest > 30000 || smallest >= largest)
    {
        printf ("�������\n");
        return;
    }
    printf ("�������Ƿ���С����������1��������0\n");
    
    scanf ("%d", &ifdecimal);
    if (ifdecimal < 0 || ifdecimal > 1)
    {
        printf ("�������\n");
        return;
    }
    printf ("�������Ƿ������ţ�������1��������0\n");
    scanf ("%d", &ifbrackets);
    if (ifbrackets < 0 || ifbrackets > 1)
    {
        printf ("�������\n");
        return;
    }
    printf ("������ÿ�е���Ŀ����1-5����\n");
    scanf ("%d", &lnumber);
    if (lnumber < 1 || lnumber > 5)
    {
        printf ("�������\n");
        return;
    }
    printf ("�������Ƿ�������ļ���������1��������0\n");
    scanf ("%d", &iffile);
    if (iffile < 0 || iffile > 1)
    {
        printf ("�������\n");
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
