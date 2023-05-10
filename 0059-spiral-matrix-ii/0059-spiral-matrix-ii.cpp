class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> out(n,vector<int>(n,0));
        int cor1 = n,cor2=n,cor3=0,cor4=1;
        int i=0,j=0;
        int curr =1;
        while(curr<=pow(n,2) && cor1>=0 && cor2>=0 && cor3<=n && cor4<=n){
            // cout<<curr<<endl;
            // cout<<"cor"<<cor1<<endl;
            while(j<cor1){
                out[i][j]=curr;
                curr++;j++;
            }
            j--;
            i++;
            cor1--;
            while(i<cor2){
                out[i][j]=curr;
                curr++;i++;
            }
            i--;
            j--;
            cor2--;
            while(j>=cor3){
                out[i][j]=curr;
                curr++;j--;
            }
            j++;
            i--;
            cor3++;
            while(i>=cor4){
                out[i][j]=curr;
                curr++;i--;
            }
            i++;
            j++;
            cor4++;
        }
        return out;
    }
};