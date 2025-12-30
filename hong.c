#include <stdio.h>

// 定义调试宏（取消注释即可关闭调试输出）
#define DEBUG

// 定义版本宏（修改为1启用基础版，2启用高级版）
#define VERSION 2

int main() {
    int a, b, result;
    
    // 获取用户输入
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    
    // 条件编译1：调试信息输出
    #ifdef DEBUG
        printf("[调试信息] 输入的值：a = %d, b = %d\n", a, b);
    #else
        printf("计算中...\n");
    #endif
    
    // 条件编译2：根据不同版本选择不同功能
    #if VERSION == 1
        // 基础版：只计算加法
        result = a + b;
        printf("基础版 - 两数之和：%d + %d = %d\n", a, b, result);
    
    #elif VERSION == 2
        // 高级版：计算加法和乘法
        result = a + b;
        printf("高级版 - 两数之和：%d + %d = %d\n", a, b, result);
        
        int product = a * b;
        printf("高级版 - 两数之积：%d × %d = %d\n", a, b, product);
        
        #ifdef DEBUG
            printf("[调试信息] 乘法计算完成\n");
        #endif
    
    #else
        // 默认功能
        printf("未知版本，使用默认计算：\n");
        result = a + b;
        printf("结果：%d\n", result);
    #endif
    
    // 条件编译3：平台特定代码（示例）
    #ifdef _WIN32
        printf("运行在Windows平台\n");
    #elif defined(__linux__)
        printf("运行在Linux平台\n");
    #else
        printf("运行在其他平台\n");
    #endif
    
    return 0;
}