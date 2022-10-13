void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDown(int* a, int n, int root)//����
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//����û���Һ���
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//����������ѭ����������ѭ��
		{
			break;
		}
	}
}
int* sortArray(int* nums, int numsSize, int* returnSize)
{
	//�����򽨴��
	for (int end = (numsSize - 1 - 1) / 2; end >= 0; end--)
	{
		ADJustDown(nums, numsSize, end);//����
	}

	for (int n = numsSize - 1; n > 0; n--)
	{
		Swap(&nums[0], &nums[n]);
		ADJustDown(nums, n, 0);//����
	}
	*returnSize = numsSize;
	return nums;
}