class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dig, out;
        vector<pair<string, string>> let;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' '){ ++i;}
            if (isalpha(s[i + 1])) {let.emplace_back(s.substr(0, i), s.substr(i + 1));}
            else {dig.push_back(s);}
        }
        sort(let.begin(), let.end(), [&](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for (auto &p : let){ out.push_back(p.first + " " + p.second);}
        for (string &s : dig){ out.push_back(s);}
        return out;
    }
};