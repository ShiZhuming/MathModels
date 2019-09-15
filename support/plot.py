import matplotlib.pyplot as plt
f=open('data.out')
r=f.read()
r=r.split('\n\n')
r.pop()
x=[];y=[]
for i in range(len(r)):
    x.append([]);y.append([])
    r[i]=r[i].split('\n')
    for j in range(len(r[i])-1):
        r[i][j]=r[i][j].split(' ')
        x[i].append(float(r[i][j][0]))
        y[i].append(float(r[i][j][1]))
    plt.plot(x[i],y[i],label=str(r[i][len(r[i])-1]))
    print(str(r[i][len(r[i])-1]))
plt.xlabel('t');plt.ylabel('p',rotation=0)
plt.legend()
plt.grid()
plt.show()

        