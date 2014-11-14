#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int start, int mid, int end)
{
    int i, j, k, n1, n2;
    int * front, * back; //变量用于申请两个内存空间

    n1 = mid - start + 1;   //前一部分长度
    n2 = end - mid;  //后一部分长度

    front = (int *) malloc (n1 * sizeof(int)) ; //申请两个空间存放排好的数组
    back = (int *) malloc (n2 * sizeof(int));

    /*将数组转入两个新空间中*/
    for (i = 0; i < n1; i++)
    {
        front[i] = a[start + i];
    }
    for (i = 0; i < n2; i++)
    {
        back[i] = a[mid + i + 1];
    }

    /*将元素合并*/
    i = 0;
    j = 0;
    k = start;
    
    while (i < n1 && j < n2) 
    {
        if (front[i] < back[j])
        {
            a[k++] = front[i++];
        }
        else
        {
            a[k++] = back[j++];
        }
    }

    /*将剩余元素合并*/
    while (i < n1)     //有点巧妙
    {
        a[k++] = front[i++];
    }
    while (j < n2)
    {
        a[k++] = back[j++];
    }
}

void merge_sort(int a[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;  //将数组分解
        merge_sort(a, start, mid); //前一部分用递归方法排序
        merge_sort(a, mid + 1, end); //后一部分用递归方法排序
        merge(a, start, mid, end);  //将两个部分合并
    }
}
int main()
{
    int a[8] = {1, 4, 3, 9, 6, 5, 8, 7};
    int i;

    merge_sort(a, 0, 7);

    for (i = 0; i < 8; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
