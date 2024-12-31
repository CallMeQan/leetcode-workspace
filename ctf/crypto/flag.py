msg_original = b'thoushaltnotpass'
msg_encrypted = bytes.fromhex("b3308e2187c86d8dd21105033ad7a2a1")
from Crypto.Cipher import AES
from Crypto.Util.number import *
import numpy as np

# S-box (provided)
sbox = [
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
]

tracked_operator = [(255, 112), (194, 221), (141, 154), (124, 161), (159, 104), (250, 47), (246, 119), (219, 249), (56, 176), (230, 41), (26, 72), (107, 26), 
(59, 115), (247, 4), (221, 78), (75, 16), (34, 253), (192, 176), (6, 37), (229, 144), (179, 160), (207, 155), (171, 136), (114, 20), (35, 143), (72, 134), (18, 55), (2, 129), (220, 214), (186, 102), (196, 123), (20, 66), (47, 26), (247, 148), (214, 208), (252, 105), (167, 156), (2, 151), (204, 170), (169, 67), (145, 159), (126, 135), (186, 3), (22, 67), (27, 43), (52, 65), (169, 53), (180, 201), (166, 124), (127, 
12), (129, 246), (158, 27), (222, 153), (229, 128), (159, 95), (89, 164), (252, 174), (241, 198), (56, 224), (170, 208), (147, 16), (0, 202), (86, 40), (235, 213), (220, 117), (127, 133), (224, 184), (226, 195), (58, 176), (6, 138), (97, 87), (8, 161), (49, 251), (9, 196), (62, 41), (114, 222), (169, 215), (152, 94), (168, 248), (115, 153), (47, 219), (110, 236), (43, 35), (64, 12), (87, 197), (248, 248), (129, 64), (3, 224), (217, 132), (64, 148), (221, 191), (115, 239), (151, 68), (86, 207), (141, 13), (76, 95), (207, 223), (66, 163), (122, 184), (7, 48), (88, 216), (65, 177), (65, 123), (89, 84), (89, 121), (116, 138), (202, 207), (42, 86), (147, 114), (182, 88), (159, 47), (92, 213), (218, 14), (246, 168), (253, 159), (30, 181), (201, 97), (102, 23), (219, 82), (69, 40), (181, 78), (227, 11), (247, 147), (231, 254), (138, 122), (244, 79), (243, 106), (168, 117), (41, 36), (41, 252), (202, 161), (198, 173), (190, 192), (9, 30), (91, 33), (218, 125), (129, 
209), (236, 239), (240, 208), (217, 237), (240, 198), (6, 251), (189, 44), (151, 175), (60, 129), (129, 62), (17, 246), (235, 213), (84, 243), (246, 35), (134, 189), (198, 8), (213, 174), (255, 178), (33, 116), (151, 48), (32, 81), (220, 156), (203, 216), (202, 89), (78, 219), 
(35, 35), (145, 26), (182, 5), (81, 125), (13, 156), (92, 229), (99, 200), (84, 100), (157, 198), (84, 242), (38, 48), (202, 153), (201, 163), (165, 230), (52, 215), (224, 147), (235, 16), (120, 93), (194, 146), (130, 86), (70, 134), (36, 230), (72, 189), (192, 3), (60, 9), (231, 124), (5, 31), (74, 30), (7, 145), (130, 194), (70, 158), (106, 241), (72, 242), (59, 0), (255, 169), (145, 206), (180, 12), (177, 0), (116, 212), (64, 14), (218, 205), (22, 101), (39, 172), (232, 24), (198, 205), (126, 31), (204, 39), (48, 111), (192, 84), (137, 154), (54, 
27), (155, 28), (192, 204), (71, 250), (205, 219), (183, 59), (206, 26), (247, 79), (212, 3), (235, 240), (137, 250), (97, 117), (184, 158), (34, 18), (136, 9), (115, 198), (20, 185), (220, 249), (169, 163), (182, 90), (8, 97), (76, 34), (60, 110), (107, 82)]

for operator in tracked_operator:
    sbox[operator[0]], sbox[operator[1]] = sbox[operator[1]], sbox[operator[0]]

# Inverse S-box (calculated)
inv_sbox = [sbox.index(x) for x in range(256)]

def add_round_key(state, key):
    """Adds the round key to the state."""
    for i in range(16):
        state[i] ^= key[i]
    return state

def sub_bytes(state, inverse=False):
    """Applies the S-box (or inverse S-box) to the state."""
    box = inv_sbox if inverse else sbox
    for i in range(16):
        state[i] = box[state[i]]
    return state

