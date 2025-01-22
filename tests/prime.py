def minCostToEqual(arr, brr, k):
    n = len(arr)
    
    # If rearrangement cost is 0, we can freely sort the arrays
    if k == 0:
        arr.sort()
        brr.sort()
        return sum(abs(arr[i] - brr[i]) for i in range(n))
    
    # General case: compute both no-rearrangement cost and rearrangement cost
    no_rearrange_cost = sum(abs(arr[i] - brr[i]) for i in range(n))
    
    arr.sort()
    brr.sort()
    rearrange_cost = k + sum(abs(arr[i] - brr[i]) for i in range(n))
    
    return min(no_rearrange_cost, rearrange_cost)

# Example usage
print(minCostToEqual([-7, 9, 5], [7, -2, -5], 2))  # Output: 13
print(minCostToEqual([2, 1], [2, 1], 0))          # Output: 0
print(minCostToEqual([-10,5,3,-6,5,-10,-1,8,-8], [-4,-2,-10,-9,-9,-4,7,-2,2], 0)) # Ouput: 23

