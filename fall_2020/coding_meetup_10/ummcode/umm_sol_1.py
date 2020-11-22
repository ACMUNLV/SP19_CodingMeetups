# Author: Michael Lazeroff
# Solution To: Problem L "Umm Code" ICPC Mid Central USA Programming Contest 2019


import string

def get_valid_words(txt: list):
    """
    Returns a single string of the valid um words
    """

    um_index = []     # holds the indices of the valid code words

    # get an individual word from the list
    for n in range(len(txt)):
        valid_word = 1

        # check that all letters are valid from the word
        for i, my_string in enumerate(txt[n]):
            # if the word is not valid, skip checking the rest of the letters
            if valid_word == 0:
                break
        
            # check if u or m exists
            if my_string == 'u' or my_string == 'm':
                # valid word flag still okay
                valid_word = 1
                continue        
        
            # if not 'u' or 'm', check if its a punctuation : punctuation = r"""!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~"""
            if my_string in string.punctuation:
                # remove the letter from the
                txt[n] = txt[n].replace(my_string, '')
                continue
            
            # not u or m or punctuation, so the word is not valid
            valid_word = 0
        
        if valid_word == 1:
            um_index.append(n) # store index valud of valid word

    um_words = ''.join([txt[x] for x in um_index])

    return um_words

    
if __name__ == "__main__":
    words = get_valid_words(input().split())
    words = words.replace('u', '1')
    words = words.replace('m', '0')

    my_string = ""
    index = 0
    while index < len(words):
        # obtain substrings of length 7
        temp = words[index:index+7]
        # obtain the ascii character for the binary string
        my_string += chr(int(temp,2))
        index += 7

    print(my_string)
