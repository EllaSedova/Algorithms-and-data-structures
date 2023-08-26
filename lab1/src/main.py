def height(tree_data, dict, leaf):
    h = 1
    if leaf in dict.keys():
        h = dict[leaf]
    else:
        if tree_data[leaf] == -1:
            dict[leaf] = 1
        if tree_data[leaf] != -1:
            h += height(tree_data, dict, tree_data[leaf])
            dict[leaf] = h
    return h

def get_h(tree_data,len):
    t = 0
    dict = {}
    for i in range(len):
        temp = height(tree_data, dict, i)
        t=max(t, temp)
    return t

if __name__ == '__main__':
    len = int(input())
    tree_data= list(map(int, input().split()))
    print(get_h(tree_data,len))


