# python
def merge(arr, dict):
    if len(arr) == 1:
        return arr
    middle = len(arr) // 2
    left, right = arr[:middle], arr[middle:]
    merge(left, dict)
    merge(right, dict)
    index_left = index_right = index = 0
    result = [0] * (len(left) + len(right))
    while index_left < len(left) and index_right < len(right):
        if dict[left[index_left]] <= dict[right[index_right]]:
            result[index] = left[index_left]
            index_left += 1
        else:
            result[index] = right[index_right]
            index_right += 1
        index += 1
    while index_left < len(left):
        result[index] = left[index_left]
        index_left += 1
        index += 1
    while index_right < len(right):
        result[index] = right[index_right]
        index_right += 1
        index += 1
    for i in range(len(arr)):
        arr[i] = result[i]
        print(arr[i], end=' ')
    print()
    return arr


if __name__ == "__main__":
    n = int(input())
    arr = []
    dict={}
    for i in range(n):
        m = int(input())
        summa = 0
        numbers = 0
        for j in range(m):
            numbers = list(map(int, input().split()))
            summa += numbers[j]

        dict[i]=summa
    for i in range(len(merge(arr,dict))):
        print(arr[i], end=' ')
    print()
