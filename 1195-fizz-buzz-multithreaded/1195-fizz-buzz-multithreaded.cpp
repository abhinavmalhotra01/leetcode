class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        i=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(!(i%5 && !(i%3)) && i<=n){
                cv.wait(lock);
            }
            if(i>n){break;}
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(!(i%3 && !(i%5)) && i<=n){
                cv.wait(lock);
            }
            if(i>n){break;}
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(!(i%3==0 && i%5==0) && i<=n){
                cv.wait(lock);
            }
            if(i>n){break;}
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(!(i%3 && i%5) && i<=n){
                cv.wait(lock);
            }
            if(i>n){break;}
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};