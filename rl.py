def read_feature():
	u1 = []
	u2 = []
	with open("features1", "r") as f:
	    u1 = f.readlines()
	with open("features2", "r") as f:
		u2 = f.readlines()
	for i in range(len(u1)):
		u1[i] = u1[i].strip("\n")
	for i in range(len(u2)):
		u2[i] = u2[i].strip("\n")
	x1 = u1[-1].split(" ")[-1]
	x2 = u2[-1].split(" ")[-1]
	# print(u1[-1])
	y1 = u1[-1].split(" ")[:-1]
	y2 = u2[-1].split(" ")[:-1]
	# print(y1)
	if(x1 == "10"):
		y1.append("-10")
		str = ""
		for i in y1:
			str+=i+" "
		str = str.strip(" ")
		# print(len(u2))
		u2.append(str)
	elif(x2 == "10"):
		y2.append("-10")
		str = ""
		for i in y2:
			str+=i+" "
		str = str.strip(" ")
		u1.append(str)
	return u1, u2

def td_leaf():
	w = []
	with open("weights", "r") as f:
		w = f.readlines()

	u1, u2 = read_feature()
	for i in range(len(u1)):
		u1[i] = [float(x) for x in u1[i].split(" ")]
	for i in range(len(u2)):
		u2[i] = [float(x) for x in u2[i].split(" ")]

	for i in range(len(w)):
		w[i] = float(w[i].strip('\n'))

	jacobin = []
	for i in range(len(u1)):
		z = 0.0
		for j in range(14):
			z += u1[i][j]*w[j]
		jacobin.append(z)

	d = []
	for i in range(len(jacobin) - 1):
		d.append(jacobin[i+1] - jacobin[i])

	d[-1] = u1[-1][-1] - jacobin[-2]
	# print(d)
	alpha = 0.01
	lam = 0.1
	w_temp = [x for x in w]
	for i in range(len(w)):
		for t in range(len(jacobin) - 1):
			for j in range(t, len(jacobin) - 1):
				w_temp[i] += alpha * u1[t][i] * (lam**(j-t)*d[t])
	
	with open("weights1", "w") as f:
		for i in w_temp:
			f.write(str(i))
			f.write("\n")

if __name__ == '__main__':
	# append_feature()
	td_leaf()