class ArrayWrapper {
    myArr : Array<number> = []
	constructor(nums: number[]) {
        this.myArr=nums;
    }

	valueOf() {
        const val = this.myArr.reduce((a,b)=> a+b,0);
        return val;
    }

	toString() {
        return JSON.stringify(this.myArr);
    }
};

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */