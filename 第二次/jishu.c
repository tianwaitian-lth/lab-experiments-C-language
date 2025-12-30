#include <stdio.h>

// 定义分数结构体
typedef struct {
    long long numerator;   // 分子
    long long denominator; // 分母
} Fraction;

// 计算最大公约数（GCD），用于约分
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 分数化简函数
Fraction simplify_fraction(Fraction f) {
    if (f.numerator == 0) {
        f.denominator = 1;
        return f;
    }
    
    long long common_divisor = gcd(f.numerator, f.denominator);
    // 确保分母为正数
    if (common_divisor < 0) common_divisor = -common_divisor;
    
    f.numerator /= common_divisor;
    f.denominator /= common_divisor;
    return f;
}

// 分数加法函数
Fraction add_fractions(Fraction a, Fraction b) {
    Fraction result;
    
    // 通分后分子相加
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    
    // 化简结果
    return simplify_fraction(result);
}

// 计算调和级数前n项和，返回分数结果
Fraction harmonic_series_sum(int n) {
    Fraction sum = {0, 1}; // 初始和为0/1
    
    for (int i = 1; i <= n; i++) {
        Fraction term = {1, i}; // 当前项为1/i
        sum = add_fractions(sum, term);
    }
    
    return sum;
}

int main() {
    int n;
    
    printf("请输入调和级数的项数n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("项数必须为正整数。\n");
        return 1;
    }
    
    for (int i=1;i<=n;i++)
    {
        Fraction result = harmonic_series_sum(i);
        printf("H(%d) = %lld/%lld\n", i, result.numerator, result.denominator);
    }
    system("pause");
    return 0;
}