class Solution {
public:
    //判断一个字符串是否存在某个字符
    bool ifExist(char* arr,int count, char c){
        for(int i=0;i<count;i++){
            if(arr[i] == c){
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int* max;
        max = new int[len];
        int last = 0;
        for (int i = 0; i < len; i++)
        {
            char temp[50000];
            for(int j=i;j<=last;j++){
                temp[j-i] = s[j];
            }
            int maxlen = last - i + 1;
            for (int j = last+1; j < len; j++)
            {
                if(ifExist(temp, maxlen, s[j])){
                    break;
                }
                temp[maxlen] = s[j];
                maxlen += 1;
            }
            max[i] = maxlen;
            last = i + maxlen - 1; 
        }
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            if(max[i] > result){
                result = max[i];
            }
        }
        return result;
    }
};