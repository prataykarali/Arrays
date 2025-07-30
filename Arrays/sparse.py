def isSparse(matrix):
    rows = len(matrix)
    cols = len(matrix[0]) if rows > 0 else 0
    total = rows * cols
    zero_count = 0

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                zero_count += 1

    return zero_count > (total // 2)


# --- Input Handling ---
if __name__ == "__main__":
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))

    print(f"Enter {rows * cols} elements (row-wise):")
    elements = list(map(int, input().split()))

    if len(elements) != rows * cols:
        print("Error: Incorrect number of elements!")
        exit()

    matrix = [elements[i * cols:(i + 1) * cols] for i in range(rows)]

    # Check and print result
    if isSparse(matrix):
        print("Matrix is Sparse.")
    else:
        print("Matrix is NOT Sparse.")
