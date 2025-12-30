#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 比较函数：用于qsort排序的规则定义
 * 参数：a和b是指向数组元素的指针（数组元素是char*，所以这里实际是char**）
 * 返回值：负数(a排b前)，零(相等)，正数(b排a前)
 * 传参时使用指针传递，返回值为1，0，-1
 */
int compare_strings(const void *a, const void *b) {
    // 1. 将void*转换为指向char*的指针（即char**）
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;
    
    // 2. 使用strcmp比较两个字符串
    // strcmp返回值规则与qsort要求完全一致
    return strcmp(*str1, *str2);
}

int main() {
    // 待排序的字符串数组（实际上是字符指针数组）
    char *fruits[] = {
        "apple", 
        "orange", 
        "banana", 
        "grape",
        "pear",
        "kiwi"
    };
    
    // 计算数组元素个数
    int n = sizeof(fruits) / sizeof(fruits[0]);
    
    // 输出排序前的数组
    printf("排序前:\n");
    for(int i = 0; i < n; i++) {
        printf("%d: %s\n", i, fruits[i]);
    }
    printf("\n");
    
    /*
     * 调用qsort进行排序：
     * fruits    - 数组首地址
     * n         - 元素个数
     * sizeof(char*) - 每个元素的大小（指针大小）
     * compare_strings - 比较函数指针
     */
    qsort(fruits, n, sizeof(char*), compare_strings);
    
    // 输出排序后的结果
    printf("按字典序升序排列后:\n");
    for(int i = 0; i < n; i++) {
        printf("%d: %s\n", i, fruits[i]);
    }
    
    return 0;
}
