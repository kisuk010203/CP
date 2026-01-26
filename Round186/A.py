t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    is_new_year = ("2026" in s) or ("2025" not in s)
    if is_new_year:
        print(0)
    else:
        print(1)