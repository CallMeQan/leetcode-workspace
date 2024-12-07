# A Gift from BKU Brother - VGU Cypher CTF for beginner

- Write-up by [Qân](https://github.com/CallMeQan)
- Thuộc phần **Crypto**

## Đánh giá

```python
from Crypto.Util.number import getPrime, isPrime, bytes_to_long
from math import isqrt

def genModulus(bit = 512):
    while True:
        p = getPrime(bit)
        q = (isqrt(p ** 3 - p + 1) + isqrt(p ** 3 + p + 1))
        q |= 1
        if isPrime(q):
            return p, q
        
p, q = genModulus()
n = p * q
e = 0x10001
m = bytes_to_long(b'vgucypher{REDACTED}')
c = pow(m, e, n)

print(f'{n = }')
print(f'{c = }')
# n = số rất dài
# c = số rất dài
```

- Bài này sử dụng mã [RSA 512 bit](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) để mã hóa chuỗi `vgucypher{REDACTED}`. Nhưng họ cho ta 2 dòng cuối số `n` và `c` để tìm ngược lại chuỗi bị mã hóa đó.
- Khi đọc vào file ta sẽ thấy số `n` sẽ phụ thuộc 2 số nguyên tố lớn `p` và `q` mà chương trình tìm được trong hàm `genModulus`. Mà theo như công thức giải mã RSA thì ta cần có số `n` và `c`.
- Để ý trong hàm `genModulus` thì ta thấy rằng số `p` được gen random trong khoảng `2^511 <= p < 2^512`.
- Và số `q` được tìm dự vào công thức `sqrt(p^3 - p + 1) + sqrt(p^3 + p + 1)` và check liên tục coi `q` có phải là số nguyên tố không?

=> **Ta cần tìm số nguyên tố `p` và `q`**

## Cách giải bằng toán học

### Rút gọn phương trình `n = p * q`

```text
ta có q = sqrt(p^3 - p + 1) + sqrt(p^3 + p + 1)
n = p * q
  = p * (sqrt(p^3 - p + 1) + sqrt(p^3 + p + 1))
  ...
=> n^2 = 2p^8 + 6p^5 - 2p^4 + 5p^2
```

- Sau khi rút gọn phương trình để đưa về dạng `n` phụ thuộc vào `p`, nó vẫn quá phức tạp để tính.
- Vì phức tạp nên mình sẽ bỏ bớt `p+1` trong cả 2 căn. Khi đó công thức cho q sẽ là `q = sqrt(p^3) + sqrt(p^3) = 2 * sqrt(p^3)` với sai số nhưng mình sẽ tính sau

### Rút gọn phương trình `n = p * q` lần 2

``` text
n = p * q
  = p * sqrt(p^3) * 2
=> n/4 = p^5
```

=> **Vậy thứ mình cần tìm chính là `p^5`**

### Áp dụng

- Dự vào đề bài ban đầu, ta biết được `p` sẽ nằm trong khoảng `[0, n]` vì mình sẽ dùng [chặt nhị phân](https://wiki.vnoi.info/algo/basic/Binary-Search) để tìm `p`. Ta sẽ cập nhật biến `ans` liên tục cho đến khi `l > r`.

```python
def findRoot5(n): # Binary search
    l = 0
    r = n
    ans = 1
    while l <= r:
        mid = (l + r) // 2
        if mid ** 5 <= n: # p phải mũ 5 lên để cho bằng số n nạp vào
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    return ans

p = findRoot5(n*n // 4) # Sử dụng // của python để xử lý số lớn
```

- Sau khi chặt xong, ta có được số `p` nhưng đó chỉ là **số dự tính** bởi chúng ta sử dụng công thức với sai số lớn.
- Vì thế ta phải chạy vòng for để tìm số p chính xác, ta biết `n = p * q` thì q phải là đáp án của `n mod p == 0`. Nhưng để khoảng để chạy bao nhiêu thì không biết.
- Ở đây mình chạy thủ công cho khoảng là `p - 10 <= ans_p <= p + 10` và cứ tăng dần khoảng lên

```python
ansp = 0
ansq = 0

for p_dutinh in range(p - 10, p + 10): # Cứ tăng khoảng tìm kiếm lên
    if (n % p_dutinh == 0):
        ansp = p_dutinh
        ansq = n // p_dutinh
```

- Sau khi tìm được 2 con số nguyên tố quan trọng nhất là `ansp` và `ansq` thì ta cứ áp dụng công thức giải mã RSA (tìm trên google) là ra!

## **Cảm ơn vì đã đọc tới đây >w<**

### Code solution

```python
from Crypto.Util.number import *

def findRoot5(n): # Binary search
    l = 0
    r = n
    ans = 1
    while l <= r:
        mid = (l + r) // 2
        if mid ** 5 <= n: # p with math prove is 5
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    return ans

# Default input
n = # số rất lớn lmao
c = # số rất lớn
e = 0x10001

# Decryption
p = findRoot5(n*n//4)
ansp = 0
ansq = 0

for p_dutinh in range(p - 100000, p + 100000):
    if (n % p_dutinh == 0):
        ansp = p_dutinh
        ansq = n // p_dutinh

# Google search: rsa decrypt formula
phi = (ansp - 1) * (ansq - 1)
d = pow(e, -1, phi)
m = pow(c, d, n)

print(long_to_bytes(m))
```

=> `b'vgucypher{1_gU3s5 ... }'`
