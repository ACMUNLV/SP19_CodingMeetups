string = input()
alphabet = [0] * 26

# there is another way to do it without sorting, just keep track of the two
# max frequencies
for letter in string:
    alphabet[ord(letter) - 97] += 1
alphabet.sort()
print(len(string) - (alphabet[25] + alphabet[24]))
