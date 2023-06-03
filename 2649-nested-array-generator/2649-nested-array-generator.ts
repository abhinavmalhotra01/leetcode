type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
  if (!Array.isArray(arr)) {
    yield arr;
    return;
  }

  for (let i = 0; i < arr.length; i++) {
    yield* inorderTraversal(arr[i] as MultidimensionalArray);
  }
}
/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */