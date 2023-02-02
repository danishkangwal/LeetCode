class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        orderMap = [0]*26
        
        for i in range(len(order)):
            orderMap[ord(order[i])-ord('a')] = i;
        
        for i in range(len(words)-1):
            for j in range(len(words[i])):
                if(j >= len(words[i+1])):
                    return False
                
                if(words[i][j] != words[i+1][j]):
                    curr = ord(words[i][j])-ord('a');
                    next = ord(words[i+1][j])-ord('a');
                    
                    if orderMap[curr] > orderMap[next]:
                        return False
                    else:
                        break
                
        return True    