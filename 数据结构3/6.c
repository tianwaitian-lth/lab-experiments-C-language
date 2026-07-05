#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int h;
    int k;
} Person;
int cmp(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    if (p1->h != p2->h) {
        return p2->h -p1->h; // 按身高降序排序
    } else
    {
        return p1->k - p2->k; // 
    }
}
int main()
{
    Person *people=malloc(sizeof(Person)*10001);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &people[i].h, &people[i].k);
    qsort(people, n, sizeof(Person), cmp);
    int cursize=0;
    Person *result=malloc(sizeof(Person)*10001);
    for (int i = 0; i < n; i++) {
        int pos = people[i].k;
        if (pos<cursize)
        {
            memmove(&result[pos + 1], &result[pos], (cursize - pos) * sizeof(Person));
        }
        result[pos] = people[i];
        cursize++;
    }
    for (int i = 0; i < n; i++)
        printf("%d %d\n", result[i].h, result[i].k);
    free(people);
    free(result);
    return 0;
}