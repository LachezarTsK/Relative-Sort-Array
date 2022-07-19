
/**
 * @param {number[]} toSort
 * @param {number[]} distictElements
 * @return {number[]}
 */
var relativeSortArray = function (toSort, distictElements) {
    const RANGE_VALUES = [0, 1000];
    const frequency = new Array(RANGE_VALUES[1] + 1).fill(0);

    for (let n of toSort) {
        ++frequency[n];
    }

    let indexSorted = 0;
    for (let n of distictElements) {
        while (frequency[n] > 0) {
            toSort[indexSorted] = n;
            --frequency[n];
            ++indexSorted;
        }
    }

    for (let n = RANGE_VALUES[0]; n <= RANGE_VALUES[1]; ++n) {
        while (frequency[n] > 0) {
            toSort[indexSorted] = n;
            --frequency[n];
            ++indexSorted;
        }
    }

    return toSort;
};
