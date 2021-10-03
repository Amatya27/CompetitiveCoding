def check_square(number):
    if number == 1:
        return True
    factors_list = [0]
    i = 2
    while number != 1:
        if number % i == 0:
            factors_list.append(i)
            number = number / i
        else:
            i += 1
    if len(factors_list) != 2:
        factors_list.pop(0)
        if len(factors_list) % 2 != 0:
            factors_list.append(0)
    i = 0
    while True:
        if factors_list[i] == factors_list[i+1]:
            factors_list.pop(i)
            factors_list.pop(i)
        if len(factors_list) == 0:
            return True
        if factors_list[i] != factors_list[i + 1]:
            return False



def main():
    number = int(input("Enter a number : "))
    print(check_square(number))
    # check_square(number)


main()
