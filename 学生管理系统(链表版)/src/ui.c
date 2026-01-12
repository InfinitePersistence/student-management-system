#include <stdio.h>
#include "ui.h"
#include "version.h"

void displayMenu(void) {
  printf("\n═══════════════════════════════════════\n");
    printf("     学生信息管理系统 (%s)\n",APP_VERSION);
    printf("═══════════════════════════════════════\n");
    printf("1. 添加学生\n");
    printf("2. 显示所有学生\n");
    printf("3. 查找学生\n");
    printf("4. 修改学生信息\n");
    printf("5. 删除学生\n");
    printf("6. 统计信息\n");
    printf("7. 保存数据到文件\n");
    printf("8. 从文件加载数据\n");
    printf("9. 内存信息\n");
    printf("0. 退出系统\n");
    printf("═══════════════════════════════════════\n");
    printf("请选择操作: ");
}