def is_identity(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if (i == j and matrix[i][j] != 1) or (i != j and matrix[i][j] != 0):
                return False
    return True

# Example usage
n = int(input("Enter size of square matrix: "))
matrix = []

print("Enter matrix row by row:")
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

if is_identity(matrix):
    print("Identity Matrix ✅")
else:
    print("Not an Identity Matrix ❌")
