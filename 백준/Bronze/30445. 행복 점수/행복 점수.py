str = input()

ph, pg = 0, 0
for c in str :
	if c in 'HAPPY' :
		ph += 1
	if c in 'SAD' :
		pg += 1

if ph + pg == 0 :
	print('50.00')
else :
	print('{:.2f}'.format(round(ph * 100 / (ph + pg), 2)))