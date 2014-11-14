#include<stdio.h>
void insertionSort(int a[], int n)
{
    //序列中公n个数，所以要进行n-1次插入
    int i, j, key;
    //从序列中的第二个数开始
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i-1])     //否则无需进行插入操作，因为这两个数的大小关系确定，位置不用变化
        {
            key = a[i];
            j = i-1;
            while (j >= 0 && key < a[j])
            {
                a[j+1] = a[j];
                a[j] = key;
                j--;   //j--后去看下一个数和key的大小情况， 如果满足条件，交换之
            }
        }
    }
}

int main()
{
    int a[7] = {8, 2, 4, 9, 3, 6, 10};
    int i;
    insertionSort(a, 7);
    for (i = 0; i < 7; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}
