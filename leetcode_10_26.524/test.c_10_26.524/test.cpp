char* findLongestWord(char* s, char** dictionary, int dictionarySize)
{
    int m = strlen(s);//s�ַ�������
    int n = dictionarySize;

    int count = 0;
    int ri = 0;

    char* cur1 = s;
    char** cur2 = dictionary;
    for (int i = 0; i < n; i++)
    {

        int c = 0;//��Ҫdictionary����
        int count1 = 0;
        for (int j = 0; j < m; j++)
        {
            if (cur2[i][c] == cur1[j])//�Ƚ���ͬ����ͬ++
            {
                c++;
                count1++;
            }
            if (cur2[i][c] == '\0')//dictionary������
            {
                break;
            }
        }
        //2�ֿ��ܣ�1dictionary�����ˣ�2j��С��m��
        if (cur2[i][c] != '\0')
        {
            count1 = 0;
        }

        if (count == count1)
        {
            for (int j = 0; cur2[i][j] != '\0'; j++)//�ж����ͬ���ַ�����ȡ��ĸ��С��
            {
                if (cur2[ri][j] > cur2[i][j])
                {
                    ri = i;
                    count = count1;
                    break;
                }
                else if (cur2[ri][j] < cur2[i][j])
                {
                    break;
                }
            }
        }
        else if (count < count1)//�ж����ڵ�dictionary��i���Ƿ����
        {
            ri = i;
            count = count1;
        }
    }
    char* cnums = "";
    if (count == 0)//û�з��ϵķ��ؿ��ַ���
    {
        return cnums;
    }
    return dictionary[ri];
}