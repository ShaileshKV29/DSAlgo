def lcs(s1, s2):
	if (s1 == '' or s2 == ''):
		return 0

	if (s1[-1] == s2[-1]):
		return 1 + lcs(s1[:-1], s2[:-1])
	else:
		return max(lcs(s1, s2[:-1]), lcs(s1[:-1], s2))

str1 = "abcde"
str2 = "ade"

print("LCS:", lcs(str1, str2))