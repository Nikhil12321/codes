class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        if(strs.size()==0)
            return s;
        int min = 12321;
        for(int i=0; i<strs.size(); i++)
        {
            if(strs[i].size()<min)
                min = strs[i].size();
        }
        int i;
        int flag=0;
        for(i=0; i<min; i++){
            
            char common = strs[0].at(i);
            
            for(int j=1; j<strs.size(); j++){
                if(strs[j].at(i)!=common){
                    flag = 1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        return strs[0].substr(0, i);
    }
};