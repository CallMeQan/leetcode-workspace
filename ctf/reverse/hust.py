values = [268, 158, 330, 157, 353, 159, 292, 233, 360, 214, 167, 357, 169, 161]

decoded_chars = []
for i, val in enumerate(values, 1):
    ascii_val = (val - i) // 3
    decoded_chars.append(chr(ascii_val))

print(''.join(decoded_chars))