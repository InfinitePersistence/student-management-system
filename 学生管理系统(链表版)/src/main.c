// #include <stdio.h>
// #include "app.h"
// #include "student_list.h"

// extern StudentList g_list;

// int main()
// {
// #ifdef _WIN32
//     SetConsoleOutputCP(CP_UTF8);
//     SetConsoleCP(CP_UTF8);
// #endif
//     printf("欢迎使用%s\n当前版本:%s\n", APP_NAME, APP_VERSION);

//     printf("初始化\n");
//     if (list_init(&g_list) == NULL)
//     {
//         printf("list init failed\n");
//         return 1;
//     };

//     runMenu();


//     return 0;
// }

#include <stdio.h>
#include "app.h"
#include "student_list.h"
#include "runMenu.h"

extern StudentList g_list;

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    printf("DATA_FILE = %s\n", DATA_FILE);
    printf("欢迎使用%s\n当前版本:%s\n", APP_NAME, APP_VERSION);

    if (list_init(&g_list) != 0) {
        printf("list init failed\n");
        return 1;
    }

    printf("加载历史文件中...\n");
    if (student_list_load_from_file(&g_list, DATA_FILE) == 0) {
        printf("学生数据已加载（%d 条）\n", g_list.size);
    } else {
        printf("未找到历史数据，将创建新数据。\n");
    }

    runMenu();   

    printf("退出前保存中...\n");
    if (student_list_save_to_file(&g_list, DATA_FILE) == 0) {
        printf("学生数据已保存。\n");
    } else {
        printf("保存失败！\n");
    }

    list_free(&g_list);
    return 0;
}
