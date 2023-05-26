def two_sum(arr, sum_):
    pairs = []
    len_ = len(arr)
    for i in range(len_):
        for j in range(1, len_):
            if arr[i] + arr[j] == sum_:
                pairs.append([arr[i], arr[j]])

    
    return pairs

def hash_sln(arr, sum_):
    hash = {}
    pairs = []

    for i in range(len(arr)-1):
        hash[arr[i]+arr[i+1]] = [arr[i]+arr[i+1]]
    


if __name__ == "__main__":
    print(two_sum([22, 24, 36, -3, 5, -17, 14], 19))
