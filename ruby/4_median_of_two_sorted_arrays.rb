# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}


def find_kth(nums1, nums2, k)
  m = nums1.length
  n = nums2.length

  return find_kth(nums2, nums1, k) if m > n # assume nums1 length less than nums2 length
  return nums2[k-1] if m == 0
  return [nums1[0], nums2[0]].min if k == 1

  i = [m, k/2].min
  j = [n, k/2].min

  if nums1[i-1] > nums2[j-1]
    return find_kth(nums1, nums2[j...n], k-j)
  else
    return find_kth(nums1[i...m], nums2, k-i)
  end
end


def find_median_sorted_arrays(nums1, nums2)
  m = (nums1.length + nums2.length + 1) / 2
  n = (nums1.length + nums2.length + 2) / 2

  return ( find_kth(nums1, nums2, m) + find_kth(nums1, nums2, n) ) / 2.0
end


puts find_median_sorted_arrays([1, 2], [3, 4])
