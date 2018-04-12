def polynomailEvaluationFirst(A, n, x):
	if n == 0:
		P = A[0]
	else:
		P = polynomailEvaluationFirst(A, n-1, x)
		xn = 1
		for i in range(0, n):
			xn = xn *x
		P = P + A[n]*xn
		
	return P

def polynomailEvaluationSecond(A, n, x):
	if n == 0:
		P = A[0]
		xn = 1
	else:
		P, xn = polynomailEvaluationSecond(A, n-1, x)
		xn = xn * x
		P = P + A[n]*xn
		
	return (P, xn)

def polynomailEvaluationThird(A, n, i, x):
	if i == 0:
		P = A[n]
	else:
		P_line = polynomailEvaluationThird(A, n, i-1, x)
		P = x*P_line + A[n-1]
		
	return P	

def main():
	A = [10, 4, 8, -25, 6, 78, 100]
	#A = [0, 0, 0, 0, 0, 0, 1]
	P1 = polynomailEvaluationFirst(A, len(A)-1, 2)
	print("P1: " + str(P1)) 
	
	P2, xn2 = polynomailEvaluationSecond(A, len(A)-1, 2)
	print("P2: " + str(P2)) 
	print("xn2: " + str(xn2))
	
	P3 = polynomailEvaluationThird(A, len(A)-1, 0, 2)
	print("P3: " + str(P3)) 
main()
