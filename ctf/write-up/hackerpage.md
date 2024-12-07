# Hackerpage - VGU Cypher CTF for beginner

- Write-up by [Qân](https://github.com/CallMeQan)
- Thuộc phần **Web**

## Đánh giá

chả có gì, chỉ là tận dụng Dev Tool của Chrome thôi

## Solution

- Vào trang Flag, mở dev tool lên đi dò thì ta sẽ thấy phần thứ nhất của flag: `vgucypher{1n5p3c1` và dưới đó có ghi `robots.txt`
- Sau đó ta thử truy cập file robots.txt bằng url `http://ctf.vgucypher.id.vn:3000/robots.txt`, nó hiện ra có dòng `Disallow: /extremely_secret_1209892/`
- Tiếp tục truy cập nó bằng url `http://ctf.vgucypher.id.vn:3000/extremely_secret_1209892/` sẽ hiện ra Part 2 và cùng input bị ẩn. Mở dev tool lên và inspect nó sẽ cho ra phần thứ 2 của flag `_c@r3FV11y`

Sau đó quay lại trang Flag:

- Mở dev tool lên
- Vào tab `Network`
- Nếu không có gì thì F5 để tải lại trang
- bấm vào `flag.html` và vào tab Header
- Đọc từ trên xuống sẽ lần lượt có flag phần thứ 4 và thứ 3

=> **Ghép lại thành Flag**
