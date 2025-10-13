from cs50 import get_float

while True:
	dollars = get_float("Change owed (in dollars): ")
	if dollars >= 0: break

x = round(dollars * 100) # Convert dollars to cents
n = 0 # Number of coins
y = x # Change owed

while y >= 25:
	y -= 25
	n += 1

while y >= 10 and y < 25:
	y -= 10
	n += 1

while y >= 5 and y < 10:
	y -= 5
	n += 1

while y >= 1 and y < 5:
	y -= 1
	n += 1

print(n)