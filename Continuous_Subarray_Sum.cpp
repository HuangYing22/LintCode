//Continuous Subarray Sum
//Given an integer array, find a continuous subarray where the sum of numbers is the biggest. 
//Your code should return the index of the first number and the index of the last number. 
//(If their are duplicate answer, return anyone)
class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int n=A.size();
        int global=A[0];
        int local=A[0];
        int startIndex=0;
        int endIndex=0;
        int startTemp=0;
        int i;
        for (i=1;i<n;i++) {
            if ((local+A[i]) > A[i]) {
                local = local + A[i];
            } else {
                local = A[i];
                startTemp = i;
            }
            if (global < local) {
                global = local;
                startIndex = startTemp;
                endIndex = i;
            }
        }
        vector<int> res;
        res.push_back(startIndex);
        res.push_back(endIndex);
    }
};
