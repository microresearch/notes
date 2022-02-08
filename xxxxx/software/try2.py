"""
Attempt to:

- Classify sentences DONE
- Take first Noun phrase (NP) with X or more words from first sentence // question of what to do with fullstop: ignore full stop?
- Count how many times this occurs in the full text?
- Output NP and maybe convert to grammar

 grammar = "NP: {<NN><NN>}  # Chunk two consecutive nouns"

- Take next NP (shift one? until we hit end of sentence?)

or try to match whole sentence?

"""

import nltk, pickle
import re
import sys
import random, itertools

import sys
reload(sys)
sys.setdefaultencoding('utf8')

# we need to match more than once!

# TODO: make list of tags and store these - don;t add if we already have!
posphrases=[]

def dowematch(posphrase, taggedtext):
    once=0
    for sent in taggedtext:
        for (w1,t1), (w2,t2), (w3,t3), (w4,t4), (w5,t5) in nltk.ngrams(sent,5):
            if posphrase == [t1, t2, t3, t4, t5] and posphrase not in posphrases and w5!="." :
                once+=1
                #print posphrase, [t1, t2, t3, t4, t5]
                if once>4:
                    #print t1,t2,t3,t4,t5
                    posphrases.append([t1, t2, t3, t4, t5])
                    return

# convert to grammar and output
                
def process(sentence):
    #print sentence
    listy=[]
    for (w1,t1), (w2,t2), (w3,t3), (w4,t4), (w5,t5) in nltk.ngrams(sentence,5): 
        #        if (t1.startswith('V') and t2 == 'TO' and t3.startswith('V')):
        listy.append([t1, t2, t3, t4, t5])
    return listy
        
def storepickle(text,where):
    out = open(where, 'wb')
    pickle.dump(text, out)
    out.close()

f = open("texts/crashchap1")
text=f.read()#+ff.read()
text=re.sub(r'[^\x00-\x7f]',r'', text) 

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

#for tt in ttt:
#    print(tt)

# so now how do we access first X tags

for sent in ttt:
    #    print sent
    listy=process(sent)
    #    print(listy)
    for list in listy:
        #        print list
        # this is what we want to try and match in the text...
        dowematch(list, ttt)

count=0

grams=[]

for ph in posphrases:
    #    print ph
    # convert to NP: {<NN><NN>}  
    #strg="NP"+str(count)+": {"
    strg="NP"+": {"
    count+=1
    for el in ph:
        strg+="<"+el+">"
    strg+="}"
    print strg    
    grams.append(strg)

#print grams[0]

# apply grammar to (any) text... and print results

f = open("texts/shortpaget") # other to same text
text=f.read()#+ff.read()
text=re.sub(r'[^\x00-\x7f]',r'', text) 

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

#chunking the text according to this grammar
for grammar in grams:
    cp = nltk.RegexpParser(grammar)
    result = [cp.parse(sent) for sent in ttt]

    nounphrase=[]
    npp=""
    for sent in result:
        for subtree in sent.subtrees():
            np=""
            if subtree.label() == 'NP':
                x=' '.join(nltk.tag.untag(subtree))
                for i in x:
                    np += i
                npp += np +" " 
                nounphrase.append(np)
    for nn in nounphrase:
        print nn
