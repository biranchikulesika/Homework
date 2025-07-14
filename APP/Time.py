class Time:
    def __init__(self, h, m, s):
        self.h = h
        self.m = m
        self.s = s

    def add(self, other):
        total_sec = self.s + other.s
        total_min = self.m + other.m + (total_sec // 60)
        total_hr = self.h + other.h + (total_min // 60)
        total_min %= 60
        total_sec %= 60
        return Time(total_hr, total_min, total_sec)

    def display(self):
        print(f"{self.h} hour(s), {self.m} minute(s), {self.s} second(s)")


t1 = Time(1, 45, 40)
t2 = Time(2, 30, 50)
t3 = t1.add(t2)
t3.display()
