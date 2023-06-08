visited=[0]*32*2
visited[0]=1
gcc=[0]*33*2
alley=[]
looky=[0,0,1,0, 2,0,0,0, 3,0,0,0, 0,0,0,0, 4, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,5]

# so far we have all permutations of gray codes, not yet beckett

def f(b):
 r,*u=1,
 for x,y in zip(b,b[1:]):
  if x<y:u+=x^y,
  else:r&=u.pop(0)==x^y
 return r

test=[0, 2, 3, 1]

test=[0, 1, 3, 2, 6, 7, 5, 13, 9, 8, 10, 11, 27, 19, 23, 21, 20, 4, 12, 28, 24, 26, 18, 22, 30, 14, 15, 31, 29, 25, 17, 16]

#print(f(test))

def transitions(arry,n):
    for d in range(n+1):
        if d!=0:
            print(looky[abs(arry[d]-last)],end=" ")
        last=arry[d]
    print()

def transitionsN(arry,n):
    for d in range(n):
        if d!=0:
            print(looky[abs(arry[d]-last)],end=" ")
        last=arry[d]
    print()
    
def flip(arrs,which):
    arrs=arrs^(1<<which)
    return arrs

def beckett(d,x,max_coord,n):
    if d>=pow(2,n):
        if (gcc[d-1]&(gcc[d-1]-1) == 0) and gcc[d-1] != 0: # cyclic as in one bit at end
            if f(gcc[0:d]):
                print(gcc[0:d])
                transitions(gcc,d)# how to get transition
            #            print("Cyclic:",end=" ")
            #print(gcc[0:d])
            #print("Isbeckett:",end=" ")
            #print(f(gcc[0:d]))
            #transitions(gcc,d)# how to get transition
            #        else:
            #print("NON-cyclic:",end=" ")
            #transitionsN(gcc,d)# how to get transition
        #ally.append(list(gc))
        return
    for i in range(min(n-1, max_coord)+1):
        x=flip(x,i)
        if visited[x]==0:
            visited[x]=1
            gcc[d]=x
            beckett(d+1, x, max(i+1, max_coord), n)
            visited[x]=0
        x=flip(x,i)

        
beckett(1,0,0,6) # 5 above we run out of memory if we concat gc into larger list
#print(alley)

# To achieve that, we need to modify the algorithm a little. We will
# use a queue to know that when we set a bit to zero, that will be the
# bit whose value has stayed at one for the longest time.
