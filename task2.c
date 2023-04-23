#include<stdio.h>
#include<string.h>

#define SEARCH_EDU "网络空间安全学院" //待查学院
#define FILE_NAME "student.txt" //打开文件名
#define FILE_OUT "csStudent.txt" //输出文件名
#define MAXSIZE 1024

typedef struct STUDENT
{
    char name[20];//姓名
    char sno[20];//学号
    char edu[50];//学院
    char age[4];//年龄
    char sex[4];//性别
}Student;

int main()
{
    Student students;
    FILE* stuFile = fopen(FILE_NAME,"r");
    FILE* outFILE = fopen(FILE_OUT,"w");
    int i,j;
    char buf[MAXSIZE];
    //读取文件学生信息到内存
    while(!feof(stuFile))
    {
        fgets(buf,MAXSIZE,stuFile);
        sscanf(buf, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", students.name,
        students.sno,students.edu,students.age,students.sex);
        //输出指定学院的学生到文件
        if(strcmp(students.edu,SEARCH_EDU) == 0)
        {
            fprintf(outFILE,"%s:%s:%s:%s:%s\n", students.sno,
            students.name,students.age,students.sex,students.edu);
        }
    }
    fclose(stuFile);
    fclose(outFILE);
    return 0;

}
