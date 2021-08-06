#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int totalQuestion = 0;
typedef struct {
        int nhom;
        char noidung[255];
        char dapan[5][255];
    } cauhoi;
cauhoi dsCauHoi[100];
bool isQuestion(char question[255]) 
{
    if(question[0] == '*' && question[1] == '*') return true;
    return false;
}

char * getQuestionFromLine(char * line)
{
    static char question[255];
    for(int i = 3; i < strlen(line); i++)
    {
        question[i - 3] = line[i];
    }
    question[strlen(line)] = '\0';
    return question;
}

int getGroupQuestionFromLine(char line[255])
{
    int group = 0;
    group = atoi(&line[2]);   
    return group;
}

bool isAnswer(char line[255])
{
    if(line[0] == '#') return true;
    return false;
}

char * getAnswerFromLine(char * line)
{
    static char question[255];
    for(int i = 1; i < strlen(line); i++)
    {
        question[i - 1] = line[i];
    }
    question[strlen(line)] = '\0';
    return question;
}

void xoa(char s[90],int vitrixoa)
{
	int n=strlen(s);//gán n= độ dài của chuỗi
    for(int i=vitrixoa;i<n;i++)//duyệt chuỗi từ vị trí cần xóa
     s[i]=s[i+1];
	s[n-1]='\0'; //kết thúc
}

void remove_spaces(char*s)
{
    for(int i=0;i<strlen(s);i++)
		if(s[i]==' '&& s[i+1]==' ')
		{
			xoa(s,i);
			i--;
		}
    if(s[0]==' ')
		xoa(s,0);
    if(s[strlen(s)-1]==' ')
		xoa(s,strlen(s)-1);
}

void sortQuestionByGroup(cauhoi * question)
{
    cauhoi tmp;
    for(int i = 0; i < totalQuestion; i++)
    {
        for(int j = i + 1; j < totalQuestion; j++)
        {
            if(dsCauHoi[i].nhom > dsCauHoi[j].nhom)
            {
                tmp = dsCauHoi[j];
                dsCauHoi[j] = dsCauHoi[i];
                dsCauHoi[i] = tmp;
            }
        }
    }
}
int main() 
{
    
    FILE * input = NULL;
    input = fopen("cauhoi.txt", "r");

    if(input != NULL)
    {
        char line[255];
        int numAnswer = 1;
        char * tmpQuestion;
        int totalGroup = 0;
        int tmpChuong = 0;
        int chuong[100];
        for (int i = 0; i < 100; i++)
        {
            chuong[i] = 0;
        }
        while(!feof(input))
        {
            fgets(line, sizeof(line), input);
            if(isQuestion(line))
            {
                tmpQuestion = getQuestionFromLine(line); // Fraught with problem
                remove_spaces(tmpQuestion);
                numAnswer = 1;
                tmpChuong = getGroupQuestionFromLine(line);
                if(chuong[tmpChuong] == 0)
                {
                    chuong[tmpChuong] = 1;
                    totalGroup++;
                }
                dsCauHoi[totalQuestion].nhom = tmpChuong;
                strcpy(dsCauHoi[totalQuestion].noidung, tmpQuestion);

                totalQuestion++;
            }

            if(isAnswer(line))
            {
                tmpQuestion = getAnswerFromLine(line); // Fraught with problem
                remove_spaces(tmpQuestion);
                strcpy(dsCauHoi[totalQuestion - 1].dapan[numAnswer - 1], tmpQuestion);
                numAnswer++;
            }

        }
        sortQuestionByGroup(dsCauHoi);
        printf("Tổng Số chương: %d\nSố câu hỏi: %d\n", totalGroup, totalQuestion);
        for(int i = 0; i < totalQuestion; i++)
        {
           printf("%d.  %s", i + 1, dsCauHoi[i].noidung);
           for(int j = 0; j < 5; j++)
           {
               if(strlen(dsCauHoi[i].dapan[j]) > 0 )
               {
                   printf("%c)  %s", j + 97, dsCauHoi[i].dapan[j]);
               }
           }
           printf("\n");
        }
    }
    else
    {
        printf("Loi mo file");
    }

    printf("\n");
    return 0;
}