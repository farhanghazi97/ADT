if __name__ == "__main__":
	exp = input("Enter bracket expression: ")
	bracket_set = {}
	valid_brackets = {'[' : ']', '{' : '}', '(' : ')'}
	for b in exp:
		if b not in bracket_set:
			bracket_set[b] = 1
		else:
			bracket_set[b] += 1
	valid = False
	for key , value in valid_brackets.items():
		try:
			if(bracket_set[key] == bracket_set[value]):
				valid = True
		except KeyError:
			pass
	print(valid)
