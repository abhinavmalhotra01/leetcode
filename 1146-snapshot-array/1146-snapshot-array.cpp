class SnapshotArray {
    vector<map<int,int>> arr;
    int c;
public:
    SnapshotArray(int length) {
        arr.resize(length);
        for(int i = 0; i < length; i++)
            arr[i][0] = 0;
        c=0;
    }
    
    void set(int index, int val) {
        // auto &e = arr[index];
        // if(e.count(c)>0){
        //     e[c]=val;
        // }else{
        //     // cout<<c<<" "<<val<<endl;
        //     e.insert({c,val});
        //     // cout<<e[c]<<endl;
        // }
        arr[index][c]=val;
    }
    
    int snap() {
        c++;
        return c-1;
    }
    
    int get(int index, int snap_id) {
        // for(auto f :e){
            // cout<<f.first<<" "<<f.second<<endl;
        // }
        // cout<<snap_id<<" "<<e[snap_id]<<endl;
        if(arr[index].count(snap_id)==0){
            auto i = arr[index].lower_bound(snap_id);
            i--;
            return i->second;
        }
        return arr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */