def add_times(hour1, minute1, second1, hour2, minute2, second2):
	# Add seconds, minutes, and hours
	total_seconds = second1 + second2
	total_minutes = minute1 + minute2 + (total_seconds // 60)
	total_hours = hour1 + hour2 + (total_minutes // 60)

	# Normalize time
	final_seconds = total_seconds % 60
	final_minutes = total_minutes % 60
	final_hours = total_hours

	return final_hours, final_minutes, final_seconds

# Input times
print("Enter first time:")
hour1 = int(input("Hours: "))
minute1 = int(input("Minutes: "))
second1 = int(input("Seconds: "))

print("Enter second time:")
hour2 = int(input("Hours: "))
minute2 = int(input("Minutes: "))
second2 = int(input("Seconds: "))

# Add times
result_hours, result_minutes, result_seconds = add_times(hour1, minute1, second1, hour2, minute2, second2)

# Display result
print(f"Total Time: {result_hours} hours, {result_minutes} minutes, {result_seconds} seconds")