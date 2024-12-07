
def caesar_cipher_decrypt(string, keys):
    decrypted_string = ""
    for i, char in enumerate(string):
        key = keys[i % len(keys)]  # Cycle through keys
        if char.isalpha():
            offset = ord('a') if char.islower() else ord('A')
            decrypted_char = chr((ord(char) - offset - key) % 26 + offset)
        else:
            decrypted_char = char  # Non-alphabetic characters remain the same
        decrypted_string += decrypted_char
    return decrypted_string

input_str = "gidijyqhy{tc1iu_1t_m0_czt_kadojn}"
keys = [11,2,9,6,11,9,9,3,7,14,1,21,16,3,1,15,7,6,14,19,11,18,9,18,15,23,19,19,5,21,2,1,4]

print(caesar_cipher_decrypt(input_str, keys))
""" 
    Don't you want me
    Just the two of us, We can make i
    Welcome to the Hotel California
    Never put my love out on the line
    what a wonderful world this is
    I shouldn't have let you go
    Just give me a reason, just a
    Feeling my way through the darkness
    I'll be by your side, 'til the dark
    Turn down for what
"""
