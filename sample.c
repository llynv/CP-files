#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
    int a[n], maxVal = -(__INT32_MAX__);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        maxVal = (a[i] > maxVal ? a[i] : maxVal);
    }
    printf("Max value : %d", maxVal);
}