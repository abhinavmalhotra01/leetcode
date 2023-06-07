function decToBinary(n:number):string
{
    let out:string;
    // Size of an integer is assumed to be 32 bits
    for (let i = 31; i >= 0; i--) {
        let k = n >> i;
        if (k & 1){
            out+='1'
        }else{
            out+='0'
        }
    }
    return out;
}
function minFlips(a: number, b: number, c: number): number {
    const s = decToBinary(a);
    const f = decToBinary(b);
    const d = decToBinary(c);
    let out=0;
    for(let i=0;i<d.length;i++){
        if(d[i]=='0'){
            if(s[i]=='1' && f[i]=='1'){
                out+=2;
            }else if(s[i]=='1' || f[i]=='1'){
                out++;
            }
        }else{
            if(s[i]=='0' && f[i]=='0'){
                out++;
            }
        }
    }
    return out;
}