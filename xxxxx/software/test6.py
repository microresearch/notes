#TODO- learning chunks from wounds, process of recombination

#### 2014/2015 - node replaced in nltk 3.0 with label()

# 1-text becomes instructions (as chunks) becomes/generates text
# 2-also as genetic algo.

# so: how to train on wounds...? tag it first
# and what we expect to achieve? by training rather than just recognition of injury phrases
# ballardian noun phrase?

#catting texts such as crash excerpts with paget report, ripper letters and so on

#///

# how to have like chunk + chunk options - relook at chunking
# how to search around key terms in grammars

#////

# desc /injuries // carried out by/sustained in/formed by/caused by-within-during/to
# in accidents involving the --- collisions (between)
#loc: at//at the (junctions) between --- and ---
#deformed by/sectioned by

#////

#merging concordances somehow//with phrasing also
#see concord.py

#///

#get nounphrase chunk ordering from one text and use as model for
#others automatically

#///

# Diana our lady of
# Diana princess of
# Diana queen of

import nltk, pickle
import re
import sys
import random, itertools
from nltk.corpus import brown

def a(input):
    x = input[random.randint(0,len(input) - 1)]
    return x

def reader():
    ttt = open('/root/collect2012-3/diana/documents/paget2.txt','r')
#    ttt = open('shortpaget','r')
#    ttt = open('crash.txt','r')
#    ttt = open('crashchap1','r')
#    ttt = open('wounds/crashwounds','r')
#    uuu=rrr.read()+ttt.read()
    return ttt.read()

def plaintaggedtree(text):
    sentences = nltk.sent_tokenize(text)
    sentences = [nltk.word_tokenize(sent) for sent in sentences]
    sentences = [nltk.pos_tag(sent) for sent in sentences] 
#    sentences = [nltk.ne_chunk(sent) for sent in sentences]
    return sentences

def tokenize_text_and_tag_named_entities(text):
    tokens = []
    for sentence in nltk.sent_tokenize(text):
        for chunk in nltk.ne_chunk(nltk.pos_tag(nltk.word_tokenize(sentence))):
            if hasattr(chunk,  'node'):
#                print chunk
                if chunk.node != 'GPE':
                    tmp_tree = nltk.Tree(chunk.node,  [(' '.join(c[0] for c in chunk.leaves()))])
                else:
                    tmp_tree = nltk.Tree('LOCATION',  [(' '.join(c[0] for c in chunk.leaves()))])
                tokens.append(tmp_tree)
            else:
                tokens.append(chunk[0])
    return tokens

def extract_people_in_locations():
    for rel in nltk.sem.extract_rels('PERSON','LOCATION',doc,corpus='ieer',pattern=IN):
        #filler_tokens = dict(nltk.pos_tag(nltk.word_tokenize(rel['filler'])))
        print rel

class doc():
  pass
doc.headline = ['this is expected by nltk.sem.extract_rels but not used in this script']

# compile expressions to use to identify relations between named entities
#IN = re.compile (r'.*\bin\b')
#TO = re.compile (r'.*\bto\b')
# a list of verb tags for reference
#verbs = ['VB',  'VBG',  'VBD', 'VBN',  'VBP',  'VBZ']

# def storepickle(doc):
#     out = open("crash_tagged003.pickle", 'wb')
#     pickle.dump(doc.text, out)
#     out.close()

# def recallpickle(doc):
#     out = open("crash_tagged001.pickle", 'rb')
#     doc.text=pickle.load(out) 
#     out.close()

def storepickle(text,where):
    out = open(where, 'wb')
    pickle.dump(text, out)
    out.close()

def recallpickle(where):
    out = open(where, 'rb')
    text=pickle.load(out) 
    out.close()
    return text

# text=reader()
# ttt=nltk.word_tokenize(text)
# ttt=plaintaggedtree(text)

# patterns = [
#     ('injur*|wound*', 'INJ'),
#     ('crash*', 'CHR'),
#     ('collision*', 'COL')
#     ]

