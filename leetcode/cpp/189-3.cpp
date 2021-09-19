class Solution 
{
public:
    // Reverse the first n - k elements, the last k elements, and then all the n elements.
    // code from zhukov
    void rotate(int nums[], int n, int k) 
    {
        k = k%n;

        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums, nums + n - k);
        
        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums + n - k, nums + n);
        
        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums, nums + n);
    }
};