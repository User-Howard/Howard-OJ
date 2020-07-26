class Solution:
    """
    @param numbers: An array of Integer
    @param target: target = numbers[index1] + numbers[index2]
    @return: [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        for i in range(0, len(numbers)):
            for j in range(i+1, len(numbers)):
                if numbers[i]+numbers[j] == target:
                    return i, j
