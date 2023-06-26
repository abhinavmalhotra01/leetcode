class Solution {
public:
    int bestClosingTime(string s) {
        vector<int> Ncnt(s.size(),0);
        vector<int> Ycnt(s.size(),0);
        int i=0,j=s.size()-1;
        if(s[i]=='N'){Ncnt[i]=1;}else{Ncnt[i]=0;}
        i++;
        if(s[j]=='Y'){Ycnt[j]=1;}else{Ycnt[j]=0;}
        j--;
        while(i<s.size() && j>=0){
            if(s[i]=='N'){
                Ncnt[i]=Ncnt[i-1]+1;
            }else{
                Ncnt[i]=Ncnt[i-1];
            }
            if(s[j]=='Y'){
                Ycnt[j]=Ycnt[j+1]+1;
            }else{
                Ycnt[j]=Ycnt[j+1];
            }
            i++;j--;
        }
        int out=INT_MAX,ans=0;
        for(int i=0;i<s.size();i++){
            // cout<<Ncnt[i]<<" "<<Ycnt[i]<<endl;
            // out=min(out,Ncnt[i]+Ycnt[i]);
            if(Ncnt[i]+Ycnt[i]<out){ans=i;out=Ncnt[i]+Ycnt[i];}
        }
        // if(ans){return ans+1;}
        if(!ans){
            return s[0]=='Y';
        }
        return ans+1;
    }
};