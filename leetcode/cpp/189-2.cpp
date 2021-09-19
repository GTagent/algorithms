class Solution 
{
public:
    // Start from one element and keep rotating until we have rotated n different elements.
    // code from zhukov
    void rotate(int nums[], int n, int k) 
    {
        if ((n == 0) || (k <= 0))
        {
            return;
        }
        
        int cntRotated = 0;
        int start = 0;
        int curr = 0;
        int numToBeRotated = nums[0];
        int tmp = 0;
        // Keep rotating the elements until we have rotated n 
        // different elements.
        while (cntRotated < n)
        {
            do
            {
                tmp = nums[(curr + k)%n];
                nums[(curr+k)%n] = numToBeRotated;
                numToBeRotated = tmp;
                curr = (curr + k)%n;
                cntRotated++;
            } while (curr != start);
            // Stop rotating the elements when we finish one cycle, 
            // i.e., we return to start.
            
            // Move to next element to start a new cycle.
            start++;
            curr = start;
            numToBeRotated = nums[curr];
        }
    }
};