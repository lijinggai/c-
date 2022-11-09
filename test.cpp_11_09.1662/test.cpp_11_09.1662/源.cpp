class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str3;
        int index = 0;
        for (auto str1 : word1)
        {
            for (auto ch1 : str1)
            {
                str3.push_back(ch1);
                index++;
            }
        }
        int i = 0;
        for (auto str2 : word2)
        {
            for (auto ch2 : str2)
            {
                if (str3[i] != ch2)
                {
                    return false;
                }
                i++;
            }
        }
        //����һ���Ľ�������һ����������
        if (i != index && i != str3.size())
        {
            return false;
        }
        return true;
    }
};