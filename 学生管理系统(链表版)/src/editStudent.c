#include <stdio.h>
#include "editStudent.h"
#include "pause_enter.h"
#include "student_list.h"

extern StudentList g_list;

void editStudent(void)
{
    int id;

    printf("请输入要修改的学生学号(id): ");
    if (scanf("%d", &id) != 1) {
        printf("输入错误。\n");
        int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("按回车继续...");
        pause_enter();
        return;
    }

    // 清掉换行
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    StudentNode*p = findStudent_list(&g_list, id);
    if (p == NULL) {
        printf("未找到学号为 %d 的学生。\n", id);
        printf("按回车继续...");
        pause_enter();
        return;
    }

    printf("找到学生，重新输入该学生的信息。\n");

    Student new_s;
    new_s.id = id;  // 学号一般不允许修改，沿用原 id

    printf("姓名: ");
    scanf("%19s", new_s.name);

    printf("年龄: ");
    scanf("%d", &new_s.age);

    printf("成绩: ");
    scanf("%f", &new_s.score);

    printf("状态 (0-ACTIVE, 1-INACTIVE): ");
    scanf("%d", (int *)&new_s.status);

    printf("联系方式类型 (0-电话, 1-邮箱): ");
    scanf("%d", &new_s.contact_type);

    if (new_s.contact_type == 0) {
        printf("电话: ");
        scanf("%11s", new_s.contact.phone);
    } else {
        printf("邮箱: ");
        scanf("%29s", new_s.contact.email);
    }

    // 清掉残留换行，避免 pause_enter 秒过
    while ((ch = getchar()) != '\n' && ch != EOF) {}


    //从这里修改成链表
    int ret = editStudent_list(&g_list, id, new_s);
    if (ret == 0) printf("修改成功。\n");
    else printf("修改失败。\n");

    printf("按回车继续...");
    pause_enter();
}
