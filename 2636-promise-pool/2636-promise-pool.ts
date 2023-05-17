type F = () => Promise<any>;

async function promisePool(functions: F[], n: number): Promise<any> {
    return new Promise((resolve) => {
        let curr = 0;
        let i = 0;
        function rec() {
            if (i == functions.length) {
                if (curr === 0) resolve(0);
                return;
            }

            while (curr < n && i< functions.length) {
                curr++;
                const promise = functions[i]();
                i++;
                promise.then(() => {
                    curr--;
                    rec();
                });
            }
        }
        rec();
    });
};;

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */