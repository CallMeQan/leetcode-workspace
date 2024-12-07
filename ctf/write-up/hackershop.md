# Hackershop - VGU Cypher CTF for beginner

- Write-up by [Qân](https://github.com/CallMeQan)
- Thuộc phần **Web**

## Đánh giá

- Vào ta thấy chả có gì ở trang login. Vì thế chúng ta tạo đại một account nào đó cũng được.
- Đăng nhập xong ta thử vào trang `VIP Service` thì báo rằng chúng ta cần 1 triệu đô

=> **Đề bài kêu mình kiếm tiền phạm pháp lên triệu đô <(")**

## Solution

- Vào phần `Shop` và inspect (Dev Tool) từng chỗ điền quantity thì thấy nó toàn xử lý ở frontend, vì thế ta có thể chỉnh nó thành số âm để công thêm tiền vào tài khoản

```html
<input type="number" min="1" value="1" name="quantity" class="border rounded-lg w-16 text-center quantity-input" oninput="
    const maxQuantity=1337;
    const quantity = Math.max(1, this.value);
    this.value = Math.min(1337, quantity);
    updateTotal(this);
">
```

- Ở đây chúng ta sẽ chỉnh `min` thành số âm cực lớn, tùy bạn chọn
- Xong vào phần javascript thì chỗ biến quantity viết thành `const quantity = Math.min(-100000000, this.value);`
- Sau cùng, ta bấm vào nút tăng giảm và nhấn mua là tiền tăng lên

=> **Quay lại trang VIP là nguyên cái flag to đùng ở đó**
