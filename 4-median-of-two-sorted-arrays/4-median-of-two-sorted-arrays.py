def leq(arr, value):
    ret = 0
    lidx, ridx = 0, len(arr) - 1
    while lidx <= ridx:
        midx = (lidx + ridx) // 2
        if arr[midx] <= value:
            ret = max(ret, midx + 1)
            lidx = midx + 1
        else:
            ridx = midx - 1
    return ret

def geq(arr, value):
    return len(arr) - leq(arr, value - 1)

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        A, B = (nums1, nums2) if len(nums1) < len(nums2) else (nums2, nums1)
        if len(A) == 0: return (B[len(B)//2] + B[(len(B)-1)//2])/2

        N = len(A) + len(B)
        P = (N + 1) // 2
        l, r = min(A[0], B[0]), max(A[-1], B[-1])

        cand1, cand2 = 123456789, -123456789
        while l <= r:
            m = (l + r) // 2
            if leq(A, m) + leq(B, m) >= P:
                r = m - 1
                cand1 = min(cand1, m)
            else: l = m + 1


        l, r = min(A[0], B[0]), max(A[-1], B[-1])
        while l <= r:
            m = (l + r) // 2
            if geq(A, m) + geq(B, m) >= P:
                l = m + 1
                cand2 = max(cand2, m)
            else:   r = m - 1

        return (cand1 + cand2) / 2
