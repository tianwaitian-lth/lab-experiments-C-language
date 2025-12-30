#include <stdio.h>

int main() {
    int a, b, sum;

    printf("请输入两个整数（用空格或回车分隔）: ");

    // 使用 scanf 的返回值检查是否成功读取了两个整数
    if (2 != scanf("%d %d", &a, &b)) {
        printf("错误：输入无效，请确保输入的是两个整数。\n");

        // 尝试清空输入缓冲区（注意：fflush(stdin) 不符合C语言标准，可移植性差）
        fflush(stdin); // 此方法仅在部分编译器（如VC++）中有效
        return 1; // 非正常退出
    }

    // 计算两数之和
    sum = a + b;

    // 输出结果
    printf("两数之和 %d + %d = %d\n", a, b, sum);

    return 0; // 程序正常结束
}