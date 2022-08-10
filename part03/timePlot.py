import matplotlib.pyplot as plt
import csv

x  = []
y1 = []
y2 = []

with open('example.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y1.append(float(row[1]))
        y2.append(float(row[2]))

plt.plot(x,y1, label='Итерация')
plt.plot(x,y2, label='Рекурсия')

plt.xlabel('n')
plt.ylabel('time')
plt.title('Исследование факториала')
plt.legend()
plt.show()
