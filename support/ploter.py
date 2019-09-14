import matplotlib.pyplot as plot
x_list = []
y_list = []
DataFile = open("dataof1.out")
try:
    while True:
        x = DataFile.readline()
        if (x == ''):
            break
        x_list.append(x)
        y = DataFile.readline()
        if (y == ''):
            break
        y_list.append(y)
finally:
    DataFile.close()
x_list.pop()
# y_list.pop()
plot.figure('plot of data 1')
ax = plot.gca()
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.plot(x_list, y_list)

plot.show()