class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length; 
        int n = nums2.length;
        int arr[] = new int[m+n];
        int a = 0;
        int b = 0;
        int c = 0;
        while(a < m && b < n){
            if(nums1[a] <= nums2[b] ){
                arr[c] = nums1[a];
                c++;
                //list.add(nums1[a]);
                a++;
            } else {
                arr[c] = nums2[b];
                c++;
                //list.add(nums2[b]);
                b++;
            }
        }
        while(a < m){
            arr[c] = nums1[a];
            c++;
            a++;
        }
        while (b < n ){
            arr[c] = nums2[b];
            c++;
            b++;
        }
        int s = arr.length;
        if(s % 2  == 0){
            return ((double) (arr[s/2 - 1] + arr[s/2])/ 2) ;
        } else return arr[s/2];
    }
}