# tag1= nltk.data.load(nltk.tag._POS_TAGGER)
# regexp_tagger = nltk.RegexpTagger(patterns,backoff=tag1)
# ttt=[regexp_tagger.tag(sent) for sent in ttt]
# #print ttt

# storepickle(ttt,"pagetsentenced.pickle") 
#ttt=recallpickle("pagetsentenced.pickle")+recallpickle("customcrashsentenced.pickle")

ttt=recallpickle("pickle/customcrashsentenced.pickle")
#ttt=recallpickle("crash_taggedwounds.pickle")
#004 is full crash... paget_tagged2 is full paget

# ? =preceding is optional
# * =repeat previous zero or more times
# + =repeat one or more times

#grammar = "NP: {<DT>?<N.*|JJ.*><IN|N.*|VBN><VBN|IN|N.*><JJ.*|N.*><N.*>}" # from crash wounds text
#     {<.*>+}          # Chunk everything
# grammar = """
# NP: {<DT>?<N.*|JJ.*>+<IN|N.*|VBN>+<VBN|IN|N.*>?<JJ.*|N.*>?<N.*>}
#     }<NNS>+<VBN>+<IN>{      # Chink sequences of VBD and IN
#   """
#grammar = "NP: {<DT>?<JJ.*>*<N.*>*<N.*>}"
# grammar = """
# NP: {<JJ.*>?<CC>?<JJ.*>?<INJ><V.*>?<IN>?<V.*|JJ.*|N.*>+<V.*|JJ.*|CC|POS|IN|N.*>+}
# }<INJ><V.*><IN>{

# """

grammar="""
IP: {<JJ|NN>?<INJ><MD|R.*|WDT||V.*|JJ.*|CC|P.*|TO|DT|IN|NN.*|INJ|COL|CHR>+} 
CP: {<JJ>?<CHR><DT|V.*|JJ.*|CC|POS|IN|NN.*|TO,>+} 
OP: {<JJ>?<COL><DT|V.*|JJ.*|CC|POS|IN|NN.*|,|.>+} 
"""

# NP: {<COL|INJ|CHR><DT|V.*|JJ.*|CC|POS|IN|NN.*|PRP.*|COL|TO|,>+}  =*****

# injuries caused by INJ VBN IN

#grammar = "IP: {<DT>?<JJ.*>?<N.*>+<IN>+<JJ.*|VB.*>+<N.*>?<CC>?<JJ.*|NN>?<IN>?<NNS>}"

#grammar = "NP: {<JJ.*>?<VBD|N.*>?<IN|VBD>?<NN>?<N.*>}" # dt jj nn = the adjective noun 
cp = nltk.RegexpParser(grammar)
result = [cp.parse(sent) for sent in ttt]
#print result

nounphrase=[]
npp=""
for sent in result:
    for subtree in sent.subtrees():
#    if len(subtree) == 5:
        np=""
#        print subtree.label()
        if subtree.label() == 'IP':
            x=' '.join(nltk.tag.untag(subtree))
            for i in x:
                np += i
            npp += np +" " 
            nounphrase.append(np)
#print nounphrase
sentence=""

# for sent in result:
#     for subtree in sent.subtrees():
# #    if len(subtree) == 5:
#         np=""
#         if subtree.node == 'IP':
#             x=' '.join(nltk.tag.untag(subtree))
# #            print x+",",
#             for words in sent:
#                 if isinstance(words[0], tuple):
#                     sentence+= a(nounphrase)+" "
#                 else:
#                     if words[0]=="," or words[0]==".":
#                         sentence= sentence[:-1] + words[0]+" "
#                     else:
#                         sentence+=words[0]+" "
#             print sentence[:-1]
#             print
#             sentence=""
#            for i in x:
#                np += i + " "
        #                np += i
      #  print np
#        npp += np[:-1] +" " 
#            nounphrase.append(np[:-1])

#nounphrase = list(set(nounphrase))

#print nounphrase
#print npp

nounphraseo=[]

for sent in result:
    for subtree in sent.subtrees():
#    if len(subtree) == 5:
        np =""
        if subtree.label() == 'OP':
            x=nltk.tag.untag(subtree)
            for i in x:
                np += i + " "
        #                np += i
      #  print np
            nounphraseo.append(np[:-1])

