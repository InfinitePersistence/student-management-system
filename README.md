
## Overview
A student management system implemented in C, using linked lists for dynamic data storage and supporting basic CRUD operations with file persistence.

## Features
- Add, delete, modify, and search student records
- Store student data using a singly linked list
- Save and load records from files
- Input validation and basic error handling
- Modular code organization

## Project Structure
student-management-system/
├── src/        # Source files
├── include/    # Header files
├── data/       # Sample data files
├── Makefile
└── README.md

## Technical Highlights
- Singly linked list implementation
- Dynamic memory management with malloc/free
- File I/O using standard C library
- Separation of interface and implementation
- Basic defensive programming

## Usage
- Select operations from the menu
- Enter student information as prompted
- Data can be saved to and loaded from files

## Roadmap
- [ ] Support sorting by different fields
- [ ] Add binary file storage
- [ ] Refactor to doubly linked list
- [ ] Add unit tests


//#define APP_VERSION "0.1.01"//先做出来的一个垃圾,只有打印菜单//输入数字//0能退出的功能
//#define APP_VERSION "0.1.10"  //优化了编译文件,现在不用每加入一个新功能就去改tasks.json了.同时
//在main开头加入了win32强制切到utf-8输出来保证exe文件不乱码
//#define APP_VERSION "0.2.01"//完成基本框架,现在可以从菜单调用各后级功能 
//#define APP_VERSION "1.0.02"//实现了添加学生的功能,并且菜单 1对接到 student_db
//#define APP_VERSION "1.1.03"//补齐了结构体的数据类型
//#define APP_VERSION "1.2.03"//完整实现了增删查改,开始实现数据的保存和导入
//#define APP_VERSION "1.3.04"//实现了数据的本地保存,设置了保存路径
//#define APP_VERSION "1.4.04"//补充统计信息功能
//#define APP_VERSION "2.0.01"//补充内存信息功能现在实现了菜单所有功能为完整版了
//#define APP_VERSION "2.0.02"//用 printf 的“最小字段宽度”控制列宽,优化了displayALLstudents的排版
// #define APP_VERSION "2.0.03"//优化了addStudent的邮箱电话输入检测,修复了bug
// #define APP_VERSION "3.0.02"//将学生信息结构体修改为了双向循环链表,尚在移植功能
//#define APP_VERSION "3.1.03"//实现了增加学生到链表,遍历打印链表,从链表中查找
#define APP_VERSION "3.2.03"//功能完备
