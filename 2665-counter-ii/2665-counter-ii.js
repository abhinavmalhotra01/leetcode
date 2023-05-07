/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currVal = init;
    function increment(){
        currVal+=1;
        return currVal;
    }
    function decrement(){
        currVal-=1;
        return currVal;
    }
    function reset(){
        currVal = init;
        return init;
    }
    return {increment,decrement,reset}
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */