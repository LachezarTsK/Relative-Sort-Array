
#include <array>
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> relativeSortArray(vector<int>& toSort, vector<int>& distictElements) {
        array<int, 2> RANGE_VALUES {0, 1000};
        vector<int> frequency(RANGE_VALUES[1] + 1);

        for (const auto& n : toSort) {
            ++frequency[n];
        }

        int indexSorted = 0;
        for (const auto& n : distictElements) {
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
};
