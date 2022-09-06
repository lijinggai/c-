#include<stdio.h>
//һ����������ǰż���ں�
void Move(int arr[], int sz)
{
    int laft = 0;
    int right = sz - 1;
    while (laft < right)
    {
        while (laft < right && arr[laft] % 2 == 1)//��ż��
        {
            laft++;
        }
        while (laft < right && arr[right] % 2 == 0)//������
        {
            right--;
        }
        if (laft < right)
        {
            int tmp = arr[laft];
            arr[laft] = arr[right];
            arr[right] = tmp;
        }
    }
}
void print(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    Move(arr, sz);
    print(arr, sz);
    return 0;
}
