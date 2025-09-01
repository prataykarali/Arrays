def count_min_reversals(expr: str, open_br: str, close_br: str) -> int:
    n = len(expr)
    if n % 2 != 0:
        return -1  # odd length can't be balanced

    stack = []
    for ch in expr:
        if ch == close_br and stack and stack[-1] == open_br:
            stack.pop()
        else:
            stack.append(ch)

    unbalanced_len = len(stack)
    opening_count = stack.count(open_br)

    return (unbalanced_len // 2) + (opening_count % 2)


def min_reversals_all(expr: str) -> int:
    # Separate expressions by bracket type
    curly = "".join([ch for ch in expr if ch in "{}"])
    square = "".join([ch for ch in expr if ch in "[]"])
    round_b = "".join([ch for ch in expr if ch in "()"])

    # Solve individually
    res_curly = count_min_reversals(curly, '{', '}') if curly else 0
    res_square = count_min_reversals(square, '[', ']') if square else 0
    res_round = count_min_reversals(round_b, '(', ')') if round_b else 0

    # If any impossible (-1), return -1
    if -1 in [res_curly, res_square, res_round]:
        return -1

    return res_curly + res_square + res_round


# Example usage
expr = "}{{}}{{{[(])"
print("Minimum reversals:", min_reversals_all(expr))
