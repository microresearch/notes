import socket, time, sys, os

UDP_IP = "127.0.0.1"
UDP_PORT = 8888

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

sockout = socket.socket(socket.AF_INET, # Internet
                       socket.SOCK_DGRAM) # UDP

first=0
data=""

for line in sys.stdin:
    text = " ".join(line.splitlines())
    if first==1:
        data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
       # print "received message:", data 
    print text
    if data=="done;\n" or first==0:        
        #        sockout.sendto("okay;", (UDP_IP, 9999))
        command="echo \""+text+";\" | /usr/bin/pdsend 9999 localhost udp"
        # /usr/bin/pdsend that line - but we overlap???
        os.system(command)
        #print "done"
        first=1