def shift_rows(state, inverse=False):
    """Shifts the rows of the state."""
    if not inverse:
        state[1], state[5], state[9], state[13] = state[5], state[9], state[13], state[1]
        state[2], state[6], state[10], state[14] = state[10], state[14], state[2], state[6]
        state[3], state[7], state[11], state[15] = state[15], state[3], state[7], state[11]
    else:
        state[5], state[9], state[13], state[1] = state[1], state[5], state[9], state[13]
        state[10], state[14], state[2], state[6] = state[2], state[6], state[10], state[14]
        state[15], state[3], state[7], state[11] = state[3], state[7], state[11], state[15]
    return state

def mix_columns(state, inverse=False):
    """Mixes the columns of the state."""
    for i in range(4):
        col = state[i::4]
        if not inverse:
            col[0] ^= gf_multiply(col[1], 0x02) ^ gf_multiply(col[2], 0x03) ^ col[3]
            col[1] ^= col[0] ^ gf_multiply(col[2], 0x02) ^ gf_multiply(col[3], 0x03)
            col[2] ^= gf_multiply(col[0], 0x02) ^ col[1] ^ gf_multiply(col[3], 0x02) ^ col[3]
            col[3] ^= gf_multiply(col[0], 0x03) ^ gf_multiply(col[1], 0x02) ^ col[2] ^ col[3]
        else:
            col[0] ^= gf_multiply(col[1], 0x0e) ^ gf_multiply(col[2], 0x0b) ^ gf_multiply(col[3], 0x0d)
            col[1] ^= gf_multiply(col[0], 0x0e) ^ gf_multiply(col[2], 0x0d) ^ gf_multiply(col[3], 0x09)
            col[2] ^= gf_multiply(col[0], 0x0d) ^ gf_multiply(col[1], 0x09) ^ gf_multiply(col[3], 0x0e)
            col[3] ^= gf_multiply(col[0], 0x09) ^ gf_multiply(col[1], 0x0e) ^ gf_multiply(col[2], 0x0d)
        state[i::4] = col
    return state

def gf_multiply(a, b):
    """Multiplies two numbers in the Galois Field (2^8)."""
    p = 0
    for _ in range(8):
        if b & 1:
            p ^= a
        hi_bit_set = a & 0x80
        a <<= 1
        if hi_bit_set:
            a ^= 0x1b
        b >>= 1
    return p

def linear_cryptanalysis(plaintext, ciphertext, sbox):
    """Performs linear cryptanalysis on AES."""
    # This is a simplified example and may not cover all aspects of linear cryptanalysis
    
    # 1. Find a linear approximation for the S-box
    #    (This part is often done manually or with specialized tools)
    #    For this example, let's assume a simple approximation:
    #    input_bit[1] ^ input_bit[3] ^ output_bit[0] = 0 
    
    # 2. Collect plaintext/ciphertext pairs
    #    (Assume you have a sufficient number of pairs)

    # 3. Analyze the pairs to find the key
    key_guess = [0] * 16
    for key_byte_index in range(16):
        bias = 0
        for key_byte_guess in range(256):
            count = 0
            for pt, ct in zip(plaintext, ciphertext):
                # Partially decrypt the ciphertext
                state = list(ct)
                state = add_round_key(state, key_guess)
                state = shift_rows(state, inverse=True)
                state = sub_bytes(state, inverse=True)

                # Apply the linear approximation
                input_byte = state[key_byte_index]
                output_byte = sbox[pt[key_byte_index] ^ key_byte_guess]
                if (input_byte >> 1) & 1 ^ (input_byte >> 3) & 1 ^ output_byte & 1 == 0:
                    count += 1

            # Calculate the bias
            current_bias = abs(count / len(plaintext) - 0.5)
            if current_bias > bias:
                bias = current_bias
                key_guess[key_byte_index] = key_byte_guess

    return bytes(key_guess)

# Example usage (replace with your actual data)
plaintext = [b'thoushaltnotpass', b'thoushaltnotpass', b'thoushaltnotpass']
ciphertext = [bytes.fromhex("b3308e2187c86d8dd21105033ad7a2a1"), bytes.fromhex("4b94a44188e00a48b5edb68b1bdf1bdf"), bytes.fromhex("59fec275d707778d5f325df17232babd")]

# Perform linear cryptanalysis
recovered_key = linear_cryptanalysis(plaintext, ciphertext, sbox)
print("Recovered key:", (recovered_key.hex()))

# Test the recovered key
decrypted_text = AES.new(recovered_key, AES.MODE_ECB).decrypt(ciphertext[0])
print("Decrypted text:", decrypted_text)