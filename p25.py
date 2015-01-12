f1=1
f2=1
t=2
while  (f2<10**999):
	f1=f1+f2
	tmp=f1
	f1=f2
	f2=tmp
	t=t+1
print t
