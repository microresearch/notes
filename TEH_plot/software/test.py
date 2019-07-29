tape = [1,1,1,1,1,1,1,0,0]                  # The data tape
head = 1                                    # head position on tape
state = 1                                   # instruction pointer

def resettm():
    global tape
    tape = [1,1,0,1,1,1,0,0,0]                  # The data tape
    global head
    head = 0                                    # head position on tape
    global state
    state = 0                                   # instruction pointer


resettm()
print head, state, tape
