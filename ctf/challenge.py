# import bad_prng
# import random

# flag = ""
# output = []
# random = bad_prng.generate_seed()
# for c in flag:
#     random = bad_prng.rand_word()
#     output.append(random ^ ord(c))

# # 23b126b5f2dc627b8afcd8cf42ccd71bf5dceee9e2472d76
# print(bytes(output).hex())
a = "23b126b5f2dc627b8afcd8cf42ccd71bf5dceee9e2472d76"
a_bytes = bytes.fromhex(a)
print(a_bytes)
b = b"bronco" # Flag starts with "bronco"
b_bytes = a_bytes[:len(b)]
prng_outputs = [c ^ p for c, p in zip(b_bytes, b)]
print(prng_outputs)

m = 256
possible_params = []

for a in range(1, 256):
    for c in range(1, 256):
        test_seq = [prng_outputs[0]]
        for _ in range(5):
            test_seq.append((a * test_seq[-1] + c) % m)

        if test_seq[:6] == prng_outputs:
            possible_params.append((a, c))

print(possible_params)

# ChatGPT generated belows
a, c, m = 131, 128, 256
prng_sequence = [prng_outputs[0]]
for _ in range(len(a_bytes) - 1):
    prng_sequence.append((a * prng_sequence[-1] + c) % m)

flag_bytes = bytes(c ^ p for c, p in zip(a_bytes, prng_sequence))
flag = flag_bytes.decode(errors="ignore")
print(flag)