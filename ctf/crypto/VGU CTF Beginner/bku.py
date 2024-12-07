from Crypto.Util.number import *

def findRoot5(n):
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
n = 7523781293140998607451882096704898796076092163768565712087304200400215182324649756379410550440078065696237920534742477367296417081567197022585004494811747112405395156433652625202701411069818962996111021550888868994580529474626863240129996025209501356954098924184516382540213973640819244323987746778398867413695102245486410427979362115295594344934021796224360757228881967426156002018321
c = 4729122893508615191771352786568915014346246411614871012234877237922860851735802928814473060256192132857449564416323273716257659218305207571708060526806472749554309241758961713355359581995441282127257747583371573728547414963278837476634079999670488941162853620381858983697092979433648494756361505238332494483156763612970345610230661824490177784657989863074372327071370000873414402434703
e = 0x10001

# Decryption

p = findRoot5(n*n//4)
print(p)
ansp = 0
ansq = 0

for p_dutinh in range(p - 100000, p + 100000):
    if (n % p_dutinh == 0):
        ansp = p_dutinh
        ansq = n // p_dutinh

# Google search: RSA modulus factorization
phi = (ansp - 1) * (ansq - 1)
d = pow(e, -1, phi)
m = pow(c, d, n)

print(long_to_bytes(m))