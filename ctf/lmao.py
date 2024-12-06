# Inspired by https://www.youtube.com/watch?v=Fs3EbH-Wdhc

import requests
import base64
from tqdm import tqdm

ADDRESS = "http://mercury.picoctf.net:10868/"

s = requests.Session()
s.get(ADDRESS)
cookie = s.cookies["auth_name"]
decoded_cookie = base64.b64decode(cookie)
raw_cookie = base64.b64decode(decoded_cookie)

for pos_idx in tqdm(range(0, len(raw_cookie))):
    for bit_idx in range(0, 8):
        bitflip = (
            raw_cookie[0:pos_idx]
            + ((raw_cookie[pos_idx] ^ (1 << bit_idx)).to_bytes(1, "big"))
            + raw_cookie[pos_idx + 1 :]
        )

        tmp = base64.b64encode(base64.b64encode(bitflip)).decode()
        r = requests.get(ADDRESS, cookies={"auth_name": tmp})
        if "picoCTF{" in r.text:
            print("Flag: " + r.text.split("<code>")[1].split("</code>")[0])
