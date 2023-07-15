class MedianFinder {
    priority_queue<int> pq;
    multiset<int> ms;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.size()!=ms.size()){
            // if(ms.size()==0){
                if(num>=pq.top()){
                    ms.insert(num);
                }else{
                    int a = pq.top();
                    pq.pop();
                    ms.insert(a);
                    pq.push(num);
                }
        }else{
            if(pq.size()==0){
                pq.push(num);
            }else{
                if(num>=*ms.begin()){
                    pq.push(*ms.begin());
                    ms.erase(ms.begin());
                    ms.insert(num);
                }else{
                    pq.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(pq.size()==ms.size()){
            double a = *ms.begin();
            return (double)(a+pq.top())/2;
        }else{
            return pq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */