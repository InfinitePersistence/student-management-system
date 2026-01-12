#include <stdio.h>
#include "pause_enter.h"

void pause_enter(void) {

    int ch;

    // 清掉本行残留（比如菜单 scanf 留下的 '\n'）
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    // 真正等待用户按回车
    getchar();
}