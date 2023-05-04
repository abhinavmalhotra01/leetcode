class Solution {
public:
    string predictPartyVictory(string senate) {
        int vR=0,vD=0;
        queue<int> qR,qD;
        int i=0;
        for(auto e : senate){
            if(e=='R'){
                qR.push(i);
               vR++;
            }else{
                qD.push(i);
                vD++;
            }
            i++;
        }
        while(vR>0 && vD>0){
            // cout<<"hehe"<<endl;
            int j=0;
            for(auto e: senate){
                // cout<<senate[j];
                if(e=='A'){}
                else if(e=='R'){
                    // cout<<e;
                    // cout<<j<<"R"<<endl;
                    if(qD.size()==0){
                        // cout<<1<<endl;
                        return "Radiant";
                    }
                    int y = qR.front();
                    qR.pop();
                    qR.push(y);
                    int curr = qD.front();
                    // if(curr<j){
                    //     j++;
                    //     continue;
                    // }
                    // cout<<curr<<"rmoved"<<endl;
                    qD.pop();
                    vD--;
                    senate[curr]='A';
                }
                else{
                    if(qR.size()==0){
                        // cout<<2<<endl;
                        return "Dire";
                    }
                    int y = qD.front();
                    qD.pop();
                    qD.push(y);
                  int curr = qR.front();
                   
                    // if(curr<j){
                    //     j++;
                    //     continue;
                    // }
                    // cout<<curr<<"rmoved"<<endl;
                    qR.pop();
                    vR--;
                    senate[curr]='A';
                }
                j++;
            }
        }
        if(vR==0){
            // cout<<3<<endl;
            return "Dire";
        }
        return "Radiant";
    }
};