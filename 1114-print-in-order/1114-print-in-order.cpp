class Foo {
    int f;
    mutex m;
    condition_variable c;
public:
    Foo() {
        f=0;
    }
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        // if(!f){
        // printFirst();
        // f++;
        // }
        printFirst();
        f=1;
        c.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        // printSecond() outputs "second". Do not change or remove this line.
        // if(f==1){
        //     printSecond();
        //     f++;
        // }
        while(f!=1){
            c.wait(lock);
        }
        printSecond();
        f=2;
        c.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        // printThird() outputs "third". Do not change or remove this line.
        while(f!=2){
            c.wait(lock);
        }
        printThird();
        
    }
};