import hashlib

# Given challenge hash
target_hash = "42ef08eff161e5aca1eb2be3b02f72a754c242a8e8de54b14841816892f49dd6"

# Generate all possible 2-character hex salts
hex_salts = [f"{x:02x}" for x in range(256)]  # "00" to "ff"

# Store the rainbow table
rainbow_table = {}

def generate_rainbow_table(cheese_list_file, output_file):
    with open(cheese_list_file, "r") as f, open(output_file, "w") as out:
        for cheese in f:
            cheese = cheese.strip()
            for salt in hex_salts:
                for salted_cheese in [salt + cheese, cheese + salt]:
                    hashed = hashlib.sha256(salted_cheese.encode()).hexdigest()
                    rainbow_table[hashed] = (cheese, salt)
                    out.write(f"{hashed},{cheese},{salt}\n")

# Search for the given hash in our rainbow table
def lookup_hash(target_hash, rainbow_file):
    with open(rainbow_file, "r") as f:
        for line in f:
            hashed, cheese, salt = line.strip().split(",")
            if hashed == target_hash:
                print(f"Match Found! Cheese: {cheese}, Salt: {salt}")
                return

# Run the attack
cheese_list_file = "cheese_list.txt"  # Replace with actual file
rainbow_file = "rainbow_table.txt"

generate_rainbow_table(cheese_list_file, rainbow_file)
lookup_hash(target_hash, rainbow_file)
