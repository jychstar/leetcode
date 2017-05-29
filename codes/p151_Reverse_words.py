class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = re.sub(' +', ' ', s)
        words =s.strip().split(" ");
        length = len(words)
        for i in range(length/2):
            words[i],words[length-i-1] = words[length-i-1], words[i]
 
        return " ".join(words)