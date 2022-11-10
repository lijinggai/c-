class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int Max = values[0];
        int ans = 0;
        for (int i = 1; i < values.size(); i++)
        {
            ans = max(ans, Max + values[i] - i);

            //������ͷ����
            Max = max(Max, values[i] + i);
        }
        return ans;
    }
};