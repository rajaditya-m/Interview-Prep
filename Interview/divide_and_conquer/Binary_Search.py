def bin_search(arr, target):
    n = len(arr)
    left, right = 0, n-1
    while left <= right:
        mid = left + (right-left)/2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid+1
        else:
            right = mid-1
    return -1

