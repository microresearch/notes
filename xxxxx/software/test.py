import random, pickle
import nltk
from nltk.tag import DefaultTagger 
from nltk.tag import UnigramTagger  

#from nltk.tag.perceptron import PerceptronTagger
#default_tagger = PerceptronTagger()

#class BackoffTagger:
#    def __init__(self):
#        self._taggers = [PerceptronTagger()]

import sys
reload(sys)
sys.setdefaultencoding('utf8')


crash_raw = open("crashwounds").read() 
sens = nltk.sent_tokenize(crash_raw)
crash = []
for sen in sens:
 	crash += nltk.word_tokenize(sen)

grammar="""
IP: {<JJ|NN>?<INJ><MD|R.*|WDT||V.*|JJ.*|CC|P.*|TO|DT|IN|NN.*|INJ|COL|CHR>+} 
NP: {<DT>?<N.*|JJ.*><IN|N.*|VBN><VBN|IN|N.*><JJ.*|N.*><N.*>} # from crash wounds text
NPP: {<DT>?<JJ>?<NN|NNS>+<IN>?<JJ>?<NN|NNS>?<CC>?<JJ|NN>?<IN>?<NNS>}"
"""

patterns = [
    ('injur*|wound*', 'INJ'),
    ('crash*', 'CHR'),
    ('collision*', 'COL')
    ]

tag1= nltk.data.load(nltk.tag._POS_TAGGER)

#default_tagger = nltk.data.load("../nltk_data/taggers/maxent_treebank_pos_tagger/english.pickle")
regexp_tagger = nltk.RegexpTagger(patterns,backoff=tag1)

#regexp_tagger = nltk.RegexpTagger(patterns,backoff=nltk.DefaultTagger('NN'))
#regexp_tagger = nltk.RegexpTagger(patterns)
# #ttt=[regexp_tagger.tag(sent) for sent in ttt]
ttt=regexp_tagger.tag(crash)
#ttt=recallpickle("customcrashsentenced.pickle")
#ttt = nltk.pos_tag(crash)
#print(tags)
cp = nltk.RegexpParser(grammar)
#result = [cp.parse(sent) for sent in ttt]

result = cp.parse(ttt)
#print (ttt)

nounphrase=[]
npp=""
#for sent in result:
for subtree in result.subtrees():
#    if len(subtree) == 5:
	np=""
#    print subtree
	if subtree.label() == 'NPP':
		x=' '.join(nltk.tag.untag(subtree))
		for i in x:
			np += i
			npp += np +" " 
		nounphrase.append(np)
		nounphrase.append("\n")
print (''.join(nounphrase))
