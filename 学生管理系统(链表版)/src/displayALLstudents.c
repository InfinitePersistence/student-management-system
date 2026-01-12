#include <stdio.h>
#include "displayALLstudents.h"
#include "pause_enter.h"
#include "student_list.h"

extern StudentList g_list;

void displayALLstudents(void)
{
    printf_list();
    printf("按回车继续...");
    pause_enter();
}
