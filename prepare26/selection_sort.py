
from signal import NSIG


def selection_sort(nums: list[int]) -> None:
    nsize = len(nums)
    if nsize <= 1:
        return
    for i in range(nsize):
        for j in range(i+1, nsize):
            if nums[j] < nums[i]:
                nums[i], nums[j] = nums[j], nums[i]
        print(nums)

def selection_sort_2(nums: list[int]) -> None:
    nsize = len(nums)
    if nsize <= 1:
        return

    for i in range(nsize):
        minIndex = i
        for j in range(i+1, nsize):
            if nums[j] < nums[minIndex]:
                minIndex = j
        nums[i], nums[minIndex] = nums[minIndex], nums[i]
        print(nums)

if __name__ == "__main__":
    nums = [5, 4, 3, 2, 1]
    selection_sort(nums)
    print("*" * 10)
    print(nums)