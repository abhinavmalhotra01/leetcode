class Solution {
    string to_bin(int n){
        string out;
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                out.push_back('1');
            }else{
                out.push_back('0');
            }
        }
        return out;
    }
    long long to_dec(string n){
        long long out;
        reverse(n.begin(),n.end());
        for(int i=0;i<32;i++){
            if(n[i]=='1'){
                // cout<<i<<endl;
                out+=(1<<i);
            }
        }
        return out;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right){return left;}
        // int c = left;
        string sl=to_bin(left);
        string sr=to_bin(right);
        // string sc=sl;
        // cout<<to_bin(c)<<" "<<to_bin(left)<<endl;
        int l=0;
        for(int i=0;i<32;i++){
            if(sl[i]!='0'){
                // sl[i-1]='1';
                l=i;
                break;
            }
        }
        int r=0;
        for(int i=0;i<32;i++){
            if(sr[i]!='0'){
                // sl[i-1]='1';
                r=i;
                break;
            }
        }
        // cout<<to_dec(sl)<<" "<<to_dec(sc)<<endl;
        // for(int i=)
        // cout<<to_dec(sc);
        // long long d = to_dec(sc);
        // long long out=left;
        // for(long long i=left;i<=min(d,(long long)right);i++){
        //     // cout<<out<<" "<<i<<endl;
        //     out&=i;
        //     if(!out){return 0;}
        // }
        // reverse(sr.begin(),sr.end());
        // reverse(sl.begin(),sl.end());
        // cout<<sr<<" "<<sl<<" "<<l<<endl;
        long long out=0;
        int c=0;
        for(int i=0;i<32;i++){
            if(sr[i]!=sl[i]){break;}
            if(sr[i]=='1' && sl[i]=='1'){
                c=1;
                // cout<<i<<" ";
                if(i)
                out+=(1<<(31-i));
            }
        }
        return out;
    }
};