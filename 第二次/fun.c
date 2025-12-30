#include <stdio.h>
#include <math.h>
double fun(int n) {
    double sum = 0.0; 
    int i;
    for (i = 1; i < n; i++) 
    {
        if (i % 3 == 0 && i % 7 == 0) {
            sum += i; 
        }
    }
    return sqrt(sum);
}

int main() {
    int n;
    double result;
    printf("请输入n的值: ");
    scanf("%d", &n);
    result = fun(n);
    printf("s = %f\n", result);
    system("pause");
    return 0;
}