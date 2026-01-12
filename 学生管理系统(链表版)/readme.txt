用 C 写一个 终端版学生管理系统，支持增删改查，数据可保存到文件



//#define APP_VERSION "0.1.01"
//先做出来的一个垃圾,只有打印菜单//输入数字//0能退出的功能
//#define APP_VERSION "0.1.10"  
//优化了编译文件,现在不用每加入一个新功能就去改tasks.json了.同时
//在main开头加入了win32强制切到utf-8输出来保证exe文件不乱码
//#define APP_VERSION "0.2.01"
//完成基本框架,现在可以从菜单调用各后级功能 
//#define APP_VERSION "1.0.02"
//实现了添加学生的功能,并且菜单 1对接到 student_db
//#define APP_VERSION "1.1.03"
//补齐了结构体的数据类型
#define APP_VERSION "1.2.03"
//完整实现了增删查改,开始实现数据的保存和导入