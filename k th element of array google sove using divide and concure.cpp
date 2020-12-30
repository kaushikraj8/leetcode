/*Given two sorted arrays nums1 and nums2 of size m and n respectively and an int k. Find the k-th largest element of these arrays.
Note that it is the k-th largest element in the sorted order, not the k-th distinct element.

Example 1:

Input: nums1 = [-2, -1, 3, 5, 6, 8], nums2 = [0, 1, 2, 5, 9], k = 4
Output: 5
Explanation: Union of above arrays will be [-2, -1, 0, 1, 2, 3, 5, 5, 6, 8, 9] and the 4th largest element is 5.

Example 2:

Input: nums1 = [2, 4], nums2 = [6], k = 1
Output: 6
Explanation: union of above arrays will be [2, 4, 6] and the 1st largest element is 6.

You may assume k is always valid, 1 ≤ k ≤ m + n.*/
def kthLargest(nums1, nums2, k):
    
    N1, N2 = len(nums1), len(nums2)
    
    if N1 + N2 < k:
        return float('inf')
    
    i = N1 - 1
    j = N2 - 1
    current = float('inf')
    
    while k > 0 and i >= 0 and j >= 0:
        # print(i, j, nums1[i], nums2[j])
        if nums1[i] > nums2[j]:
            current = nums1[i]
            i -= 1
        else:
            current = nums2[j]
            j -= 1
        # print(current, k)
        k -= 1
    return current if k == 0 else (nums2[j-k+1] if i < 0 else nums1[i-k+1])

print(kthLargest([-2, -1, 3, 5, 6, 8], [0, 1, 2, 5, 9], 4))
print('-' * 20)
print(kthLargest([1,2,3,4,5], [5], 3))
    





int getKLargeVal(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    int n1Lo = k > n ? 0 : n-k, n1Hi = n-1, n2Lo = k > m ? 0 : m-k, n2Hi = m-1;
    int n1Mid, n2Mid, nth, mth;
    
    if (nums1[n1Lo] > nums2[n2Hi]) return nums1[n1Lo];
    if (nums2[n2Lo] > nums1[n1Hi]) return nums2[n2Lo];
    
    while (n1Lo <= n1Hi && n2Lo <= n2Hi) {
        n1Mid = (n1Lo + n1Hi)/2; n2Mid = (n2Lo + n2Hi)/2;
        nth = n - n1Mid, mth = m - n2Mid;
        //cout << n1Lo << " : " << n1Hi << " : " << n2Lo << " : " << n2Hi << endl;
        
        if (nums1[n1Mid] == nums2[n2Mid]) {
            if (nth + mth == k) return nums1[n1Mid];
            else if (nth + mth < k) {
                n1Hi = n1Mid;
                n2Hi = n2Mid;
            }
            else {
                n1Lo = n1Mid;
                n2Lo = n2Mid;
            }
        }
        else if (nums1[n1Mid] > nums2[n2Mid]) {
            if (nth + mth == k) {
                if (n1Mid == 0 || nums2[n2Mid] >= nums1[n1Mid-1]) return nums2[n2Mid];
                n1Hi = n1Mid - 1;
                n2Lo = n2Mid + 1;
            }
            if (nth + mth > k) n2Lo = n2Mid + 1;
            else n1Hi = n1Mid - 1;
        }
        else {
            if (nth + mth == k) {
                if (n2Mid == 0 || nums1[n1Mid] >= nums2[n2Mid-1]) return nums1[n1Mid];
                n2Hi = n2Mid - 1;
                n1Lo = n1Mid + 1;
            }
            if (nth + mth > k) n1Lo = n1Mid + 1;
            else n2Hi = n2Mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums1, nums2;
    nums1.push_back(-2);
    nums1.push_back(-1);
    nums1.push_back(3);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(8);
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(9);
    cout << getKLargeVal(nums1, nums2, 4) << endl;
}