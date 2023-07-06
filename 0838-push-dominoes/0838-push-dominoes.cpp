class Solution{
    public:
    string pushDominoes(string s) {
        int n = s.size(), r = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                if (r == -1) { 
                    for (int j = i - 1; j >= 0 && s[j] == '.'; j--) {
                      s[j] = 'L';  
                    } 
                } else {
                    for (int j = r + 1, k = i - 1; j < k; ++j, --k) {
                        s[j] = 'R';
                        s[k] = 'L';
                    } 
                    r = -1;
                }
            } else if (s[i] == 'R') {
                if (r != -1) {
                    for (int j = r + 1; j < i; ++j){
                         s[j] = 'R';
                    }
                }
                r = i;
            }
        }
        if (r != -1) {
            for (int j = r + 1; j < n; j++){
                s[j] = 'R';
            }
        }
        return s;
    }
};