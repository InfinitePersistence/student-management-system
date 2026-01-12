// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "student_db.h"
// #include "student_list.h"


// //管理学生数据的存储和操作，不负责任何用户输入输出

// static int student_db_grow(StudentDB *db)   //StudentDB *db是指向“学生数据库本体”的指针
// //static表示这个函数只在 student_db.c 内部使用（外部不能调用）   为什么要加这个??
// {
//     int new_capacity = (db->capacity == 0) ? 8 : db->capacity * 2;
// /*这里分两种情况：情况 A：第一次用capacity == 0给 8 个 Student 的空间
// 情况 B：不够用了capacity > 0容量翻倍*/
//     Student *new_data = realloc(db->data, new_capacity * sizeof(Student));
// //第一次真正向堆申请学生数组内存    Student *new_data什么意思???new_data是student*型么?
// //realloc的返回值必须接住.    realloc的返回值规则???  
//     if (!new_data) {
//         return -1; // 内存不足
//     }

//     db->data = new_data;
//     db->capacity = new_capacity;//更新指针和容量
//     return 0;
// }
// //            为什么grow 只改 capacity，不改 size？??





// void student_db_init(StudentDB *db)
// {
//     db->data = NULL;
//     db->size = 0;
//     db->capacity = 0;
// }

// void student_db_free(StudentDB *db)
// {
//     free(db->data);
//     db->data = NULL;
//     db->size = 0;
//     db->capacity = 0;
// }

// //查找
// int student_db_find_index_by_id(const StudentDB *db, int id)
// {
//     for (int i = 0; i < db->size; i++) {
//         if (db->data[i].id == id) {
//             return i;
//         }
//     }
//     return -1;
// }

// //添加学生
// int student_db_add(StudentDB *db, const Student *s)
// {
//     // 学号不能重复
//     if (student_db_find_index_by_id(db, s->id) != -1) {
//         return 1; // 重复
//     }

//     // 空间不够就扩容
//     if (db->size == db->capacity) {
//         if (student_db_grow(db) != 0) {
//             return -1; // 内存不足
//         }
//     }

//     db->data[db->size++] = *s;
//     return 0;
// }


// //修改学生
// int student_db_update_by_id(StudentDB *db, int id, const Student *new_s)
// {
//     int index = student_db_find_index_by_id(db, id);
//     if (index == -1) {
//         return 1; // 没找到
//     }

//     db->data[index] = *new_s;
//     return 0;
// }

// //删除学生
// int student_db_delete_by_id(StudentDB *db, int id)
// {
//     int index = student_db_find_index_by_id(db, id);
//     if (index == -1) {
//         return 1;
//     }

//     db->data[index] = db->data[db->size - 1];
//     db->size--;
//     return 0;
// }

// // 显示所有学生
// void student_db_print_all(const StudentDB *db)
// {
//     if (db->size == 0) {
//         printf("当前没有学生记录。\n");
//         return;
//     }

//     printf("%-6s %-12s %-6s %-8s %-10s %-30s\n",
//        "ID", "Name", "Age", "Score", "Status", "Contact");

//     for (int i = 0; i < db->size; i++) {
//         const Student *s = &db->data[i];

//         printf("%-6d %-12s %-6d %-8.2f %-10s %-30s\n",
//        s->id,
//        s->name,
//        s->age,
//        s->score,
//        s->status == ACTIVE ? "ACTIVE" : "INACTIVE",
//        s->contact_type == 0 ? s->contact.phone : s->contact.email);

//     }
// }




// //内存信息
// void student_db_print_memory_info(const StudentDB *db)
// {
//     printf("Student sizeof: %zu bytes\n", sizeof(Student));
//     printf("size: %d\n", db->size);
//     printf("capacity: %d\n", db->capacity);
//     printf("allocated: %zu bytes\n",
//            (size_t)db->capacity * sizeof(Student));
// }

// //==================================================================
// //保存到文件
// int student_db_save_to_file(const StudentDB *db, const char *path)
// {
//     FILE *fp = fopen(path, "w");   // 覆盖写
//     if (!fp) return -1;

//     for (int i = 0; i < db->size; i++) {
//         const Student *s = &db->data[i];

//         const char *contact_value =
//             (s->contact_type == 0) ? s->contact.phone : s->contact.email;

//         // 注意 name 不含空格的话，这样保存没问题
//         fprintf(fp, "%d|%s|%d|%.2f|%d|%d|%s\n",
//                 s->id,
//                 s->name,
//                 s->age,
//                 s->score,
//                 (int)s->status,
//                 s->contact_type,
//                 contact_value);
//     }

//     fclose(fp);
//     return 0;
// }


// //从文件加载
// int student_db_load_from_file(StudentDB *db, const char *path)
// {
//     FILE *fp = fopen(path, "r");
//     if (!fp) return -1;

//     // 如果你希望“加载=覆盖当前内存数据”，先清空
//     db->size = 0;

//     char line[256];
//     while (fgets(line, sizeof line, fp)) {
//         // 去掉末尾换行
//         line[strcspn(line, "\r\n")] = '\0';

//         Student s;
//         int status_int = 0;
//         char contact_value[64];

//         // 解析：id|name|age|score|status|contact_type|contact_value
//         // name 不含空格时用 %19[^|] 更稳（读到 | 为止）
//         if (sscanf(line, "%d|%19[^|]|%d|%f|%d|%d|%63[^\n]",
//                    &s.id, s.name, &s.age, &s.score,
//                    &status_int, &s.contact_type, contact_value) != 7) {
//             fclose(fp);
//             return -1; // 格式不对
//         }

//         s.status = (StudentStatus)status_int;

//         if (s.contact_type == 0) {
//             strncpy(s.contact.phone, contact_value, sizeof(s.contact.phone) - 1);
//             s.contact.phone[sizeof(s.contact.phone) - 1] = '\0';
//         } else {
//             strncpy(s.contact.email, contact_value, sizeof(s.contact.email) - 1);
//             s.contact.email[sizeof(s.contact.email) - 1] = '\0';
//         }

//         // 用 add，能顺便做“学号查重”
//         if (student_db_add(db, &s) != 0) {
//             // 重复/内存不足都算失败（你也可以选择跳过重复）
//             fclose(fp);
//             return -1;
//         }
//     }

//     fclose(fp);
//     return 0;
// }

