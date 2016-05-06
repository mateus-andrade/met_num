from __future__ import print_function

n = 3; m = 0.0

a = [[100.0, -100.0, 200.0],
	 [-100.0, 10.0,  110.0],
	 [0.0,    110.0, 10.0]]

x = [0.0, 0.0, 0.0]
b = [0.0, 0.0, 20.0]
I = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

for k in range (0,n-1):
	for i in range (k+1, n):
		m = a[i][k]/a[k][k]
		for j in range(k+1,n):
			a[i][j] = a[i][j] - (m*a[k][j])
		b[i] = b[i] - m*b[k]
		a[i][k] = 0.0;

	for o in range (0,n):
		print('|',end="")
		for p in range(0,n):
			print('','%0.2f' % a[o][p],' ',end="")
		print(b[o],'| \n')

	print()

x[n-1] = b[n-1]/a[n-1][n-1]

for i in range (n-2,-1,-1):
	soma = 0.0
	for j in range (i+1,n):
		soma = soma + a[i][j]*x[j]

	x[i] = (b[i]-soma)/a[i][i];

I[1] = x[0]; I[3] = x[1]; I[4] = x[2]
I[0] = I[4]+I[3]
I[2] = I[1]+I[4]
I[5] = I[0]+I[1]

for i in range(0,6):
	print('I',i,'= %0.10f' % I[i])
