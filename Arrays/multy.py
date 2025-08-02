def multiply_polynomials(A, B):
    # Initialize result array with zeros
    result_degree = len(A) + len(B) - 2
    result = [0] * (result_degree + 1)

    # Multiply each term of A with each term of B
    for i in range(len(A)):
        for j in range(len(B)):
            result[i + j] += A[i] * B[j]

    return result


def input_polynomial(name):
    degree = int(input(f"Enter degree of polynomial {name}: "))
    print(f"Enter {degree + 1} coefficients for {name} from constant term to x^{degree}:")
    coeffs = list(map(int, input().split()))
    while len(coeffs) != degree + 1:
        print(f"Error: Please enter exactly {degree + 1} coefficients.")
        coeffs = list(map(int, input().split()))
    return coeffs


def pretty_print(poly):
    terms = []
    for i in range(len(poly)):
        coeff = poly[i]
        if coeff != 0:
            term = str(coeff)
            if i == 1:
                term += "x"
            elif i > 1:
                term += f"x^{i}"
            terms.append(term)
    return " + ".join(terms[::-1]) if terms else "0"


# ---- Main Program ----
print("Polynomial Multiplication Program")
A = input_polynomial("A")
B = input_polynomial("B")

product = multiply_polynomials(A, B)

print("\nPolynomial A:", pretty_print(A))
print("Polynomial B:", pretty_print(B))
print("Product A * B:", pretty_print(product))
