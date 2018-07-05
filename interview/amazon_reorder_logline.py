def reorderElements(logFileSize, logLines):
    wordtuple =[]
    numLines = []
    for line in logLines:
        words = line.split()
        if words [1].isdigit():
            numLines.append(line)
        else:
            wordtuple.append((" ".join(words[1:]),words[0]))
    wordtuple.sort()
    res = []
    for (text,iden) in wordtuple:
        res.append(iden + " " + text)
    for text in numLines:
        res.append(text)
    return res