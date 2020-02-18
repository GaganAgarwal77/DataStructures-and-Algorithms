class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        n = len(stones)
        a = [1]
        a.remove()
        //a = stones
        while(n>0):
            maxim1 = max(stones)
            stones.remove(maxim1)
            maxim2 = max(stones)
            stones.remove(maxim2)
            if(maxim1-maxim2 != 0):
                stones.append(maxim1-maxim2)
            n = len(stones)
        print(stones)
        if(str(stones) == '[]'):
            return 0
        else:
            return stones[0]    