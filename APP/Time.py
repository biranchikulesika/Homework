class Time:
    def __init__(self, hours=0, minutes=0, seconds=0):
        self.hr = hours
        self.min = minutes
        self.sec = seconds
        self.normalise()

    def normalise(self):
        self.min += self.sec // 60
        self.sec %= 60
        self.hr += self.min // 60
        self.min %= 60

    def add(self, other):
        return Time(self.hr + other.hr, self.min + other.min, self.sec + other.sec)

    def __str__(self):
        return f"{self.hr} hours, {self.min} minutes, {self.sec} seconds"


time1 = Time(7, 53, 45)
time2 = Time(3, 63, 45)

time3 = time1.add(time2)

print(time3)
