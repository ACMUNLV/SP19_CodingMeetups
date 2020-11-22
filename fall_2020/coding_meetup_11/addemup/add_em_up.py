# Author: Michael Lazeroff
# Solution: Add Em Up -> ICPC Northeast North America Regional Contest 2019

from collections import Counter

# -> sees function name -> monkahmmmmmmmmmmmmmmmmmmmmmmm - Ben
def rev_me_papi(num: int) -> int:
    """
    Takes an integer, and returns the reversed integer if possible.
    """
    REVERSIBLE = {'0', '1', '2', '5', '6', '8', '9'}
    num_str = list(str(num))
    for index, i in enumerate(num_str):
        # If our current digit is not reversible, the whole card is not
        if i not in REVERSIBLE:
            return num

        # If our current digit is either 6 or 9, we have to change them
        if i == '6':
            num_str[index] = '9'
            continue

        if i == '9':
            num_str[index] = '6'

    num_str = ''.join(num_str)

    return int(num_str[::-1])   # Reverse the string


def do_the_stuff(meta_line: str = None, card_line: str = None):
    num_cards, desired_sum = meta_line.split(' ')
    num_cards = int(num_cards)
    desired_sum = int(desired_sum)

    # Create a list of ints for the cards
    cards = [int(card) for card in card_line.split(' ')]
    
    # Create a list that has the normal cards, + reversal of the cards if possible
    # Dont reverse a card if it is the same forwards and backwards
    all_nums = cards + [rev_me_papi(card) for card in cards if rev_me_papi(card) != card]

    # Create a dictionary that has the num as a key, and how many times it shows up
    all_nums = Counter(all_nums)

    for num in all_nums:
        need = desired_sum - num
        if need in all_nums:
            # If the number we need is in the dictionary, make sure it occurs more than once
            # If it doesn't occur more than once, then it is just the reversal of the same number
            if need == num or need == rev_me_papi(num):
                return True if all_nums[need] > 1 else False
            else:
                return True

    return False

    
if __name__ == "__main__":
    meta_line = input()
    card_line = input()
    if do_the_stuff(meta_line, card_line):
        print('YES')
    else:
        print('NO')
