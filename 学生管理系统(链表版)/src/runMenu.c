#include <stdio.h>
#include "ui.h"
#include "addStudent.h"
#include "runMenu.h"
#include "displayALLstudents.h"
#include "findStudent.h"
#include "editStudent.h"
#include "deleteStudent.h"
#include "showStatistics.h"
#include "saveStudentToFile.h"
#include "loadStudentsFromFile.h"
#include "showMemoryInfo.h"
#include "student_list.h"


void runMenu()
{

    int choice;
    do
    {
        displayMenu();
        if (scanf("%d", &choice) != 1)
        {                         // 防止输入不是数字
            printf("无法正常选择功能,请输入数字！\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
            continue;
        }
        switch (choice)
        {
        case 1:
            addStudent();          // 添加学生
            break;
        case 2:
            printf_list();  // 显示所有学生
            break;
        case 3:
            findStudent();          // 查找学生
            break;
        case 4:                     // 4. 修改学生信息
            editStudent();
            break;
        case 5:                     // 5.删除学生信息
            deleteStudent();
            break;
        case 6:                      //6. 统计信息
            showStatistics();
            break;
        case 7:                      //7. 保存数据到文件
            saveStudentToFile();
            break;
        case 8:                      //8. 从文件加载数据
            loadStudentsFromFile();
            break;
        case 9:                      //9. 内存信息
            showMemoryInfo();
            break;


        default:
            printf("无效选择，请重试。\n");
            break;
        }
    } while (choice != 0);
}