from matplotlib import pyplot as plt
a =[]
i = 0
a.append([i for i in range(5)])
a[i][0]=264
a[i][1]=5362
a[i][2]=5260
a[i][4]=5263
a[i][3]=5263
i = 1
a.append([i for i in range(5)])
a[i][0]=284
a[i][2]=5086
a[i][3]=5086
a[i][1]=5085
a[i][4]=5087
i = 2
a.append([i for i in range(5)])
a[i][0]=255
a[i][0]=5393
a[i][1]=5444
a[i][2]=5466
a[i][3]=5472
a[i][4]=5573
i = 3
a.append([i for i in range(5)])
a[i][0]=255
a[i][0]=5275
a[i][1]=5314
a[i][2]=5323
a[i][3]=5332
a[i][4]=5375
i = 4
a.append([i for i in range(5)])
a[i][0]=255
a[i][0]=5386
a[i][1]=5416
a[i][2]=5428
a[i][3]=5342
a[i][4]=5236

i = 5
a.append([i for i in range(5)])
a[i][0]=5672
a[i][1]=5672
a[i][2]=5677
a[i][3]=5687
a[i][4]=5730

x = [ i for i in range(5) ]
for i in range(len(a)):
    plt.plot(x,a[i])

plt.show()
