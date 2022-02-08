import nltk, pickle
import re
import sys
import random, itertools

import sys
reload(sys)
sys.setdefaultencoding('utf8')


def storepickle(text,where):
    out = open(where, 'wb')
    pickle.dump(text, out)
    out.close()

#crash_raw = open("crash.txt").read()

f = open("paget2.txt")
text=f.read()#+ff.read()

#sentences = nltk.word_tokenize(crash_raw)
#crash = []
#for sen in sens:
#	crash += nltk.word_tokenize(sen)

#crash_raw = open("crashwounds").read() 
#sens = nltk.sent_tokenize(crash_raw)
#crash = []
#for sen in sens:
# 	crash += nltk.word_tokenize(sen)

sentences = nltk.sent_tokenize(text)
sentences = [nltk.word_tokenize(sent) for sent in sentences]


patterns = [
    ('injur*|wound*', 'INJ'),
    ('crash*', 'CHR'),
    ('collision*', 'COL')
    ]

tag1= nltk.data.load(nltk.tag._POS_TAGGER)
regexp_tagger = nltk.RegexpTagger(patterns,backoff=tag1)
ttt=[regexp_tagger.tag(sent) for sent in sentences]
#ttt=[regexp_tagger.tag(crash)]

# the grammar we define for injuries, crashes and collisions.

# Notes:
# ? =preceding is optional
# * =repeat previous zero or more times
# + =repeat one or more times

grammar="""
IP: {<JJ|NN>?<INJ><MD|R.*|WDT||V.*|JJ.*|CC|P.*|TO|DT|IN|NN.*|INJ|COL|CHR>+} 
CP: {<JJ>?<CHR><DT|V.*|JJ.*|CC|POS|IN|NN.*|TO,>+} 
OP: {<JJ>?<COL><DT|V.*|JJ.*|CC|POS|IN|NN.*|,|.>+} 
NP: {<JJ.*>?<VBD|N.*>?<IN|VBD>?<NN>?<N.*>}
"""

# some other grammars

# grammar = "NP: {<COL|INJ|CHR><DT|V.*|JJ.*|CC|POS|IN|NN.*|PRP.*|COL|TO|,>+}"
# grammar = "IP: {<DT>?<JJ.*>?<N.*>+<IN>+<JJ.*|VB.*>+<N.*>?<CC>?<JJ.*|NN>?<IN>?<NNS>}"
# grammar = "NP: {<JJ.*>?<VBD|N.*>?<IN|VBD>?<NN>?<N.*>}" # dt jj nn = the adjective noun 

#chunking the text according to this grammar

cp = nltk.RegexpParser(grammar)
result = [cp.parse(sent) for sent in ttt]

#collect the injury nounphrases

nounphrase=[]
npp=""
for sent in result:
    for subtree in sent.subtrees():
        np=""
        if subtree.label() == 'IP':
            x=' '.join(nltk.tag.untag(subtree))
            for i in x:
                np += i
            npp += np +" " 
            nounphrase.append(np)

            
sentence=""

#substitute each injury nounphrase for another randomly selected one

def a(input):
    x = input[random.randint(0,len(input) - 1)]
    return x

for sent in result:
    for subtree in sent.subtrees():
#    if len(subtree) == 5:
        np=""
        if subtree.label() == 'IP':
            x=' '.join(nltk.tag.untag(subtree))
#            print x+",",
            for words in sent:
                if isinstance(words[0], tuple):
                    sentence+= a(nounphrase)+" "
                else:
                    if words[0]=="," or words[0]==".":
                        sentence= sentence[:-1] + words[0]+" "
                    else:
                        sentence+=words[0]+" "
            print(sentence[:-1])
            print("\n")
            sentence=""
