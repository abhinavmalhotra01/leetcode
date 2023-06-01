const movements = [
    { x: 0, y: 1 },
    { x: 0, y: -1 },
    { y: 0, x: -1 },
    { y: 0, x: 1 },
    { x: 1, y: 1 },
    { x: 1, y: -1 },
    { y: 1, x: -1 },
    { y: -1, x: -1 },
]

function safeToMove(x: number, y: number, grid: number[][]) {
    return x >= 0 && x < grid.length && y >= 0 && y < grid.length && grid[y][x] === 0;
}

function shortestPathBinaryMatrix(grid: number[][]): number {
    const n = grid.length;

    if (grid[n-1][n-1] === 1 || grid[0][0] === 1) {
        return -1;
    }

    const queue: { x: number, y: number, count: number }[] = [{ x: 0, y: 0, count: 1 }];
    grid[0][0] = 1;

    while (queue.length > 0) {
        const { x, y, count } = queue.shift()!;
        // console.log({x,y,count})
        if (x === n-1 && y === n-1) {
            return count;
        } else {
            for (const movement of movements) {
                const nextX = x + movement.x;
                const nextY = y + movement.y;
				
                if (safeToMove(nextX, nextY, grid)) {
                    queue.push({ x: nextX, y: nextY, count: count + 1 })
                    grid[nextY][nextX] = 1;
                }
            }
        }
    }

    return -1;
};