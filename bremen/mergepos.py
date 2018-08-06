import random
import nltk
#from textclean.textclean import textclean

#crash_raw = open("crash.txt").read()

esc_chars = ["...",']',';','%','^','&','_','{',"}","~"]

def choose(listie):
# but we need counter for each POS! - in each list as listie[0] but where is code?
    count=listie[0]+1
    if count>len(listie):
        listie[0]=0
        count=1
    else:
        listie[0]=count
    return listie[count]

crash_raw = open("text-to_process").read()
#crash_raw = textclean.clean(crash_raw)
sens = [word.lower() 
        for word in nltk.sent_tokenize(crash_raw)]


crash = []
for sen in sens:
	crash += nltk.pos_tag(nltk.word_tokenize(sen))
        crash += ("XXXXX",)
#print crash

train_txt = open("sidechannelheat.txt").read()
#train_txt = textclean.clean(train_txt)
train_sens = nltk.sent_tokenize(train_txt)
train_txt = []
for sen in train_sens:
	train_txt += nltk.pos_tag(nltk.word_tokenize(sen))

# pickle the tokenised

mm = {}

for tword in train_txt:
    if not(tword[1] in mm):
        mm[tword[1]] = [tword[0]]
    else:
        mm[tword[1]].append(tword[0])

#print mm.keys().sort()
#ll=mm.keys()
#ll.sort()
#print ll[0]
#print ll

for x in range(100):
    out = ""
    for word in crash:
        if word=="XXXXX": 
            out+="\n"
        else:
            newword = ""
            try:
            #            newword = choose(mm[word[1]]) # + " "
                if random.randint(0,10)>4:
                    newword = random.choice(mm[word[1]]) # choose from POS key
                else:
                    newword = word[0] # the original
            except:
                newword = word[0]
            for ch in esc_chars:
                newword = newword.replace(ch,"")
        out += newword + " "
    print out+"\n\n"
    print x
    
# outfile = open("crashpaget002", "w")
# outfile.write(out)
# outfile.close()
