class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        int i=0;
        int j=0;
        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]>nums2[j])
            {
                temp.push_back(nums2[j]);
                j++;
            }
            else if(nums2[j]>=nums1[i])
            {
                temp.push_back(nums1[i]);
                i++;
            }
        }
        while(i<nums1.size())
        {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size())
        {
            temp.push_back(nums2[j]);
            j++;
        }
        if(temp.size()%2!=0)
        {
            return double(temp[temp.size()/2]);
        }
        return double(double(temp[temp.size()/2]+temp[(temp.size()/2)-1])/2);
    }
};
