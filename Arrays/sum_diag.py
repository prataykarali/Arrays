def sum_main_diagonal(a, n):
    total = 0
    for i in range(n):
        total += a[i][i]
    return total


# --- Taking user input ---
n = int(input("Enter size of square matrix (n x n): "))

print("Enter the matrix row by row:")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    if len(row) != n:
        print("Invalid row length. Expected", n)
        exit()
    matrix.append(row)

# --- Calling the function ---
result = sum_main_diagonal(matrix, n)
print("Sum of main diagonal:", result)
