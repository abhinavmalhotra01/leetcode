function summaryRanges(nums: number[]): string[] {
    let f :string[]=[];
    let i=0,j=0;
    while(j<nums.length){
        if(nums[j+1]==nums[j]+1){
            j++;
        }else{
            if(nums[j]==nums[i]){
                f.push(nums[i].toString());
            }else{
            f.push(nums[i]+"->"+nums[j]);
            }
            j++;i=j;
        }
    }
    return f;
};