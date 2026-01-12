#include <stdio.h>
#include "saveStudentToFile.h"
#include "student_list.h"
#include "pause_enter.h"

extern StudentList g_list;

void saveStudentToFile(void)
{
    const char *filename = "../data/students.txt";

    int ret = student_list_save_to_file(&g_list, filename);
    if (ret == 0) {
        printf("学生数据已保存到文件：%s\n", filename);
    } else {
        printf("保存失败，无法写入文件。\n");
    }

    printf("按回车继续...");
    pause_enter();
}
