#include <stdio.h>

int main() {
    int scores[100]; // 用于存储成绩的数组
    int count = 0;   // 记录已存储的成绩数量
    int choice;      // 记录用户菜单选择
    int i, sum;
    float average;

    do {
        // 打印菜单
        printf("\n=== 学生成绩管理系统 ===\n");
        printf("1. 添加成绩\n");
        printf("2. 查看所有成绩\n");
        printf("3. 计算平均分\n");
        printf("4. 成绩等级评估\n");
        printf("5. 退出系统\n");
        printf("请选择操作 (1-5): ");
        
        if (scanf("%d", &choice) != 1) { // 检查输入有效性
            printf("输入错误，请输入数字！\n");
            while (getchar() != '\n'); // 清空输入缓冲区
            continue;
        }

        // 使用switch语句处理用户选择
        switch (choice) {
            case 1: // 添加成绩
                if (count < 100) {
                    printf("请输入成绩 (0-100): ");
                    if (scanf("%d", &scores[count]) == 1 && scores[count] >= 0 && scores[count] <= 100) {
                        count++;
                        printf("成绩添加成功！\n");
                    } else {
                        printf("无效成绩，请输入0-100之间的整数。\n");
                        while (getchar() != '\n');
                    }
                } else {
                    printf("成绩列表已满！\n");
                }
                break;

            case 2: // 查看所有成绩
                if (count == 0) {
                    printf("暂无成绩记录。\n");
                } else {
                    printf("当前所有成绩：\n");
                    for (i = 0; i < count; i++) {
                        printf("%d ", scores[i]);
                    }
                    printf("\n");
                }
                break;

            case 3: // 计算平均分
                if (count == 0) {
                    printf("暂无成绩记录，无法计算平均分。\n");
                } else {
                    sum = 0;
                    for (i = 0; i < count; i++) {
                        sum += scores[i];
                    }
                    average = (float)sum / count;
                    printf("平均分: %.2f\n", average);
                }
                break;

            case 4: { // 成绩等级评估 (使用代码块以局部变量)
                int scoreToCheck;
                if (count == 0) {
                    printf("暂无成绩记录。\n");
                    break;
                }
                printf("请输入要评估的成绩序号 (1-%d): ", count);
                if (scanf("%d", &i) == 1 && i >= 1 && i <= count) {
                    scoreToCheck = scores[i - 1];
                    printf("成绩 %d 的等级为: ", scoreToCheck);
                    // 使用switch进行等级划分，演示case的穿透用法[2,3](@ref)
                    switch (scoreToCheck / 10) { // 通过整数除法将百分制成绩映射到case
                        case 10:
                        case 9:
                            printf("A (优秀)\n");
                            break;
                        case 8:
                            printf("B (良好)\n");
                            break;
                        case 7:
                            printf("C (中等)\n");
                            break;
                        case 6:
                            printf("D (及格)\n");
                            break;
                        default:
                            printf("E (不及格)\n"); // 60分以下
                            break;
                    }
                } else {
                    printf("无效的序号！\n");
                    while (getchar() != '\n');
                }
                break;
            }

            case 5: // 退出系统
                printf("感谢使用，再见！\n");
                break;

            default: // 处理非1-5的输入[7,8](@ref)
                printf("无效选择，请输入1-5之间的数字。\n");
                break;
        }
    } while (choice != 5); // 如果用户没有选择5（退出），则继续循环

    return 0;
}