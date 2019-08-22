import sys, time, os

for line in sys.stdin:
    text = " ".join(line.splitlines())
    #    print text, # escape newline
    print text + ";"
    command="echo \""+text+";\" | /usr/bin/pdsend 9999 localhost udp"
    # /usr/bin/pdsend that line - but we overlap???
    os.system(command)
    time.sleep(3)
