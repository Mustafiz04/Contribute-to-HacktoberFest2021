# Problem Statement : Given a string S, partition A such that every substring of the partition is a palindrome.
# Return the minimum cuts needed for a palindrome partitioning of S.

# function for checking given string is palindrome or not
def isPalindrome(s, i, j):
    while i <= j:
        if s[i] == s[j]:
            i += 1
            j -= 1
        else:
            return False
    return True

def solve(s, i, j):
    # base condition
    if i >= j:
        return 0

    # if cached value is present return it
    if dp[i][j] != -1:
        return dp[i][j]

    # if given string is palindrome then return 0
    if isPalindrome(s, i, j):
        return 0

    ans = float('inf')
    for k in range(i, j):
        left = dp[i][k]
        if dp[i][k] == -1:
            left = solve(s, i, k)

        right = dp[k+1][j]
        if dp[k+1][j] == -1:
            right = solve(s, k+1, j)

        temp = 1 + left + right
        ans = min(temp, ans)

    # caching the answer
    dp[i][j] = ans
    return ans


s = 'ababbbabbababa'
dp = [[-1 for _ in range(len(s))] for _ in range(len(s))]
no_of_partitions = solve(s, 0, len(s)-1)
# printing the minimum no of partitions required
print(no_of_partitions)
