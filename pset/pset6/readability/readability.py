from cs50 import get_string

s = get_string("Text: ")
numWords = numLetters = numSentences = 0

for c in s:
	if c.isalpha(): numLetters += 1
	if c == " ": numWords += 1
	if c in [".", "!", "?"]: numSentences += 1
numWords += 1
L = float(float(numLetters / numWords) * 100)
S = float(float(numSentences / numWords) * 100)
index = int(round(0.0588 * L - 0.296 * S - 15.8))
if index < 1: print("Before Grade 1")
elif index >= 16: print("Grade 16+")
else: print(f"Grade {index}")