/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int>m;
        if(nums1.size()==0&&nums2.size()!=0)
            return nums2;
        if(nums2.size()==0&&nums1.size()!=0)
            return nums1;
        if(nums1.size()==0&&nums2.size()==0)
            return m;
        vector<int> v(nums1.size()+nums2.size(),0);
        int i=0;
        auto it1=nums1.begin(),it2=nums2.begin();
        for(;it1!=nums1.end()&&it2!=nums2.end();){
            if(*it1<=*it2){
                v[i]=*it1;
                ++i;
                ++it1;
            }
            else{
                v[i]=*it2;
                ++i;
                ++it2;
            }
        }
        while(it1!=nums1.end()){
            v[i++]=*it1;
            ++it1;
        }
         while(it2!=nums2.end()){
            v[i++]=*it2;
            ++it2;
        }
        return v;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>v=merge(nums1,nums2);
        
        int position=v.size()/2;
        if(v.size()%2==0){
            return (v[position]*1.0+v[position+1])/2.0;
        }
        if(v.size()%2==1){
            return v[position]*1.0;
        }
        return 0;
    }
};

