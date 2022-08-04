def main():
    coins = [25, 10, 5, 1]
    c = cents()
    counter = 0;
    for coin in coins:
        amount, c = divmod(c, coin)
        counter += amount
    print(counter)
def cents():
    while True:
        cents = input("Change owed: ")
        if ispositivefloat(cents):
            break
    return int(float(cents) * 100)
def ispositivefloat(num):
    try:
        float(num) and float(num) > 0
        if float(num) > 0:
            return True
        else:
            return False
    except ValueError:
        return False
main()