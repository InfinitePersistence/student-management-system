#include <stdio.h>
#include "showStatistics.h"
#include "pause_enter.h"
#include "student_list.h"

extern StudentList g_list;

void showStatistics(void)
{
    if (g_list.size == 0) {
        printf("当前没有学生数据，无法统计。\n");
        printf("按回车继续...");
        pause_enter();
        return;
    }

    int active_count = 0;
    int inactive_count = 0;

    float sum_age = 0.0f;
    float sum_score = 0.0f;

    // 用第一个有效节点初始化 min/max
    StudentNode *p = g_list.head->next;
    Student first = p->data;

    int min_age = first.age;
    int max_age = first.age;

    float min_score = first.score;
    float max_score = first.score;

    // 遍历链表
    while (p != g_list.head) {
        const Student *s = &p->data;

        if (s->status == ACTIVE) active_count++;
        else inactive_count++;

        if (s->age < min_age) min_age = s->age;
        if (s->age > max_age) max_age = s->age;
        sum_age += (float)s->age;

        if (s->score < min_score) min_score = s->score;
        if (s->score > max_score) max_score = s->score;
        sum_score += s->score;

        p = p->next;
    }

    printf("========== 学生统计信息 ==========\n");
    printf("学生总数: %d\n", g_list.size);
    printf("在读(ACTIVE): %d\n", active_count);
    printf("非在读(INACTIVE): %d\n", inactive_count);

    printf("\n【年龄】\n");
    printf("平均年龄: %.2f\n", sum_age / g_list.size);
    printf("最小年龄: %d\n", min_age);
    printf("最大年龄: %d\n", max_age);

    printf("\n【成绩】\n");
    printf("平均成绩: %.2f\n", sum_score / g_list.size);
    printf("最低成绩: %.2f\n", min_score);
    printf("最高成绩: %.2f\n", max_score);

    printf("==================================\n");
    printf("按回车继续...");
    pause_enter();
}
