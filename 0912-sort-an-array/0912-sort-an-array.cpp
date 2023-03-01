class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res(nums.begin(),nums.end());
        merge_sort(res,0,res.size()-1);
        return res;
    }
private:
    void merge(vector<int>& a, int start, int mid, int end) {
        int leftarray_size = mid - start + 1;
        int rightarray_size = end - mid;
        int leftarray[leftarray_size], rightarray[rightarray_size];

        for (int i = 0; i < leftarray_size; i++) {
            leftarray[i] = a[start + i];
        }
        for (int i = 0; i < rightarray_size; i++) {
            rightarray[i] = a[mid + 1 + i];
        }

        int index1 = 0, index2 = 0, index = start;
        while (index1 < leftarray_size && index2 < rightarray_size) {
            if (leftarray[index1] <= rightarray[index2]) {
                a[index] = leftarray[index1];
                index1++;
            }
            else {
                a[index] = rightarray[index2];
                index2++;
            }
            index++;
        }

        while (index1 < leftarray_size) {
            a[index] = leftarray[index1];
            index++, index1++;
        }
        while (index2 < rightarray_size) {
            a[index] = rightarray[index2];
            index++, index2++;
        }
    }

    void merge_sort(vector<int>& a, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
};