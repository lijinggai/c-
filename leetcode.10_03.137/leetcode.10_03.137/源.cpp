class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        //λ����
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            //һ�����һλ
            for (int num : nums)
            {
                //����������λ������λҲ�п�����ֵ
                total += (num >> i) & 1;
            }
            if (total % 3)
            {
                //total����Ϊx��3+1���κ���
                //total/=3;
                ret |= 1 << i;
            }
        }
        return ret;
    }
};