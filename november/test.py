def max_length(s, k):
    
    subarray_start = 0
    subarray_end = 0

    subarray_sum = 0
    max_len = -1 # returns -1 if there is no subsequence that adds up to k.
    for i in s:
        subarray_sum += i
        subarray_end += 1
        while subarray_sum > k: # Shrink the array from the left, until the sum is <= k.
            subarray_sum -= s[subarray_start]
            subarray_start += 1

        # After the previous while loop, subarray_sum is guaranteed to be 
        # smaller than or equal to k.
        max_len = max(max_len, subarray_end - subarray_start)

    return max_len


p = [8,2,7,9,9]

for k in p:
    #print(k)
    print(max_length(p,k))