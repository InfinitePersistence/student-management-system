#include "student_list.h"
#include <stdio.h>
// #include "student_db.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

StudentList g_list; // g_list全局变量

// 创建新节点
static StudentNode *create_NewNode(Student data)
{
    StudentNode *NewNode = (StudentNode *)malloc(sizeof(StudentNode));

    if (NewNode == NULL)
    {
        printf("create_NewNode:创建新节点为NULL!");
        return NULL;
    }

    NewNode->data = data;
    NewNode->next = NewNode;
    NewNode->prev = NewNode;

    return NewNode;
}

// 初始化(创建头节点)
int list_init(StudentList *list)
{
    if (list == NULL)
        return -1;
    list->head = (StudentNode *)malloc(sizeof(StudentNode));
    if (list->head == NULL)
    {
        printf("malloc head failed: %s\n", strerror(errno));
        return -1;
    }

    list->head->next = list->head;
    list->head->prev = list->head;

    list->size = 0;

    return 0;
}

// 尾插(将node插到p后面)

static void insert_behind(StudentNode *p, StudentNode *node)
{
    node->prev = p;
    node->next = p->next;
    p->next->prev = node;
    p->next = node;
}

// 新增一个学生到队尾
void addStudent_list(Student data)
{
    // 判断指针是否为NULL

    StudentNode *NewNode = create_NewNode(data);
    if (NewNode == NULL)
    {
        printf("addStudent创建新节点失败");
        return;
    }

    StudentNode *p = g_list.head; // 拷贝head

    while (p->next != g_list.head)
    {
        p = p->next;
    }

    insert_behind(p, NewNode);

    g_list.size++;
}

// 遍历
static void print_student_header(void)
{
    printf("%-4s %-10s %-4s %-6s %-8s %s\n",
           "ID", "Name", "Age", "Score", "Status", "Contact");
}

void printf_list(void)
{
    StudentNode *p = g_list.head->next;
    if (g_list.size == 0)
    {
        printf("当前没有学生记录。\n");
        return;
    }

    print_student_header();
    while (p != g_list.head)
    {
        // p->data 是学生信息结构体
        Student s = p->data;
        printf("%-4d %-10s %-4d %-6.2f %-8s ",
               s.id,
               s.name,
               s.age,
               s.score,
               s.status == ACTIVE ? "ACTIVE" : "INACTIVE");

        if (s.contact_type == 0)
        {
            printf("%-12s\n", s.contact.phone);
        }
        else
        {
            printf("%-30s\n", s.contact.email);
        }

        p = p->next;
    }
}

// 查找一个学生
StudentNode *findStudent_list(StudentList *list, int id)
{
    StudentNode *p = list->head->next;

    while (p != list->head)
    {
        if (p->data.id == id)
            return p;
        p = p->next;
    }

    return NULL;
}

// 删除一个学生
int delStudent_list(StudentList *list, int id)
{
    StudentNode *p = findStudent_list(list, id);

    // 判断指针是否为NULL
    if (NULL == p)
    {
        printf("未找到学号为 %d 的学生，删除失败。\n", id);
        return 1;
    }

    if (p == list->head)
    {
        printf("内部错误：不允许删除头节点。\n");
        return 1;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    list->size--;
    return 0;
}

//修改一个学生的信息
int editStudent_list(StudentList *list,int id,Student NewNode){
    StudentNode *p = findStudent_list(list, id);

        // 判断指针是否为NULL
    if (NULL == p)
    {
        printf("未找到学号为 %d 的学生，修改失败。\n", id);
        return 1;
    }

    if (p == list->head)
    {
        printf("内部错误：不允许修改头节点。\n");
        return 1;
    }


    p->data = NewNode;

    return 0;
}

//保存到文件
int student_list_save_to_file(const StudentList *list, const char *path)
{
    FILE *fp = fopen(path, "w");
    if (!fp) return -1;

    StudentNode *p = list->head->next;
    while (p != list->head) {
        const Student *s = &p->data;
        const char *contact_value =
            (s->contact_type == 0) ? s->contact.phone : s->contact.email;

        fprintf(fp, "%d|%s|%d|%.2f|%d|%d|%s\n",
                s->id, s->name, s->age, s->score,
                (int)s->status, s->contact_type, contact_value);

        p = p->next;
    }

    fclose(fp);
    return 0;
}


//清空链表数据
static void list_clear(StudentList *list)
{
    StudentNode *p = list->head->next;
    while (p != list->head) {
        StudentNode *next = p->next;
        free(p);
        p = next;
    }
    list->head->next = list->head;
    list->head->prev = list->head;
    list->size = 0;
}

//从文件加载
int student_list_load_from_file(StudentList *list, const char *path)
{
    FILE *fp = fopen(path, "r");
    if (!fp) return -1;

    list_clear(list); // 覆盖加载

    char line[256];
    while (fgets(line, sizeof line, fp)) {
        line[strcspn(line, "\r\n")] = '\0';

        Student s;
        int status_int = 0;
        char contact_value[64];

        if (sscanf(line, "%d|%19[^|]|%d|%f|%d|%d|%63[^\n]",
                   &s.id, s.name, &s.age, &s.score,
                   &status_int, &s.contact_type, contact_value) != 7) {
            fclose(fp);
            return -1;
        }

        s.status = (StudentStatus)status_int;

        if (s.contact_type == 0) {
            strncpy(s.contact.phone, contact_value, sizeof(s.contact.phone) - 1);
            s.contact.phone[sizeof(s.contact.phone) - 1] = '\0';
        } else {
            strncpy(s.contact.email, contact_value, sizeof(s.contact.email) - 1);
            s.contact.email[sizeof(s.contact.email) - 1] = '\0';
        }

        addStudent_list(s);
    }

    fclose(fp);
    return 0;
}


// //内存信息
void student_list_print_memory_info(const StudentList *list)
{
    printf("Student sizeof: %zu bytes\n", sizeof(Student));
    printf("size: %d\n", list->size);
    printf("allocated: %zu bytes\n",
           (size_t)list->size * sizeof(Student));
}

//内存释放
void list_free(StudentList *list)
{
    if (!list || !list->head) return;

    StudentNode *p = list->head->next;
    while (p != list->head) {
        StudentNode *next = p->next;
        free(p);
        p = next;
    }

    free(list->head);
    list->head = NULL;
    list->size = 0;
}