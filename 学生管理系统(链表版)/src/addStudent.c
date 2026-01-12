#include <stdio.h>
#include "addStudent.h"
#include "pause_enter.h"
#include "student_list.h"

extern StudentList g_list;
void addStudent(void)
{
    Student s;

    printf("请输入学号(id): ");
    if (scanf("%d", &s.id) != 1)
    {
        printf("学号输入错误！\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("按回车继续...");
        pause_enter();
        return;
    }

    printf("请输入姓名(name,不含空格): ");
    if (scanf("%31s", s.name) != 1)
    {
        printf("姓名输入错误！\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("按回车继续...");
        pause_enter();
        return;
    }

    printf("请输入年龄(age): ");
    if (scanf("%d", &s.age) != 1)
    {
        printf("年龄输入错误！\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("按回车继续...");
        pause_enter();
        return;
    }

    printf("请输入成绩(score): ");
    if (scanf("%f", &s.score) != 1)
    {
        printf("成绩输入错误！\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("按回车继续...");
        pause_enter();
        return;
    }

    printf("请输入状态(0-在读, 1-休学): ");
    if (scanf("%d", &s.status) != 1)
    {
        printf("成绩输入错误！\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("按回车继续...");
        pause_enter();
        return;
    }

    int type;

    while (1)
    {
        printf("请输入联系方式类型 (0-电话, 1-邮箱): ");
        if (scanf("%d", &type) != 1)
        {
            printf("输入错误，请输入数字 0 或 1。\n");
        }
        else if (type == 0 || type == 1)
        {
            break;
        }
        else
        {
            printf("输入错误，请输入 0 或 1。\n");
        }

        // 清空输入缓冲区
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }

    s.contact_type = type;

    if (s.contact_type == 0)
    {
        printf("请输入电话号码: ");
        scanf("%11s", s.contact.phone);
    }
    else
    {
        printf("请输入邮箱: ");
        scanf("%29s", s.contact.email);
    }

    // 清掉本次输入残留的换行符，避免 pause_enter 被“秒过”
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }


    //从这里改成放进链表
    addStudent_list(s);
    // if (ret == 0)
    // {
    //     printf("添加成功！\n");
    // }
    // else if (ret == 1)
    // {
    //     printf("添加失败：学号已存在。\n");
    // }
    // else
    // {
    //     printf("添加失败：内存不足。\n");
    // }

    printf("按回车继续...");
    pause_enter();
}