class Solution {
    map<pair<int,int>,int>m;
    int rec(int i, vector<int>& arr,vector<int>& arr2,int pr){
        if(i>=arr.size()){return 0;}
        if(m.count({i,pr})>0){
            return m[{i,pr}];
        }
        int r1=1e9+1;
        if(arr[i]>pr){
            r1=rec(i+1,arr,arr2,arr[i]);
        }
        int r2=1e9+1;
        auto it = upper_bound(arr2.begin(),arr2.end(),pr);
        if(it!=arr2.end()){
            int j = it-arr2.begin();
            r2=1+rec(i+1,arr,arr2,arr2[j]);
        }
        m[{i,pr}]=min(r1,r2);
        return m[{i,pr}];
    }    
public:
    int makeArrayIncreasing(vector<int>& arr, vector<int>& arr2) {
//         multiset<int> s;
//         for(auto e:arr2){s.insert(e);}
//         int out =0;
//         if(arr[0]>arr[1]){
//             if(*s.begin()<arr[1]){
//                 out++;
//                 arr[0]=*s.begin();
//                 s.erase(s.begin());
//             }else{
//                 return -1;
//             }
//         }
//         if(arr[arr.size()-1]<arr[arr.size()-2]){
//             out++;
//             if(*s.end()>arr[arr.size()-2]){
//                 out++;
//                 arr[arr.size()-1]=*s.end();
//                 s.erase(s.end());
//             }else{
//                 return -1;
//             }
//         }
//         for(int i=1;i<arr.size()-2;i++){
//             if(arr[i]<arr[i+1] && arr[i]>arr[i-1]){continue;}
//             // if(arr[i+1]<=arr[i]){
//                 int y = *s.upper_bound(arr[i-1]);
//                 if(y>arr[i+1]){return -1;}
//                 else{s.erase(s.upper_bound(arr[i-1]));out++;arr[i]=y;}
//         }
//         for(int i=0;i<arr.size()-1;i++){
//             if(arr[i]>=arr[i+1]){return -1;}
//         }
//         return out;
        // map<pair<int,int>,int> m;
        m.clear();
        sort(arr2.begin(),arr2.end());
        int out = rec(0,arr,arr2,INT_MIN);
        if(out>=1e9){
            return -1;
        }
        return out;
    }
};