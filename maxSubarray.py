def maxSubarray(A, n):
	if n == 1:
		if A[1] < 0:
			maxSeq = maxSuf = 0
		else:
			maxSeq = A[1]
			maxSuf = A[1]
	else:
		maxSeq, maxSuf = maxSubarray(A, n-1)
		maxSuf = maxSuf + A[n]
		if (maxSuf > maxSeq):
			maxSeq = maxSuf
		elif maxSuf < 0:
			maxSuf = 0
			
	return (maxSeq, maxSuf)
			

def main():
	#A = [10, 4, 8, -25, 6, 78, 100]
	A = [13, -3, -25, 20 ,-3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
	maxSeq, maxSuf = maxSubarray(A, len(A)-1)
	print(maxSeq)
	print(maxSuf)
main()

