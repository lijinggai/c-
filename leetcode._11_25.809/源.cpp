class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ret = words.size();
        for (auto& word : words)
        {
            int i = 0, j = 0;
            while (i < s.size() || j < word.size())
            {
                //������һ�������ˣ���һ��û����
                if (i == s.size() || j == word.size())
                {
                    ret--;
                    break;
                }
                //Ԫ�ز�ͬ
                if (s[i] != word[j])
                {
                    ret--;
                    break;
                }
                int counti = 0;
                char chi = s[i];
                while (i < s.size() && s[i] == chi)
                {
                    counti++; i++;
                }
                int countj = 0;
                char chj = word[j];
                while (word[j] == chj)
                {
                    countj++; j++;
                }
                //��������
                if (countj > counti)
                {
                    ret--;
                    break;
                }
                //����ͬ��s��ĳһ��Ԫ������С��3
                if (counti != countj && counti < 3)
                {
                    ret--;
                    break;
                }
            }
        }
        return ret;
    }
};