def ispalindrome(s,i,j):

	while i < j:

		if s[i] != s[j]:

			return False

		i += 1
		j -= 1

	return True 

def partition(s,i,j):

	if i == j:

		return 0

	if ispalindrome(s,i,j):

		return 0

	ans = float('inf')

	for k in range(i,j):

		temp1 = partition(s,i,k)

		temp2 = partition(s,k+1,j)

		ans = min(temp1+temp2+1,ans)

	return ans

s = 'aab'

print(partition(s,0,len(s)-1))
