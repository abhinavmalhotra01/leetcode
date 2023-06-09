class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int g = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(g==letters.size()){
            return letters[0];
        }
        return letters[g];
    }
};