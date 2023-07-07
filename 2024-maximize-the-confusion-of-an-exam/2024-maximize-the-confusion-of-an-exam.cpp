class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int out=0;
        int i=0,j=0;
        int cnt=0;
        while(j<answerKey.size()){
            if(answerKey[j]=='T'){
                cnt++;
            }
            while(i<answerKey.size() && cnt>k){
                if(answerKey[i]=='T'){cnt--;}i++;
            }
            out=max(out,j-i+1);
            j++;
        }
        i=0;j=0;cnt=0;
        while(j<answerKey.size()){
            if(answerKey[j]=='F'){
                cnt++;
            }
            while(i<answerKey.size() && cnt>k){
                if(answerKey[i]=='F'){cnt--;}i++;
            }
            out=max(out,j-i+1);
            j++;
        }
        return out;
    }
};