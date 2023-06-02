function* fibGenerator(): Generator<number> {
    let prev1 = 0;
    let prev2 = 1;

    while(true) {
        yield prev1;
        const temp = prev1;
        prev1 = prev2;
        prev2 += temp;
    }
};
