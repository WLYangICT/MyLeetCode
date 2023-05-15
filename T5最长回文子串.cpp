class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 1){
            return s;
        }
        int maxLen = 1;
        string maxs = "";
        maxs += s[0];
        vector<vector <bool>> IF(len, vector<bool>(len));
        for(int i=0;i<len;i++){
            IF[i][i] = true;
        }
        for(int l=2;l<=len;l++){
            for(int i=0;i<len;i++){
                int j = i + l -1;
                if(j > (len-1)){
                    break;
                }
                if(s[i] != s[j]){
                    IF[i][j] = false;
                }
                else{
                    if((j - i -1 < 2)){
                        IF[i][j] = true;
                    }
                    else{
                        if(IF[i+1][j-1]){
                            IF[i][j] = true;
                        }
                    }
                }
                if(IF[i][j]){
                    int length = j - i + 1;
                    if(length > maxLen){
                        maxs = "";
                        for(int k=i;k<=j;k++){
                            maxs += s[k];
                        }
                        maxLen = length;
                    }
                }
            }
        }
        return maxs;
    }
};