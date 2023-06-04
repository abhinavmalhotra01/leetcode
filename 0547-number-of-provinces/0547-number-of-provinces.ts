function dfs(isConnected:number[][],vis:number[],i:number,n:number):void{
    vis[i]=1;
    for(let k =0;k<n;k++){
        if(i==k){continue;}
        // console.log(i,k);
        if(!vis[k] && isConnected[i][k]===1 ){
            // console.log(i,k);
            dfs(isConnected,vis,k,n);
        }
    }
}
function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    var vis = Array(n+10).fill(0);
    let out =0;
    for(let i=0;i<n;i++){
        if(!vis[i]){
            dfs(isConnected,vis,i,n);
            out+=1;
        }
    }
    return out;
};