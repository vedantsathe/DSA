#include <stdio.h>
#include <stdio.h>
#define size 20 
void main()
{
    int a[size], n, i;
    printf("\n how many number to read:");
    scanf("%d", &n);
    printf("\n enter the numbers:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n - 1);
    printf("\n sorted array:");
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
}
void mergesort(int a[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
void merge(int a[], int lb, int mid, int ub)
{
    int i, j, k, b[size];
    i = lb;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = lb, j = 0; j < k; i++, j++)
        a[i] = b[j];
}


