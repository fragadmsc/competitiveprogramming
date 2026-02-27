a = int(input(""))
mx=0
i = 1
while(i<=a):
    mx = max(mx, (a-i)*10*i+i)
    i*=10

print(mx)