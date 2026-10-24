# 对数组 ["12-12","12-11", "12-11", "12-11", "12-13", "12-14"] 去重同时进行排序

from operator import le


def test() -> None:
    data = ["12-12", "12-11", "12-11", "12-11", "12-13", "12-14"]
    data = list(set(data))
    data = sorted(data, key=lambda s: tuple(map(int, s.split("-"))))
    print(data)

def test_bubble_sort() -> None:
    data = [7, 2, 1, 6, 3, 5, 4]
    nsize = len(data)
    print(f"nsize: {nsize}")

    for i in range(nsize-1):
        swap = False
        for j in range(nsize-1-i):
            if data[j+1] < data[j]:
                data[j+1], data[j] = data[j], data[j+1]
                swap = True
        print(data)
        if not swap:
            break
    print("*" * 10)
    print(data)

# [0,0,0,1,1,1,2,2,3,3,4]
# [1, 2, 3, 4, 5]
def removeDuplicates(nums: list[int]) -> int:
    nsize = len(nums)
    if nsize <= 1:
        return nsize
    
    left, right = 0, 0
    while right < nsize:
        tmp = right + 1
        while tmp < nsize:
            if (nums[right] == nums[tmp]):
                tmp += 1
            else:
                nums[left+1] = nums[tmp]
                left += 1
                break
        right = tmp
    
    return left + 1

if __name__ == "__main__":
    nums1 = [1, 1, 2]
    nums2 = [0,0,0,1,1,1,2,2,3,3,4]
    # print(removeDuplicates(nums1))
    print(removeDuplicates(nums2))
