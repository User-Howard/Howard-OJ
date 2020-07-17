T1 = [int(i) for i in input().split(':')]
T2 = [int(i) for i in input().split(':')]
ANS = (T2[0]*3600+T2[1]*60+T2[2]) - (T1[0]*3600+T1[1]*60+T1[2])
if ANS<0:
    ANS+=24*3600
print("%02d:%02d:%02d"%(ANS//3600, ANS//60%60, ANS%60))
