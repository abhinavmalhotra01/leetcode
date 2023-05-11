/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    // console.log(functions[1](2))
	return function(x) {
        for(let i=functions.length-1;i>=0;i--){
            x=functions[i](x);
        }
        // console.log(x)
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */