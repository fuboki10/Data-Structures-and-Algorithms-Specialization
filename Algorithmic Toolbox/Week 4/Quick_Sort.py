def quick_sort(a):
    if len(a) <= 1:
        return a
    pivot = a[0]
    less = [x for x in a if x < pivot]
    equal = [x for x in a if x == pivot]
    greater = [x for x in a if x > pivot]
    return quick_sort(less) + equal + quick_sort(greater)

n = input()
a = list(map(int, input().split()))
a = quick_sort(a)
for x in a:
    print(x, end=' ')