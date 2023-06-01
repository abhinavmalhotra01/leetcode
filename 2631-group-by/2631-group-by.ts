declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function(fn) {
    const out: Record<string,any[]> = {};
    // for(let i=0;i<this.length;i++){
    //     // console.log(this[i]+" "+fn(this[i]));\\
    //     console.log(this[i]);
    //     const curr = fn(this[i]);
    //     // console.log(curr);
    //     if(curr in out){
    //         console.log(curr)
    //         console.log(typeof out[curr])
    //         console.log(typeof out)
    //         out[curr].push(this[i]);
    //     }else{
    //         out[curr]=this[i];
    //     }
    // }
    for (const item of this) {
        console.log(item)
    const key = fn(item);
    if (key in out) {
        console.log(key)
            console.log(typeof out[key])
            console.log(typeof out)
      out[key].push(item);
    } else {
      out[key] = [item];
    }
  }
    return out;
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */