type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    const arr = {};
    return function(...args) {
       const curr = JSON.stringify(args);
        if(curr in arr){
            return arr[curr];
        }
        let out = fn(...args);
        arr[curr]=out;
        return arr[curr];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */