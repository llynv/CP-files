#include <stdio.h>
#include <string.h>

const int INF = 0x3f3f3f3f;

int a[111], n;

void PrintArray(char s[100]) {
    printf("%s", s);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void PrintEvenValue() {
    printf("Even Value : ");
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) printf("%d ", a[i]);
    }
    printf("\n");
}

void PrintValueInRange(int l, int r) {
    printf("Value in Range [%d, %d] : ", l, r);
    for (int i = l - 1; i < r; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int MaxValue() {
    int res = -INF;
    for (int i = 0; i < n; ++i) {
        if (a[i] > res) res = a[i];
    }
    return res;
}

void AddElement(int x) {
    a[n] = x;
    ++n;
}

int FindValueInArray(int x) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) return 1;
    }
    return 0;
}

int FindValueIndex(int x)
{
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

void RemoveFirstExist(int x) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == x) {
            for (int j = i; j < n - 1; ++j) {
                a[j] = a[j + 1];
            }
            --n;
            break;
        }
    }
}

void RemoveAllExist(int x) {
    int i = 0, j = 0, cnt = 0;
    while (i < n) {
        if (a[i] != x) {
            a[j++] = a[i];
        } else {
            cnt++;
        }
        ++i;
    }
    n -= cnt;
}

void mergeIncrease(int L, int R)
{
    int mid = (L + R) / 2;
    int i = L, j = mid + 1, k = 0;
    int tmp[R - L + 1];
    while (i <= mid && j <= R) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= R) {
        tmp[k++] = a[j++];
    }
    for (int i = L; i <= R; ++i) {
        a[i] = tmp[i - L];
    }
}

void mergeDecrease(int L, int R)
{
    int mid = (L + R) / 2;
    int i = L, j = mid + 1, k = 0;
    int tmp[R - L + 1];
    while (i <= mid && j <= R) {
        if (a[i] > a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= R) {
        tmp[k++] = a[j++];
    }
    for (int i = L; i <= R; ++i) {
        a[i] = tmp[i - L];
    }
}

void MergeSort(int L, int R, int isIncrease)
{
    if (L == R) {
        return;
    }

    int mid = (L + R) / 2;
    MergeSort(L, mid, isIncrease);
    MergeSort(mid + 1, R, isIncrease);

    if (isIncrease) mergeIncrease(L, R);
    else mergeDecrease(L, R);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    PrintArray("Array : ");
    PrintEvenValue();
    PrintValueInRange(2, 4);
    printf("Max Value : %d\n", MaxValue());
    AddElement(100);
    PrintArray("After Add 100 : ");
    printf("Find 100 (YES/NO) : %s\n", (FindValueInArray(100) ? "YES" : "NO"));
    printf("Find 100 (index) : %d\n", FindValueIndex(100));
    RemoveFirstExist(3);
    PrintArray("After Remove First Exist 3 : ");
    RemoveAllExist(1);
    PrintArray("After Remove All Exist 1 : ");
    MergeSort(0, n - 1, 1); // 1 : increase , 0 : decrease
    PrintArray("After Increase Merge Sort : ");
    MergeSort(0, n-1, 0); // 1 : increase , 0 : decrease
    PrintArray("After Decrease Merge Sort : ");
    return 0;
}

