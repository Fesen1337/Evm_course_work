import matplotlib.pyplot as plt


#plt.plot((0.1, 0.5, 0.9, 0.1), (0.1, 0.9, 0.1, 0.1))
#plt.show()

flag = 0
f = open('logs.txt', 'r')
for eachLine in f:
    a = eachLine.strip().split(" ")
    if flag != 0:
        res = list(map(int, a))
    else:
        res = float(eachLine)
    if flag == 0:
        time = res
    if flag == 1:
        y1 = res
    if flag == 2:
        x1 = res
    if flag == 3:
        y2 = res
    if flag == 4:
        x2 = res
    flag = flag + 1
plt.plot(x1, y1, 'b', label='c конвейером')
plt.plot(x2, y2, 'g', label ='без конвейера')
plt.legend()
plt.grid()
plt.title(f"Среднее количество тактов на команду = {time}")
plt.xlabel("Кол-во обработанных команд")
plt.ylabel("Кол-во тактов")
plt.show()
