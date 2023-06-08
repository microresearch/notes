#-----------------------------------------------------------------------
# beckett.py
#-----------------------------------------------------------------------

#An n-bit Gray code is a list of the 2n different n-bit binary numbers
#such that each entry in the list differs in precisely one bit from
#its predecessor. Gray codes directly apply #to Beckett's problem
#because we can interpret each bit as denoting whether the integer
#corresponding to its bit position is in the subset. Changing the
#value of a bit from 0 to 1 c#orresponds to an integer entering the
#subset; changing a bit from 1 to 0 corresponds to and integer exiting
#the subset.

# https://introcs.cs.princeton.edu/python/23recursion/

# not true QUAD code as constraints (of last one exiting and circularity) are not met...

# can those be added in this recursive format?

import sys

stage=[]

#-----------------------------------------------------------------------

# Write to standard output Beckett's stage instructions to have n
# actors enter (if parameter enter is True) or exit (if parameter
# enter is False) the stage.

def moves(n, enter):
    if n == 0:
        return
    moves(n-1, True)
    if enter:
        stage.append(str(n))
        #        print('enter ' + str(n))
        #        print stage
        print str(n-1),
    else:
        stage.remove(str(n))
        #        print('exit  ' + str(n))
        #        print stage
        print str(n-1),
    moves(n-1, False)

#-----------------------------------------------------------------------

# Accept integer n as a command-line argument. Write to standard
# output Beckett's stage instructions (the bit positions that change
# in a binary-reflected Gray code) for n actors.

def main():
    n = int(sys.argv[1])
    moves(n, True)

if __name__ == '__main__':
    main()
    
#-----------------------------------------------------------------------
