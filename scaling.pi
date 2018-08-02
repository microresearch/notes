import csv

maxx=0
minn=1024
scaler=[]

with open('MONK27') as f:
    reader = csv.reader(f)
    for row in reader:
        if int(row[0])>maxx:
            maxx=int(row[0])
        if int(row[0])<minn:
            minn=int(row[0])
        scaler.append(int(row[0]))
            
print maxx, minn

scalerr=255.0/(maxx-minn)

with open('monkxy', 'w') as f:
    writer = csv.writer(f)
    writer.writerows([int(howmany*scalerr)] for howmany in scaler) 
