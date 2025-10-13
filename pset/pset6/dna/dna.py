import csv
from sys import argv

def main():
	if len(argv) != 3: print("Usage: python dna.py data.csv sequence.txt")
	
	# Open files
	dbFile = open(f"./{argv[1]}")
	dnaFile = open(f"./{argv[2]}")

	# Obtain strs from header of file
	dbReader = csv.DictReader(dbFile)
	strs = dbReader.fieldnames[1:]
	
	dna = dnaFile.read()
	dnaFile.close()

	fingerprint = {}
	for str in strs: fingerprint[str] = consecRepeats(str, dna)
	for row in dbReader:
		if match(strs, fingerprint, row):
			print(f"{row['name']}")
			dbFile.close()
			return
	print("No match")
	dbFile.close()

def consecRepeats(str, dna):
	i = 0
	while str * (i + 1) in dna: i += 1
	return i

def match(strs, fingerprint, row):
	for str in strs:
		if fingerprint[str] != int(row[str]): return False
	return True

main()