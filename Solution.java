
public class Solution {

    public int[] relativeSortArray(int[] toSort, int[] distictElements) {

        final int[] RANGE_VALUES = {0, 1000};
        int[] frequency = new int[RANGE_VALUES[1] + 1];

        for (int n : toSort) {
            ++frequency[n];
        }

        int indexSorted = 0;
        for (int n : distictElements) {
            while (frequency[n] > 0) {
                toSort[indexSorted] = n;
                --frequency[n];
                ++indexSorted;
            }
        }

        for (int n = RANGE_VALUES[0]; n <= RANGE_VALUES[1]; ++n) {
            while (frequency[n] > 0) {
                toSort[indexSorted] = n;
                --frequency[n];
                ++indexSorted;
            }
        }

        return toSort;
    }
}
