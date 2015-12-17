//Given an integer array, heapify it into a min-heap array.
//For a heap array A, A[0] is the root of heap
//For each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
//Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.
//Requirement: O(n) time complexity
//Min-heap: for each element A[i], A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n <= 1) return;
        
        int i = n/2-1;
        int left, right, cur;
        
        while(i >= 0) {
            cur = i;
            left = cur*2+1;
            right = cur*2+2;
            
            while(((left < n) && (A[left] < A[cur])) || ((right < n) && (A[right] < A[cur]))) {
                
                if(right >= n) {
                    
                    swap(A[cur],A[left]);
                    cur = left;
                    
                } else {
                    
                    if(A[left] > A[right]) {
                        swap(A[cur],A[right]);
                        cur = right;
                    } else {
                        swap(A[cur],A[left]);
                        cur = left;
                    }
                }
                
                left = cur*2+1;
                right = cur*2+2;
            }
            
            i--;
        }
        
        return;
        
    }
};
