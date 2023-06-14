/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function dfs(root:TreeNode | null,curr:number[]) : void{
    if(root==null){
        return;
    }
    dfs(root.left,curr);
    curr.push(root.val);
    dfs(root.right,curr);
}
function getMinimumDifference(root: TreeNode | null): number {
    const curr:number[]=[];
    dfs(root,curr);
    let out = 1000000;
    // console.log(curr[0])
    for(let i=1;i<curr.length;i++){
        out = Math.min(curr[i]-curr[i-1],out);
    }
    return out;
};