#include <stdio.h>
#include "loadStudentsFromFile.h"
#include "student_list.h"
#include "pause_enter.h"

extern StudentList g_list;

void loadStudentsFromFile(void)
{
    const char *filename = "../data/students.txt";

    int ret = student_list_load_from_file(&g_list, filename);
    if (ret == 0) {
        printf("学生数据已从文件加载：%s\n", filename);
    } else {
        printf("加载失败，文件不存在或格式错误。\n");
    }

    printf("按回车继续...");
    pause_enter();
}
