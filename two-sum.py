arr = [13,4,234,5,676,878,90,3]
k = 16
arr_map = {}
for i in arr:
    if(abs(k-i) in arr_map.keys()):
        print(arr.index(i), " " , arr.index(abs(k-i)))
    arr_map[i] = 1