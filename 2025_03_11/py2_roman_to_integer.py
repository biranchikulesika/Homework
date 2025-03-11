def romanToInt(romanNum):
    dict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    integer = 0
    previous_value = 0

    for i in reversed(romanNum):
        current_value = dict[i]
        if current_value < previous_value:
            integer -= current_value
        else:
            integer += current_value
        previous_value = current_value
    return integer

romanNum = input("Enter a roman number: ")
print(f"{romanNum} = {romanToInt(romanNum)}")