N = int(input())
nums = map(int, input().split())
ans = 0
for i, num in enumerate(nums, 1):
    ans += i * num
print(ans)