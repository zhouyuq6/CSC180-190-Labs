r = input('How many rows? ')
c = input('How many cols? ')
matrix = [[0]*c]*r
print matrix
for i in range(0,r):
	for j in range(0,c):
		matrix[i][j] = i*c+j
		print i,j,matrix[i][j]
print matrix

