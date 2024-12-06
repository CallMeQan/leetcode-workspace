import random

def to_file(name: str, data: any) -> None:
    with open(name, 'w') as f:
        f.write(str(data))

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

def caesar_cipher_encrypt(string, keys):
    encrypted_string = ""
    for i, char in enumerate(string):
        key = keys[i % len(keys)]  # Cycle through keys
        if char.isalpha():
            offset = ord('a') if char.islower() else ord('A')
            encrypted_char = chr((ord(char) - offset + key) % 26 + offset)
        else:
            encrypted_char = char  # Non-alphabetic characters remain the same
        encrypted_string += encrypted_char
    return encrypted_string

# Example usage
input_str = "gidijyqhy{tc1iu_1t_m0_czt_kadojn}" # length is 9
output_str ="vgucypher"

first_str = ['t','c','1','i','u']
second_str = ['1','t']
third_str = ['m','0']
fourth_str = ['c','z','t']
fifth_str = ['k','a','d','o','j','n']
keys = [11,2,9,6,11,9,9,3,7,14,1,21,16,3,1,15,7,6,14,19,11,18,9,18,15,23,19,19,5,21,2,1,4]
# 0 is unknown key
print(len(keys))
print(caesar_cipher_decrypt(input_str, keys))
""" 
    Don't you want me
    Just the two of us, We
    Welcome to the Hotal Calif
    Never put my love out on the line
    what a wonderful 16
    I shouldn't
    Just give
    Feeling my
    I'll be b
    Turn down
"""
