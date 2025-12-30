#include <stdio.h>

int main() {
    char   *p;
    p = "hello"; 
	//p指向字符串常量, 只是让指针 p 指向这个只读区域的首地址，并非分配可写的内存空间。
    printf("\n（字符串）: %s\n", p);

    printf("\n请输入一段字符串:");
    //scanf("%s",p);                    //  试图向常量区（只读区）写入数据，程序被终止

    //p[0]='x';                         //  试图向常量区（只读区）写入数据，程序被终止
    //p[1]='y';                         //  指向字符串常量的指针不能修改内容（如 p[0] = 'x'; 会导致未定义行为）
    //p[2]='z';                         //  试图修改只读内存中的数据，操作系统会检测到这种非法操作，直接终止程序（触发段错误）。
    printf("\n（字符串）: %s\n", p);
    //system("PAUSE");
    //  如果需要修改字符串内容，应使用字符数组（存储在可写的栈 / 堆内存）而非字符串常量
    char str1[] = "hello";               
    p=str1;                                 //  p指向可写的栈区内存
    p[0] = 'x';                             //  合法，输出 "xello"
    printf("\n（字符串）: %s\n", p);

    p=malloc(strlen("hello") + 1);          //  p指向可写的堆区内存
        if (p != NULL) {
            strcpy(p, "hello");
            p[0] = 'y';                     // 合法，输出 "yello"
            printf("\n（字符串）: %s\n", p);
            free(p);
        }

    return 0;
}