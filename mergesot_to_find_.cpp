class Solution {
public:
    int mergesort(vector<int> A,int left,int right,vector<int> temp)
    {
        int mid,inv_count;
        if(right>left)
        {
            mid=(right+left)/2;
            inv_count+=mergesort(A,left,mid,temp);
            inv_count+=mergesort(A,mid+1,right,temp);
            inv_count=merge(A,temp,left,mid+1,right)
        }
        return inv_count;
    }
    int merge(std::vector<int> A,std::vector<int> temp,left,mid,right)
    {
        int i, j, k; 
        int inv_count = 0; 
        i = left; 
        j = mid; 
        k = left;
        while ((i <= mid - 1) && (j <= right)) { 
            if (arr[i] <= arr[j]) { 
                temp[k++] = arr[i++]; 
            } 
            else { 
                temp[k++] = arr[j++]; 
                inv_count = inv_count + (mid - i); 
            } 
        } 
        while (i <= mid - 1) 
            temp[k++] = arr[i++]; 
        while (j <= right) 
            temp[k++] = arr[j++]; 
        for (i = left; i <= right; i++) 
            arr[i] = temp[i]; 
        return inv_count;
    }
    bool isIdealPermutation(vector<int>& A) {
        int c=0,d=0;
        
        for(int i=A.size()-2;i>=0;i--)
        {
            if(A[i]>A[i+1])
                d++;
        }
        if(c==d)
            return true;
        return false;        
    }
};