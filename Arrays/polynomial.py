def addPolynomials(A, B):
    # Get maximum length
    max_len = max(len(A), len(B))

    # Extend both lists to same size
    A += [0] * (max_len - len(A))
    B += [0] * (max_len - len(B))

    # Add corresponding terms
    result = [A[i] + B[i] for i in range(max_len)]
    return result


def inputPolynomial(name):
    degree = int(input(f"Enter the degree of polynomial {name}: "))
    print(f"Enter {degree + 1} coefficients for {name} starting from constant term:")
    coeffs = list(map(int, input().split()))

    while len(coeffs) != degree + 1:
        print(f"Please enter exactly {degree + 1} coefficients.")
        coeffs = list(map(int, input().split()))
    return coeffs


# ---- Main Program ----
print("Polynomial Addition Program")
A = inputPolynomial("A")
B = inputPolynomial("B")

sum_poly = addPolynomials(A, B)
print("Sum of polynomials (coefficients):", sum_poly)

# Optional: Pretty print as polynomial
terms = []
for i, coeff in enumerate(sum_poly):
    if coeff != 0:
        term = str(coeff)
        if i == 1:
            term += "x"
        elif i > 1:
            term += f"x^{i}"
        terms.append(term)

if terms:
    print("Polynomial form:", " + ".join(terms))
else:
    print("Polynomial form: 0")