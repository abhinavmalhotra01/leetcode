function canMakeArithmeticProgression(arr: number[]): boolean {
    arr = arr.sort((n1,n2) => n1 - n2);
    var a1 = arr[1]-arr[0];
    for(let i=1;i<arr.length-1;i++){
        if(a1 !== arr[i+1]-arr[i]){
            return false;
        }
    }
    arr.reverse();
    a1=arr[1]-arr[0];
    for(let i=1;i<arr.length-1;i++){
        if(a1 !== arr[i+1]-arr[i]){
            return false;
        }
    }
    return true
};