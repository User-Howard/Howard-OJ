N = int(input())
for cases in range(N):
    print(f"Case {cases+1} :")
    nums= [int(i) for i in input().split()]
    M, K = nums[0], nums[1]
    t = M//K
    for i in range(1, nums[1]):
        print(f"第{i}位 : 拿{t}元並說DD! BAD!")
    print(f"第{nums[1]}位 : 拿{M-t*(K-1)}元並說DD! BAD!")
