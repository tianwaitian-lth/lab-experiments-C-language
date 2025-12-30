#include <stdio.h>
#include <string.h>

// 方式1：为结构体定义别名
typedef struct student {
    int id;           // 学号
    char name[20];    // 姓名
    int age;          // 年龄
    float score;      // 成绩
} Student;           // Student 是 struct student 的别名

// 方式2：为匿名结构体定义别名
typedef struct {
    int year;
    int month;
    int day;
} Date;              // Date 是匿名结构体的别名

int main() {
    // 使用别名声明结构体变量 - 不需要写struct关键字
    Student stu1;
    Student stu2;
    
    // 初始化结构体成员
    stu1.id = 1001;
    strcpy(stu1.name, "张三");  // 字符串赋值需要使用strcpy
    stu1.age = 20;
    stu1.score = 88.5;
    
    // 声明时直接初始化
    Student stu3 = {1002, "李四", 19, 92.0};
    
    // 使用Date结构体
    Date today = {2023, 10, 15};
    Date birthday = {.year = 2000, .month = 5, .day = 20};  // 指定成员初始化
    
    // 访问和修改结构体成员
    stu2.id = 1003;
    strcpy(stu2.name, "王五");
    stu2.age = 21;
    stu2.score = 85.5;
    
    // 打印结构体信息
    printf("学生1: 学号=%d, 姓名=%s, 年龄=%d, 成绩=%.1f\n", 
           stu1.id, stu1.name, stu1.age, stu1.score);
    printf("学生2: 学号=%d, 姓名=%s, 年龄=%d, 成绩=%.1f\n", 
           stu2.id, stu2.name, stu2.age, stu2.score);
    printf("学生3: 学号=%d, 姓名=%s, 年龄=%d, 成绩=%.1f\n", 
           stu3.id, stu3.name, stu3.age, stu3.score);
    
    printf("今天日期: %d年%d月%d日\n", today.year, today.month, today.day);
    printf("生日: %d年%d月%d日\n", birthday.year, birthday.month, birthday.day);
    
    // 结构体赋值（整体拷贝）
    Student stu4 = stu1;  // 将stu1的值拷贝给stu4
    stu4.id = 1004;       // 修改副本不影响原结构体
    strcpy(stu4.name, "赵六");
    
    printf("学生4(从学生1拷贝): 学号=%d, 姓名=%s\n", stu4.id, stu4.name);
    printf("学生1(原数据): 学号=%d, 姓名=%s\n", stu1.id, stu1.name);
    
    return 0;
}