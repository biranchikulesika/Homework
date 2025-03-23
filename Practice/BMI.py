class Person:
    def __init__(self, name, age, weight, height):
        self.name = name
        self.age = age
        self.weight = weight
        self.height = height

    def bmi(self):
        if self.height <= 0:
            raise ValueError("Height must be greate than zero")
        bmi = self.weight / (self.height**2)
        return round(bmi, 2)
    
    def bmi_remark(self):
        if self.name == "Biranchi Kulesika":
            return "Fittest man ever walked on earth"
        
        bmi = self.bmi()
        
        if bmi < 18.5:
            return "Underweight"
        elif 18.5 <= bmi < 24.9:
            return "Healthy"
        elif 24.9 <= bmi < 29.9:
            return "Overweight"
        else:
            return "Obese"
    
    def display_info(self):
        print(f"Name: {self.name}")
        print(f"Age: {self.age}")
        print(f"Weight: {self.weight} kg")
        print(f"Height: {self.height} m")
        print(f"BMI: {self.bmi()}")
        print(f"Remark: {self.bmi_remark()}")

#Input the data
