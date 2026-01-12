#include <stdio.h>
#include "deleteStudent.h"
#include "pause_enter.h"
#include "student_list.h"

extern StudentList g_list;

void deleteStudent(void)
{
    int id;

    printf("请输入要删除的学生学号(id): ");
    if (scanf("%d", &id) != 1) {
        printf("输入错误。\n");
        int ch; 
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("按回车继续...");
        pause_enter();
        return;
    }

    // 清掉换行，避免 pause_enter 秒过
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}


    //从这里修改成链表的删除功能
    if(delStudent_list(&g_list, id)){
        printf("删除失败!");
        return;
    }

    printf("删除成功!");
    printf("按回车继续...");
    pause_enter();
}
