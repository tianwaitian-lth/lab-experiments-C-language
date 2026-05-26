#include <stdio.h>
#include <stdlib.h>

#define MAX 105      // 用 #define 确保编译时常量
#define inf 100000

int map[MAX][MAX];   // 全局数组

int main()
{
    int n;
    // 用 while 循环处理多组数据，直到读到 n = 0 停止
    while (scanf("%d", &n) == 1 && n != 0) 
    {
        // 1. 初始化邻接矩阵
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = inf;
            }
        }

        // 2. 读入每个人的联系人数据
        for (int i = 1; i <= n; i++) 
        {
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; j++) 
            {
                int x, y;
                scanf("%d %d", &x, &y);
                map[i][x] = y; // i 到 x 耗时 y 分钟
            }
        }
        // 3. 使用 Floyd-Warshall 算法计算最短路径
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= n; j++) 
                    if (map[i][j] > map[i][k] + map[k][j]) 
                        map[i][j] = map[i][k] + map[k][j];
        int min_max_time = inf; // 1. 全局变量：记录全场最优的那个“最慢时间”
        int best_broker = -1;   // 2. 全局变量：记录最终胜出的那个经纪人编号

        for (int i = 1; i <= n; i++) 
        {
            int max_time_from_i = 0; // 3. 局部变量：当前假设以 i 为起点，传遍所有人要多久
            int can_reach_all = 1;   // 4. 局部变量：标记当前 i 是不是能传给所有人（1代表能，0代表不能）

            for (int j = 1; j <= n; j++) 
            {
                // 5. 核心判断：如果 i 传到 j 的最短时间依然是无穷大
                if (map[i][j] == inf) 
                {
                    can_reach_all = 0; // 说明图是不连通的，j 根本收不到 i 的消息
                    break;             // 既然有人收不到，i 就没资格当起点，直接结束对 i 的检查
                }
                // 6. 找出 i 这一行里的最大值
                if (map[i][j] > max_time_from_i) 
                {
                    max_time_from_i = map[i][j]; 
                }
            }
            // 7. 终极 PK：如果 i 有能力传遍所有人，且他的最慢时间比之前记录的最优解还要快
            if (can_reach_all && max_time_from_i < min_max_time) 
            {
                min_max_time = max_time_from_i; // 刷新全场最快纪录
                best_broker = i;                 // 把金牌得主换成 i
            }
        }
        printf("%d %d\n", best_broker, min_max_time);
    }
    return 0;
}