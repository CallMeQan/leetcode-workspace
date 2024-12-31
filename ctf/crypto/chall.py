from aes import *
import os

NSWAPS = 235
flag =b"flag{5w4p_5_b0x}" # 10 char
msg = b'thoushaltnotpass'
assert len(msg) == 16

# for i in range(NSWAPS):
#     indices = list(map(int, input(f"({i+1}) Bribe soldiers to swap their positions: ").split()))
#     s_box[indices[0]], s_box[indices[1]] = s_box[indices[1]], s_box[indices[0]]

key = os.urandom(16)

aes = AES(key)
ciphertext = aes.encrypt_block(msg)
print(ciphertext.hex())

flag = pad(flag)
flag_blocks = split_blocks(flag)

for i, block in enumerate(flag_blocks):
    flag_blocks[i] = aes.encrypt_block(block)

ciphertext = b''.join(flag_blocks)
print(ciphertext.hex())
