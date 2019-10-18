#https://leetcode.com/problems/reverse-integer/ 
class Solution:
    def reverse(self, x: int) -> int:
        rev = 0 
        rem = 0
        
        if x < 0:
            sing = -1 
        else: 
            sing = 1
        
        x = abs(x); 
        
        while x != 0:
            rem = x % 10     
            rev = (rev * 10) + rem   
            x = x // 10
            
        rev *= sing 
        print(9646324351 > 2147483647)
        print(9646324351 < -2147483648 )
        
        if (rev > ((2**31) - 1)) or (rev < ((2**31) * -1)):
            return 0 
        else:
            return rev

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            x = int(line);
            
            ret = Solution().reverse(x)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