nounphraseo = list(set(nounphraseo))

pastverb = []
nounphrasei=[]

for sent in result:
    for subtree in sent.subtrees():
#        print subtree
        #    if len(subtree) == 5:
        np =""
        if subtree.label() == 'IP':
            for i in subtree:
                if i[1] == "VBD":
                    pastverb.append(i[0])
            x=nltk.tag.untag(subtree)
            for i in x:
                np += i + " "

        #                np += i
#            lasttagged=1
#            print np
#            print subtree
            nounphrasei.append(np[:-1])


nounphrasei = list(set(nounphrasei))
pastverb = list(set(pastverb))


# g=ttt

# verblist = []
# for i in g:
#     if i[1] == "VB":
#         verblist.append(i[0])
# verblist = list(set(verblist))

# noun = []
# nounlist = []
# ing = []
# lowernoun = []
# for i in g:
#     if i[1] == "NN":        
#         if i[0].endswith("ing"):
#             ing.append(i[0])
            
#     if i[1] == "NN":        
#         if i[0][0].islower():
#             lowernoun.append(i[0])

#     if i[1] == "VBG":        
#         if i[0].endswith("ing"):
#             ing.append(i[0])

#     else:            
#       for x in g:
#                 #print x
#         if (x[0].isupper()):
#                     #print i[0]
#           nounlist.append(x[0])

# nounlist = list(set(nounlist))
# nounlist = list(set(lowernoun))

# #print nounlist
# #print ing
# #print noun

# #foo=[["Visit"], ["our"], ["new"], ["and"], ["improved"], ["Career"], ["Tools"]]
# #for x in ing:
# #    print x
#  #   z =  nsyl(x)
#  #   if z[0] == 3:
#  #       print x

# determiner = []
# for i in g:
#     if i[1] == "DT":
#         determiner.append(i[0])
# determiner = list(set(determiner))
# #print determiner

# posperspronoun = []
# for i in g:
#     if i[1] == "PRP$":
#         posperspronoun.append(i[0])
# posperspronoun = list(set(posperspronoun))

# propnoun = []
# for i in g:
#     if i[1] == "NNP":
#       if i[0].istitle():
#         propnoun.append(i[0])
# propnoun = list(set(propnoun))
# #print propnoun

# propnounpl = []
# for i in g:
#     if i[1] == "NNPS":
#         propnounpl.append(i[0])
# propnounpl = list(set(propnounpl))
# #print propnounpl

# possesive = []
# for i in g:
#     if i[1] == "POS":
#         possesive.append(i[0])
# possesive = list(set(possesive))

# adjective = []
# for i in g:
#     if i[1] == "JJ":
#         adjective.append(i[0])
# adjective = list(set(adjective))

# compadjective = []
# for i in g:
#     if i[1] == "JJR":
#         compadjective.append(i[0])
# compadjective = list(set(compadjective))

# keywords = ["self","selves","us","them","me","him","her"]
# perspronoun = []
# ppronoun = []
# for i in g:
#     if i[1] == "PRP":
#         ppronoun.append(i[0])
#         for k in keywords:
#             if k  in i[0]:
#                 perspronoun.append(i[0])
# ppronoun = list(set(ppronoun))
# perspronoun = list(set(perspronoun))

# for bla in perspronoun:
#     ppronoun.remove(bla)

# verb = []
# for i in g:
#      if i[1] == "VB":
#          verb.append(i[0])
# verb = list(set(verb))

pastverb = []
for sent in ttt:
    for i in sent:
        if i[1] == "VBD":
            pastverb.append(i[0])
pastverb = list(set(pastverb))
#print pastverb
# vbz = []
# for i in g:
#     if i[1] == "VBZ":
#         vbz.append(i[0])
# vbz = list(set(vbz))

# adverb = []
# adverbly = []
# for i in g:
#     if i[1] == "RB":
#       if i[0].endswith("ly"):
#         adverbly.append(i[0])
#       else:
#         adverb.append(i[0])

