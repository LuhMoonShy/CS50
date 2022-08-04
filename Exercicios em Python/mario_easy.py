def main():
    h = height()
    for row in range(h):
        print(" " * (h - row - 1), end="")
        print("#" * (row + 1), end="")
        print()
def height():
    while True:
        height = input("Height: ")
        if "1" <= height <= "8":
            break
    return int(height)
main()