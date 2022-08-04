def main():
    number = card()
    if number == 1:
        print("INVALID")
    else:
        if luhn(number):
            digits = len(number)
            if int(number[0]) == 4 and (digits == 13 or digits == 16):
                print("VISA")
            elif 51 <= int(number[0 : 2]) <= 55 and digits == 16:
                print("MASTERCARD")
            elif (int(number[0 : 2]) == 34 or int(number[0 : 2]) == 37) and digits == 15:
                print("AMEX")
        else:
            print("INVALID")
def card():
    while True:
        card = input("Number: ")
        if card.isdigit() and int(card) > 0:
            if 15 <= len(card) <= 16 or len(card) == 13:
                return card
                break
            else:
                return 1
def luhn(num):
    digits = len(num)
    total = 0
    for i in range(digits - 2, -1, -2):
        T = str(int(num[i]) * 2)
        for t in T:
            total += int(t)
    for i in range(digits - 1, -1, -2):
        total += int(num[i])
    if total % 10 == 0:
        return True
    else:
        return False
main()