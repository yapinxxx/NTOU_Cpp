#pragma warning(disable:4996)
#include <cstdio>
#include <cstdlib>

void modifyParameters(int *p1, double *p2)
{
    *p1 = *p1 * *p1;
    printf("請輸入參數二: ");
    scanf("%lf", p2);
}

int main()
{
    int p1 = 25;
    double p2 = -1.3;
    modifyParameters(&p1, &p2);
    printf("修改過後的參數一 = %d\n", p1);
    printf("修改過後的參數二 = %lf\n", p2);
    system("pause");
}