class ZeroEvenOdd {
private:
    int n;
    int i;
    int f;
    mutex m;
    condition_variable c;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        f=0;
        i=1;
    }
    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(f!=0 && i<=n){
                c.wait(lock);
            }
            if(i>n){break;}
            printNumber(0);
            f = (i%2==0) ? 2 : 1;
            c.notify_all();
        }
    }
    void even(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(f!=2 && i<=n){
                c.wait(lock);
            }
            if(i>n){break;}
            printNumber(i++);
            f = 0;
            c.notify_all();
        }
    }
    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(f!=1 && i<=n){
                c.wait(lock);
            }
            if(i>n){break;}
            printNumber(i++);
            f=0;
            c.notify_all();
        }
    }
};