class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=1;
        for(int i=0;i<preorder.size();i++){
            string curr;
            if(preorder[i]==','){continue;}
            while(i<preorder.size()&&preorder[i]!=','){curr.push_back(preorder[i]);i++;}
            // cout<<curr<<" ";
            n--;
            // cout<<n<<" ";
            if(n<0){return 0;}
            if(curr!="#"){n+=2;}
            // cout<<n<<endl;
        }
        return n==0;
    }
};