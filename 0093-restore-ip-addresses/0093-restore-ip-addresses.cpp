class Solution {
public:
    bool valid(string temp)
{
    if(temp.size()==0 || temp.size()>3 ||(temp.size()>1 && temp[0]=='0') || stoi(temp)>255)
    {
        return false;
    }
    return true;
}

void Rec(int indx, string s, string temp, vector<string> &ans, int dots)
{
    if(dots==0)
    {
        if(indx==s.size())
        {
            ans.push_back(temp.substr(0, temp.size()-1));
        }
        return;
    }

    for(int i =indx;i<s.size();i++)
    {
        if(valid(s.substr(indx, i-indx+1)))
        {
            temp.push_back(s[i]);
            temp.push_back('.');
            Rec(i+1, s, temp, ans, dots-1);
            temp.pop_back();
        }
    }

}

vector<string> restoreIpAddresses(string s) {
    string temp;
    vector<string> ans;
    Rec(0, s, temp, ans, 4);
    return ans;
}
};