import re
from pynput.keyboard import Key, KeyCode
keymap = {
    8: "Backspace",
    9: "Tab",
    13: "Enter",
    16: "Shift",
    17: "Ctrl",
    18: "Alt",
    20: "Caps Lock",
    27: "Escape",
    32: "Space",
    33: "Page Up",
    34: "Page Down",
    35: "End",
    36: "Home",
    37: "Arrow Left",
    38: "Arrow Up",
    39: "Arrow Right",
    40: "Arrow Down",
    45: "Insert",
    46: "Delete",
    48: "0",
    49: "1",
    50: "2",
    51: "3",
    52: "4",
    53: "5",
    54: "6",
    55: "7",
    56: "8",
    57: "9",
    65: "A",
    66: "B",
    67: "C",
    68: "D",
    69: "E",
    70: "F",
    71: "G",
    72: "H",
    73: "I",
    74: "J",
    75: "K",
    76: "L",
    77: "M",
    78: "N",
    79: "O",
    80: "P",
    81: "Q",
    82: "R",
    83: "S",
    84: "T",
    85: "U",
    86: "V",
    87: "W",
    88: "X",
    89: "Y",
    90: "Z",
    96: "Numpad 0",
    97: "Numpad 1",
    98: "Numpad 2",
    99: "Numpad 3",
    100: "Numpad 4",
    101: "Numpad 5",
    102: "Numpad 6",
    103: "Numpad 7",
    104: "Numpad 8",
    105: "Numpad 9",
    106: "Numpad Multiply",
    107: "Numpad Add",
    109: "Numpad Subtract",
    110: "Numpad Decimal",
    111: "Numpad Divide",
    112: "F1",
    113: "F2",
    114: "F3",
    115: "F4",
    116: "F5",
    117: "F6",
    118: "F7",
    119: "F8",
    120: "F9",
    121: "F10",
    122: "F11",
    123: "F12",
    144: "Num Lock",
    145: "Scroll Lock",
    186: ";",
    187: "=",
    188: ",",
    189: "-",
    190: ".",
    191: "/",
    192: "`",
    219: "[",
    220: "\\",
    221: "]",
    222: "'",
}

def parse_log_line(line):
    # Regular expression to extract relevant information from the log line
    pattern = re.compile(
        r'(?P<event>KeyPress|KeyRelease) event, serial \d+, synthetic NO, window \w+, root \w+, subw \w+, time (?P<time>\d+), \(\d+,\d+\), root:\(\d+,\d+\), state \w+, keycode (?P<keycode>\d+) \(keysym \w+\), same_screen YES'
    )
    match = pattern.match(line)
    if match:
        return match.group('event'), int(match.group('time')), int(match.group('keycode'))
    return None

def follow_log_file(file_path):
    keycodes = []
    with open(file_path, 'r') as file:
        for line in file:
            parsed = parse_log_line(line.strip())
            if parsed:
                event, time, keycode = parsed
                keycodes.append(keycode)
    
    # Convert keycodes to characters
    password = ""
    for keycode in keycodes:
        if keycode in keymap:
            password += keymap[keycode]
        else:
            password += f" ({keycode}) "
    
    print(f"Password: {password}")

if __name__ == "__main__":
    log_file_path = 'keys.log'  # Replace with your log file path
    follow_log_file(log_file_path)