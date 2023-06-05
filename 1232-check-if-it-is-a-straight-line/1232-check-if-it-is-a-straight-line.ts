function checkStraightLine(coordinates: number[][]): boolean {
    const x1 = coordinates[0][0];
    const y1 = coordinates[0][1];
    const x2 = coordinates[1][0];
    const y2 = coordinates[1][1];
    if(x2===x1){
        for(let i=0;i<coordinates.length;i++){
            if(coordinates[i][0]!==x2){
                return false;
            }
        }
        return true;
    }
    const m = (y2-y1)/(x2-x1);
    console.log(m);
    const c = y1-m*x1;
    for(let i=0;i<coordinates.length;i++){
        const curx = coordinates[i][0];
        const cury = coordinates[i][1];
        if(cury!== m*curx+c){
            return false;
        }
    }
    return true;
};