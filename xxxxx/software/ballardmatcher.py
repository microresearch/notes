# match new ballardian NPs 
# fixed for later NLTK 10/1/2021 but runs out of memory on imac

import random, pickle
import nltk
from nltk.tag import DefaultTagger 
from nltk.tag import UnigramTagger  

def recallpickle(where):
    out = open(where, 'rb')
    text=pickle.load(out) 
    out.close()
    return text

crash_raw = open("generated/paget_exec001").read() 
#crash_raw = open("generated/crashthreadedleaky001").read() 
sens = nltk.sent_tokenize(crash_raw)
crash = []
for sen in sens:
 	crash += nltk.word_tokenize(sen)

# #now match a POS template or Ballardian noun phrase

grammar="""
IP: {<JJ|NN>?<INJ><MD|R.*|WDT||V.*|JJ.*|CC|P.*|TO|DT|IN|NN.*|INJ|COL|CHR>+} 
CP: {<JJ>?<CHR><DT|V.*|JJ.*|CC|POS|IN|NN.*|TO,>+} 
OP: {<JJ>?<COL><DT|V.*|JJ.*|CC|POS|IN|NN.*|,|.>+} 
"""

patterns = [
    ('injur*|wound*', 'INJ'),
    ('crash*', 'CHR'),
    ('collision*', 'COL')
    ]

#tag1= nltk.data.load(nltk.tag._POS_TAGGER)

regexp_tagger = nltk.RegexpTagger(patterns,backoff=nltk.DefaultTagger('NN'))
#regexp_tagger = nltk.RegexpTagger(patterns)
# #ttt=[regexp_tagger.tag(sent) for sent in ttt]
ttt=regexp_tagger.tag(crash)
#ttt=recallpickle("customcrashsentenced.pickle")
cp = nltk.RegexpParser(grammar)
#result = [cp.parse(sent) for sent in ttt]
result = cp.parse(ttt)

#print result

nounphrase=[]
npp=""
#for sent in result:
for subtree in result.subtrees():
#    if len(subtree) == 5:
	np=""
#    print subtree
	if subtree.label() == 'IP':
		x=' '.join(nltk.tag.untag(subtree))
		for i in x:
			np += i
			npp += np +" " 
		nounphrase.append(np)
		nounphrase.append("\n")
print ''.join(nounphrase)



