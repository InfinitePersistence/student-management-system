#include <stdio.h>
#include "showMemoryInfo.h"
#include "student_list.h"
#include "pause_enter.h"

extern StudentList g_list;

void showMemoryInfo(void)
{
    student_list_print_memory_info(&g_list);

    printf("按回车继续...");
    pause_enter();
}
