import hashlib
from itertools import combinations

# Given hash and username
given_hash = "ea23f261fff0ebc5b0a5d74621218e413a694ed0815a90615cf6edd7b49e6d0d"
base_name = "yoshiethehomie"
flag_format = "bronco"

# Leetspeak mappings (only apply partial replacements)
leet_map = {
    "a": ["4", "@"],
    "e": ["3"],
    "i": ["1", "!"],
    "o": ["0"],
    "s": ["5"],
    "t": ["7"],
    "z": ["2"],
}


def generate_partial_leetspeak(name):
    """Generates username variations with limited leetspeak replacements."""
    variants = [name]
    for i in range(1, len(name)):
        for subset in combinations(range(len(name)), i):
            for leet_char in leet_map.get(name[subset[0]], []):
                new_name = list(name)
                for j in subset:
                    new_name[j] = leet_char
                variants.append("".join(new_name))
    return variants

def hash_and_check(password):
    """Hashes a password and checks if it matches the given hash."""
    hashed = hashlib.sha256(password.encode()).hexdigest()
    return hashed == given_hash

# Generate username variations with partial leetspeak
username_variants = generate_partial_leetspeak(base_name)

# Brute-force the 4-digit PIN
for username in username_variants:
    for pin in range(10000):  # 0000 to 9999
        password = f"{flag_format}{{{username}{pin:04d}}}"
        if hash_and_check(password):
            print(f"[+] Found password: {password}")
            exit()

print("[-] No match found.")
