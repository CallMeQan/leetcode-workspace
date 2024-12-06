import requests, os

def get_request_with_secret_key(url, secret_key):
    params = {'secret_key': secret_key}
    response = requests.get(url, params=params)
    return response

# Example usage
url = 'https://5465aaf8fcebbe76.247ctf.com/flag'
secret_key = 'your_secret_key'
response = get_request_with_secret_key(url, secret_key)
store_finded = []
while True:
    new_key = os.urandom(24)
    response = get_request_with_secret_key(url, new_key)
    if response.text == "Incorrect secret key!":
        store_finded.append(new_key)
    else:
        print(new_key)
        break