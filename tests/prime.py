class Wheel():
    def __init__(self, hp: int, num: int):
        self.num = num
        self.wheel_hp = hp

class Motor(Wheel):
    def __init__(self, hp, num):
        super().__init__(hp, num)