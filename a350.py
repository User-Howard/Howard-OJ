import sys
lens = [8, 16, 24, 32, 40, 48, 56, 64, 80]
N = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
left = list()
for i in range(8, -1, -1):
    if nums[i]!=0 and lens[i] > N :
        print("NO SOLUTION!!")
        exit()
    left.sort()
    for idx, l in enumerate(left):
        print(idx, l)
        minus = min(l // lens[i], nums[i])
        left[idx] -= minus * lens[i]
        nums[i] -= minus
    if nums[i] :
        minus = N // lens[i]
        for _ in range(nums[i] // minus):
            left.append(N - lens[i] * minus)
        if nums[i] % minus :
            left.append(N - lens[i] * (nums[i] % minus))
    # print(nums)
    # print(lens)
    # print(left)
    # print()
print(len(left))