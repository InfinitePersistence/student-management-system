// #ifndef _STUDENT_LIST_H
// #define _STUDENT_LIST_H

// #include "student_db.h"

// /* ========== 学生结构体 ========== */
// typedef enum {
//     ACTIVE,
//     INACTIVE
// } StudentStatus;

// typedef union {
//     char phone[12];
//     char email[30];
// } Contact;

// typedef struct Student {
//     int id;
//     char name[20];
//     int age;
//     float score;
//     StudentStatus status;
//     Contact contact;
//     int contact_type;   // 0-电话, 1-邮箱
// } Student;


// /* ========== 学生数据库结构 ========== */

// typedef struct Students_Node{
//     Student data;         //数据域
//     struct Students_Node *next;
//     struct Students_Node *prev;
// }StudentNode;

// typedef struct {
//     StudentNode *head;            // 哨兵节点
//     int size;
// } StudentList;

// extern StudentList g_list;

// StudentNode* list_init(StudentList *list);//初始化
// void addStudent_list(Student data); //增
// StudentNode* findStudent_list(StudentList *list, int id);//查
// int delStudent_list(StudentList *list,int id);//删
// int editStudent_list(StudentList *list,int id,Student data);//改
// void printf_list(void);


// //文件保存加载
// int student_list_load_from_file(StudentList *list, const char *path);
// int student_list_save_to_file(const StudentList *list, const char *path);
// #endif


#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <stdio.h>

/* =======================
 * 学生相关数据定义
 * ======================= */

typedef enum {
    ACTIVE = 0,
    INACTIVE = 1
} StudentStatus;

typedef union {
    char phone[12];
    char email[30];
} Contact;

typedef struct {
    int id;
    char name[20];
    int age;
    float score;
    StudentStatus status;
    Contact contact;
    int contact_type;   // 0-电话 1-邮箱
} Student;


/* =======================
 * 链表结构定义
 * ======================= */

typedef struct StudentNode {
    Student data;
    struct StudentNode *next;
    struct StudentNode *prev;
} StudentNode;

typedef struct {
    StudentNode *head;   // 哨兵节点
    int size;
} StudentList;


/* =======================
 * 全局链表
 * ======================= */

extern StudentList g_list;


/* =======================
 * 链表基础操作
 * ======================= */

int list_init(StudentList *list);


/* =======================
 * 业务操作
 * ======================= */

StudentNode* findStudent_list(StudentList *list, int id);
void addStudent_list(Student data);
int  delStudent_list(StudentList *list, int id);
int  editStudent_list(StudentList *list, int id, Student new_data);
void printf_list(void);
void student_list_print_memory_info(const StudentList *list);
/* =======================
 * 文件操作
 * ======================= */

int student_list_save_to_file(const StudentList *list, const char *path);
int student_list_load_from_file(StudentList *list, const char *path);
void list_free(StudentList *list);


/* =======================
 * 显示
 * ======================= */

void print_student(const Student *s);
void print_student_list(const StudentList *list);

#endif
