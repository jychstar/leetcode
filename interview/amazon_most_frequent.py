from collections import Counter
def retrieveMostFrequentlyUsedWords(literatureText, wordsToExclude):
    # WRITE YOUR CODE HERE
    freqs = Counter(word for word in literatureText.split() if word not in wordsToExclude)
    res = []
    if len(freqs)== 0:
        return res
    peak = freqs.most_common()[0][1]
    
    #print freqs
    for (word, freq) in freqs.most_common():
        if freq == peak:
            res.append(word)
    return res

literatureText = "rose is a flower rose is pond a flower rose flower in garden garden garden pond pond rose is a rose is a rose is a rose is a"
wordsToExclude = ["rose", "is", "a"]
print retrieveMostFrequentlyUsedWords(literatureText, wordsToExclude)

literatureText = "rose is a flower rose is pond a flower rose flower in garden garden garden pond pond rose is a rose is a rose is a rose is a"
wordsToExclude = literatureText
print retrieveMostFrequentlyUsedWords(literatureText, wordsToExclude)