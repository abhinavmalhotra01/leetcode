class FooBar {
private:
    int n;
    int ev=1;
    mutex m ;
    condition_variable c;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(ev!=1){
                c.wait(lock);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ev=0;
            c.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(ev!=0){
                c.wait(lock);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ev=1;
            c.notify_all();
        }
    }
};