# adverb = list(set(adverb))
# adverbly = list(set(adverbly))
# #print adverbly
# #print adverb

# ppverb = []
# for i in g:
#     if i[1] == "VBN":
#         ppverb.append(i[0])
# ppverb = list(set(ppverb))

# modalverb = []
# for i in g:
#     if i[1] == "MD":
#         modalverb.append(i[0])
# modalverb = list(set(modalverb))

# howwherewhy = []
# for i in g:
#     if i[1] == "WRB":
#         howwherewhy.append(i[0])
# howwherewhy = list(set(howwherewhy))


# cconj = []
# for i in g:
#     if i[1] == "CC":
#         cconj.append(i[0])
# cconj = list(set(cconj))

# c = [ppronoun, verblist, posperspronoun, nounlist, perspronoun, pastverb, cconj,  perspronoun, pastverb, ppverb, adverb, howwherewhy,ing,propnoun] 
# v = [verb,pastverb,ing,adverb,ppverb,vbz,adverbly]
# adj = [adjective,compadjective]
# noun = [propnoun,possesive,nounlist,lowernoun]
# dt = [determiner]

# components = [ppronoun, pastverb] 

# def recitea():
# #  x = a(adj[0]) + " " + a(noun[0]) + " " + a(v[0]) + " " + a(adj[1]) + " " + a(v[3]) + " " + a(noun[1]) 
# #  x = a(dt[0]) + " " + a(adj[0]) + " "+ a(noun[3]) + " - "+ a(v[2]) + " " + a(v[2]) + " -  " +a(noun[2]) + " and  "+ a(noun[2]) + ", " + a(dt[0]) + " " + a(adj[0]) + " "+ a(noun[3]) + " "+ a(v[5]) + ": " + a(v[2]) + " "+ a(v[2]) + " "+ a(v[2]) + " - " #+ a(v[6]) + " "

#     x = "spray and actress" + ", " + a(dt[0]) + " " + a(adj[0]) + " "+ a(noun[3]) + " "+ a(v[5]) + ": " + "morning dying dying"

# #    x = a(adj[0])
# #    x = a(adj[0]) + " " + a(noun[0]) + " " + a(adj[0]) + " " + a(noun[0]) + " "
# #    x =  a(c[13]) + " " + a(v[0]) + " " + a(v[0]) +" " + a(c[0]) + " " + a(c[5])  + " "+ a(c[13]) + " "+ a(v[2]) + " -  " + a(v[2]) +" -  "+  a(v[2]) +  " " + a(adj[0]) + " " + a(noun[0]) + "! " + a(adj[0]) + " " + a(noun[0]) + "! "
#    # y =  a(c[5]) + ", and " + a(c[5]) + ", " + a(c[0]) + " " + a(c[5]) + " and " + a(c[5]) + " a " + a(c[3]) + " of " + a(c[3]) +  ". "
# #    x = x.capitalize()
#     #y = y.lower().capitalize()
#     #z = z.capitalize()
#     print x

def diana():
    x="Diana "+a(pastverb)+" "+a(nounphrasei)+" "+ a(pastverb)+" "+a(nounphrase)+" "+ a(pastverb)+" "+a(nounphraseo)+"."
#    x="Diana "+ a(pastverb)+" "+a(nounphrasei)+" in a "+a(nounphraseo)+"."
    print x

#for x in range(2000):
#    print a(("Diana our lady of","Diana princess of", "Diana queen of")), a(nounphrase)+"."


# Diana our lady of
# Diana princess of
# Diana queen of

#print nounphrasei


#print "Diana",
for x in range(200):
    diana()

# print "injury:"
# print nounphrasei
# print "collision:"
# print nounphraseo
# print "crash:"
# print nounphrase


#print "INJURIES"
#for phrase in nounphrasei:
#    print phrase




# #def machine():
# # how to run text as a set of instructions which generates another?

def permute(inputlist):
    x= [' '.join(s) for s in itertools.product(*inputlist)]
    for sent in x:
#        print sent[:-1]+"."
        print sent+"."

#x = ["Diana"],pastverb,nounphrasei

#permute(x)
