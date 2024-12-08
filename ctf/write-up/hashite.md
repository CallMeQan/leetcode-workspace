# Hashite - VGU Cypher CTF for beginner

- Write-up by [Qân](https://github.com/CallMeQan)
- Thuộc phần **Crypto**

## Đánh giá

```python
from Cryptodome.Util.number import GCD
from Cryptodome.Cipher import AES

import random

a1 = 721919140332708275664160621428853988653441049264644517303176376909
a2 = 762740838008948738628397951381835990843814483667554565638672490531

k1 = 762740838008948738628397951381835990843814483667554465638672490531
k2 = 721919140332708275664160621428853988653441049264544517303176376909
k3 = 100000000000000000
k4 = 100000000000000

b1 = 2024 ** (a1 + k2 + k3) - 1
b2 = 2024 ** (a2 + k1 + k4) - 1
k = GCD(b1, b2)

random.seed(k)
k = random.randbytes(16)

iv = b"S\x0f\xac'\xd0\x18\xfb\xe3\x92\xfdoc\x93\x7fJ\xfc"
ciphertext = b"\x98\xd0\x8f;\xaa\x07\x1dJ\x9d#\\>\xa6\x14\x97$\xd7\xfb^1\xc2\x9f6\x04i\xb08\x85\x03=\xd5)"
cipher = AES.new(key=k, iv=iv, mode=AES.MODE_CBC)

flag = cipher.decrypt(ciphertext)
print(flag)
```

- Bài này dùng mã [AES](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard) dạng CBC
- Cho sẵn chúng ta `ciphertext` và `iv`.
- Nếu ta chạy script này thì sẽ tốn thời gian vì chương trình phải tính **số mũ cực lớn** ở biến `b1` và `b2`.
- Nhìn sơ qua thì thứ duy nhất chúng ta thiếu chính là `k` (key)

=> **Mình cần tìm số `k`**

## Solution

- Chúng ta chỉ nên để ý 3 dòng `b1`, `b2` và `k`.
- Theo như trong toán học thì GCD có tính chất là:

```text
GCD(x^a, x^b) = x^GCD(a, b)
hoặc
GCD(x^a + c, x^b + c) = x^GCD(a,b) + c với c là hằng số
```

- Tận dụng tính chất này, ta gọi `x = 2024`, `a = a1 + k2 + k3` và `b = a2 + k1 + k4`

```text
k = GCD(x^a, x^b) - 1
  = x^GCD(a, b) - 1
  = 2024^GCD(a1 + k2 + k3, a2 + k1 + k4) - 1
```

=> **Tính được k với thời gian nhanh hơn**.

- Sau khi đã có `k` thì chúng ta chạy script đó để decrypt ra được **flag**

## Code Solution

```python
from Crypto.Util.number import *
from Crypto.Cipher import AES

import random, sys

a1 = 721919140332708275664160621428853988653441049264644517303176376909
a2 = 762740838008948738628397951381835990843814483667554565638672490531

k1 = 762740838008948738628397951381835990843814483667554465638672490531
k2 = 721919140332708275664160621428853988653441049264544517303176376909
k3 = 100000000000000000
k4 = 100000000000000

sys.set_int_max_str_digits(100000000)
tmp = GCD(a1 + k2 + k3, a2 + k1 + k4)
k = 2024 ** tmp - 1

random.seed(k)
k = random.randbytes(16)
iv = b"S\x0f\xac'\xd0\x18\xfb\xe3\x92\xfdoc\x93\x7fJ\xfc"
ciphertext = b"\x98\xd0\x8f;\xaa\x07\x1dJ\x9d#\\>\xa6\x14\x97$\xd7\xfb^1\xc2\x9f6\x04i\xb08\x85\x03=\xd5)"

cipher = AES.new(key=k, iv=iv, mode=AES.MODE_CBC)
flag = cipher.decrypt(ciphertext)
print(flag)
```
