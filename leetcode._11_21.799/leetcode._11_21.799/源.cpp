class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> v1;
        //���ȷ��ڵ�һ������
        v1.push_back((double)poured);
        for (int i = 1; i <= query_row; i++)
        {
            vector<double> next(i + 1, 0.0);
            for (int j = 0; j < v1.size(); j++)
            {
                if (v1[j] > 1)
                {
                    //������һ�ε�����
                    next[j] += (v1[j] - 1) / 2;
                    next[j + 1] += (v1[j] - 1) / 2;
                }
            }
            v1 = next;
        }
        return min(1.0, v1[query_glass]);
    }
};