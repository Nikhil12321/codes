#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> chars(char s){
    std::vector<string> v2;
    v2.push_back("a");
    v2.push_back("b");
    v2.push_back("c");
    std::vector<string> v3;
    v3.push_back("d");
    v3.push_back("e");
    v3.push_back("f");
    std::vector<string> v4;
    v4.push_back("g");
    v4.push_back("h");
    v4.push_back("i");
    std::vector<string> v5;
    v5.push_back("j");
    v5.push_back("k");
    v5.push_back("l");
    std::vector<string> v6;
    v6.push_back("m");
    v6.push_back("n");
    v6.push_back("o");
    std::vector<string> v7;
    v7.push_back("p");
    v7.push_back("q");
    v7.push_back("r");
    v7.push_back("s");
    std::vector<string> v8;
    v8.push_back("t");
    v8.push_back("u");
    v8.push_back("v");
    std::vector<string> v9;
    v9.push_back("w");
    v9.push_back("x");
    v9.push_back("y");
    v9.push_back("z");
    switch(s){
        case '2': return v2;
        break;
        case '3':return v3;
        break;
        case '4':return v4;
        break;
        case '5':return v5;
        break;
        case '6':return v6;
        break;
        case '7':return v7;
        break;
        case '8':return v8;
        break;
        case '9':return v9;
        break;
        default:return v2;
    }
}
vector<string> letterCombinations(string digits) {
    std::vector<string> v;
    if(digits.size()==0)
        return v;
    string empty = "";
    v.push_back(empty);
    int n = digits.size();
    int i, j, k, number;

    for(i=n-1; i>=0; i--){
        number = digits[i]-'0';
        std::vector<string> tt = chars(digits[i]);
        
        vector<string> temp(v);
            v.clear();
        for(j=0; j<tt.size(); j++){
            
            for(k=0; k<temp.size(); k++){
                v.push_back(tt[j] + temp[k]);
                
            }
        }
    }
    return v;
}

int main(){
    string num;
    cin>>num;
    std::vector<string> ans = letterCombinations(num);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout<<ans[i]<<endl;
    }
}
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/