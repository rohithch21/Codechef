# cook your dish here

t = int(input())

while(t>0):
    n = int(input())
    tot_points = 4*n

    X = {}
    Y = {}
    for i in range(tot_points-1):
        line = input().split(" ")
        x = line[0]
        y = line[1]

        try:
            X[x]  = X[x] + 1
        except Exception as e:
            X.update({x:1})
        
        try:
            Y[y]  = Y[y] + 1
        except Exception as e:
            Y.update({y:1})
    
    for val in X:
        if X[val] % 2 == 1:
            x_cordinate = val
    for val in Y:
        if Y[val] %2 == 1:       
            y_cordinate = val

    print(x_cordinate + " " + y_cordinate)
    t = t - 1
    X.clear()
    Y.clear()
