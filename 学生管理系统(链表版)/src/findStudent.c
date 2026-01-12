#include <stdio.h>
#include "findStudent.h"
#include "pause_enter.h"
#include "student_list.h"

extern StudentList g_list;

void findStudent(void)
{
    int id;

    printf("请输入要查找的学号(id): ");
    if (scanf("%d", &id) != 1)
    {
        printf("输入错误，请输入数字。\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("按回车继续...");
        pause_enter();
        return;
    }

    // 清掉本次输入后的换行，避免 pause_enter 秒过
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }

    StudentNode*p = findStudent_list(&g_list, id);
    if (p == NULL)
    {
        printf("未找到学号为 %d 的学生。\n", id);
    }
    else
    {
        Student s = p->data; // 读出那条记录
        printf("找到学生：\n");
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Score: %.2f\n", s.score);
        printf("Status: %s\n",
               s.status == ACTIVE ? "ACTIVE" : "INACTIVE");

        if (s.contact_type == 0)
        {
            printf("Phone: %s\n", s.contact.phone);
        }
        else
        {
            printf("Email: %s\n", s.contact.email);
        }
    }

    printf("按回车继续...");
    pause_enter();
}
