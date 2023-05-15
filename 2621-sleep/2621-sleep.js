/**
 * @param {number} millis
 */
function timeout(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
async function sleep(millis) {
    await timeout(millis);
    return 0;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */