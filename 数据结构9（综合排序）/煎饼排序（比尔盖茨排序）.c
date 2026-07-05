#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y)
{    
    int temp = *x;
    *x = *y;
    *y = temp;
}

//反转数组
void reverse(int a[], int l, int r)
{
    while (l < r)
    {
        swap(&a[l], &a[r]);
        l++;
        r--;
    }
}

void pancakeSort(int a[], int n)
{
    //已经排好
    if (n <= 1)
        return;
    //找出最大的坐标
    int flag=-1,Max=-1000000;
    for (int i=0;i<n;i++)
    {
        if (a[i]>Max)
        {
            Max=a[i];
            flag=i;
        }
    }
    if (flag==n-1)
        pancakeSort(a,n-1);
    //翻转到最后
    reverse(a,0,flag);
    reverse(a,0,n-1);
    //继续排序
    pancakeSort(a,n-1);
}

int main()
{
    char *buff;
    buff=malloc(1000*sizeof(char));
    fgets(buff,1000,stdin);
    int len = strlen(buff);
    int arr[105],i=0,num=0;
    while (i < len && buff[i] != '\n')
    {
        if (buff[i] == 'n')
        {
            i += 4; // 跳过 "null"
            arr[num++] = -1;
            continue;
        }
        int temp = 0, flag = 0, sign = 1;
        
        if (buff[i] == '-') {
            sign = -1;
            i++;
        }
        
        while (buff[i] >= '0' && buff[i] <= '9')
        {
            flag = 1;
            temp = temp * 10 + (buff[i] - '0');
            i++;
        }
        
        if (flag)
        {
            arr[num++] = temp * sign;
            i--; 
        }
        
        if (buff[i] == ']')
        {
            break;
        }
        i++;
    }

    pancakeSort(arr,num);
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}