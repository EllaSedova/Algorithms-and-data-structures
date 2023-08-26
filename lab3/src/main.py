def siftdown(j, proc):
    maxj = j
    left = 2 * j + 1
    right = 2 * j + 2
    if left < len(proc) and proc[left] < proc[maxj]:
        maxj = left
    if right < len(proc) and proc[right] < proc[maxj]:
        maxj = right
    if j != maxj:
        proc[j], proc[maxj] = proc[maxj], proc[j]
        siftdown(maxj, proc)

def process(time, proc):
    result = []
    for i in time:
        result.append([proc[0][1], proc[0][0]])
        proc[0][0] += i
        siftdown(0, proc)
    return result

if __name__ == "__main__":
    n, m = map(int, input().split())
    time = list(map(int, input().split()))
    proc = [[0, i] for i in range(n)]
    print(proc,"proc")
    print(time,"time")
    result = process(time, proc)
    print(result,"result")
    for i in result:
        print(i[0], i[1])
