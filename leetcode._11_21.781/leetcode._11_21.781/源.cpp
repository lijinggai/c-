class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        //����
        for (auto e : answers)
        {
            m[e]++;
        }
        int answer = 0;
        for (auto e : m)
        {
            //Ϊ0û����ͬ
            if (e.first == 0)
                answer += e.second;
            else
            {
                int i = e.second - e.first - 1;
                cout << i << ":" << e.first << ":" << e.second << endl;
                answer = answer + e.first + 1;
                //˵��ͬ1�Ŀ����ж����������ͬ1ÿ��ֻ��2��
                while (i > 0)
                {
                    answer = answer + e.first + 1;
                    i = i - e.first - 1;
                }
            }
        }
        return answer;
    }
};