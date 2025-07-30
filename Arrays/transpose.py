from typing import List


class Solution:
    def transpose(self, mat: List[List[int]]) -> List[List[int]]:
        # Create a matrix with dimensions swapped (columns x rows)
        b = [[0] * len(mat) for _ in range(len(mat[0]))]

        for i in range(len(mat)):
            for j in range(len(mat[0])):
                b[j][i] = mat[i][j]

        return b


# --- Input handling ---
if __name__ == "__main__":
    # Take input for number of rows and columns
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))

    print(f"Enter {rows * cols} elements (row-wise):")
    elements = list(map(int, input().split()))

    if len(elements) != rows * cols:
        print("Error: Incorrect number of elements!")
        exit()

    # Convert flat list to 2D matrix
    mat = [elements[i * cols:(i + 1) * cols] for i in range(rows)]

    # Create object and call method
    sol = Solution()
    result = sol.transpose(mat)

    print("Transposed Matrix:")
    for row in result:
        print(row)
