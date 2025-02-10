#!/usr/local/bin/python3

from Crypto.Util.number import isPrime, getPrime

def RSAaaS():
    try:
        print("Welcome to my RSA as a Service! ")
        print("Pass me two primes and I'll do the rest for you. ")
        print("Let's keep the primes at a 64 bit size, please. ")
        while True:
            p = 18446744073709551557
            q = 18446744073709551533 # 2 largest prime

            #p = 9223372036854775837
            #q = 9223372036854775907 # 2 smallest prime
            try:
                p = int(p)
                q = int(q)
                assert isPrime(p)
                assert isPrime(q)
            except:
                print("Hm, looks like something's wrong with the primes you sent. ")
                print("Please try again. ")
                continue

            try:
                assert p != q
            except:
                print("You should probably make your primes different. ")
                continue

            try:
                assert (p > 2**63) and (p < 2**64)
                assert (q > 2**63) and (q < 2**64)
                break
            except:
                print("Please keep your primes in the requested size range. ")
                print("Please try again. ")
                continue

        print("Here are your primes: ")
        print(p)
        print(q)
        n = p * q
        print('n = ', n)
        phi = (p - 1) * (q - 1) # always positive
        print('phi = ', phi)
        e = 65537
        d = pow(e, -1, phi)
        print('d = ', d)

        print("Alright! RSA is all set! ")
        while True:
            print("1. Encrypt 2. Decrypt 3. Exit ")
            choice = input("Pick an option: ")

            if choice == "1":
                msg = input("Input a message (as an int): ")
                try:
                    msg = int(msg)
                except:
                    print("Hm, looks like something's wrong with your message. ")
                    continue
                encrypted = pow(msg, e, n)
                print("Here's your ciphertext! ")
                print(encrypted)

            elif choice == "2":
                ct = input("Input a ciphertext (as an int): ")
                try:
                    ct = int(ct)
                except:
                    print("Hm, looks like something's wrong with your message. ")
                    continue
                decrypted = pow(ct, d, n)
                print("Here's your plaintext! ")
                print(decrypted)

            else:
                print("Thanks for using my service! ")
                print("Buh bye! ")
                break

    except Exception:
        print("Oh no! My service! Please don't give us a bad review! ")
        print("Here, have a complementary flag for your troubles. ")
        with open("flag.txt", "r") as f:
            print(f.read())

stored_list = []
RSAaaS()
# while True:
#     p = getPrime(64)
#     q = getPrime(64)
#     if (p, q) in stored_list:
#         continue
#     if (p - 1) * (q - 1) % 65537 == 0:
#         print(p)
#         print(q)
#         break
#     else:
#         stored_list.append((p, q))
#         if len(stored_list) % 10000 == 0:
#             print(len(stored_list))
# 17513920800700560433
# 14362469095839962327