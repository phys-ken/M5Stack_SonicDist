import matplotlib.pyplot as plt
import serial

x, y = [], [] # 描画データ
CNT = 20      # 受信（＝描画）回数

fig, ax = plt.subplots()
lines, = ax.plot(x, y)

ax.set_xlim((0, CNT))
ax.set_ylim((0, 128))

com = serial.Serial('COM6', 115200, timeout=0.1) 
for i in range(CNT):
    res = com.read()
    n = int.from_bytes( res, 'big' )
    print(n)
    x.append(i)
    y.append(n)
    lines.set_data(x, y)

    plt.pause(0.1) # これが重要！

com.close()