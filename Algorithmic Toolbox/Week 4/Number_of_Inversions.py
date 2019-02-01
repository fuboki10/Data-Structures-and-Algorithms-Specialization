#python3

def merge(left,right):

    result = []
    inversion = 0
    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
            inversion += len(left)
    result += left or right
    return result, inversion


def merge_sort(a):
    if len(a) == 1:
        return a, 0

    m = len(a)//2
    left, left_inv = merge_sort(a[:m])
    right, right_inv = merge_sort(a[m:])
    merged, merged_inv = merge(left, right)
    return merged, merged_inv + left_inv + right_inv

n = input()
a = list(map(int, input().split()))
merged, inversions = merge_sort(a)
print(inversions)