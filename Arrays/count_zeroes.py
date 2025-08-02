class Solution:
    def countZeroes(self, a, n):
        row = 0
        col = n - 1
        count = 0

        while row < n and col >= 0:
            if a[row][col] == 0:
                count += (col + 1)
                row += 1
            else:
                col -= 1

        return count


# --- Taking user input ---
n = int(input("Enter size of square matrix (n x n): "))

print("Enter the matrix row by row (0s and 1s only):")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    if len(row) != n:
        print("Invalid row length. Expected", n)
        exit()
    matrix.append(row)

# --- Calling the function ---
sol = Solution()
result = sol.countZeroes(matrix, n)
print("Total number of 0s:", result)