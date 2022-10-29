void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDown(int* a, int n, int root)//����
{
	int parent = root;
	int child = parent * 2 + 1;//����
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
void HeapSort(int* a, int n)//������
{
	//���򣬽����
	for (int end = (n - 1 - 1) / 2; end >= 0; end--)
	{
		ADJustDown(a, n, end);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ADJustDown(a, end, 0);
		end--;
	}
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
	int* nums = (int*)malloc(sizeof(int) * capacitySize);
	for (int i = 0; i < capacitySize; i++)
	{
		nums[i] = capacity[i] - rocks[i];
	}
	HeapSort(nums, capacitySize);//������
	int i = 0;
	while (i < capacitySize)
	{
		if (additionalRocks - nums[i] >= 0)
		{
			additionalRocks -= nums[i];
			i++;
		}
		else
		{
			break;
		}
	}
	return i;
}