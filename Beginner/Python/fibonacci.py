# Program to print fibonacci sequence till nth number.
n = int(input("Enter desired length of Fibonacci Sequence: "))
if n <= 0:
	print("\nInvalid Input!\n")
else:
	print("\nFibonacci Sequence:")
	fib = [0, 1]
	l = 2
	for i in range(2, n):
		fib.append(fib[l-1]+fib[l-2])
		l += 1
	print(' '.join(map(str, fib[:n])))
