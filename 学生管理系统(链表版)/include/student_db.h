// #ifndef STUDENT_DB_H
// #define STUDENT_DB_H

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
// typedef struct {
//     Student *data;   // 动态数组
//     int size;        // 当前学生数量
//     int capacity;    // 当前容量
// } StudentDB;

// /* ========== 生命周期管理 ========== */
// void student_db_init(StudentDB *db);
// void student_db_free(StudentDB *db);

// /* ========== 基本操作 ========== */
// int student_db_add(StudentDB *db, const Student *s);
// int student_db_find_index_by_id(const StudentDB *db, int id);
// int student_db_update_by_id(StudentDB *db, int id, const Student *new_s);
// int student_db_delete_by_id(StudentDB *db, int id);

// /* ========== 显示 / 信息 ========== */
// void student_db_print_all(const StudentDB *db);
// void student_db_print_memory_info(const StudentDB *db);

// int student_db_save_to_file(const StudentDB *db, const char *path);
// int student_db_load_from_file(StudentDB *db, const char *path);




// #endif