class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        long long a=0,b=0;
        while(i<version1.size() || j<version2.size()){
        //     if(version1[i]>version2[j]){
        //         return 1;
        //     }
        //     else if(version2[j]>version1[i]){
        //         return -1;
        //     }
            
            
            while(i<version1.size() && version1[i]!='.'){
                // while(version1[i]==0){i++;}
                a=a*10+(version1[i]-'0');i++;
            }
            while(j<version2.size() && version2[j]!='.'){
                // while(version2[j]==0){j++;}
                b=b*10+(version2[j]-'0');j++;
            }
        //     cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
            if(a>b){
                return 1;
            }
            else if(b>a){
                return -1;
            }
            a=0,b=0;
            i++;j++;
        }
        // if(a>b){return 1;}
        // if(b<a){return -1;}
        return 0;
    }
};