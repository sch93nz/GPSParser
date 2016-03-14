class degree:
	Time = 00.00
	X = 00.00
	Y = 00.00
	Z = 00.00

class output:
	time = 00.00
	X = 00.00
	Y = 00.00
	Z = 00.00
	
file = 0

degr = []
data = [] 
def main():
	global file
	file = open("D3431.TXT")
	load()
	print "output"
	print degr
	print data
	
	
	
def load ():
	for line in file:
		if "degress" in line:
	#deal with degree
			dealDegree(line)
		else :
			dealData(line)
	
	

def dealData(str):
	points = str.split(",")
	print points
	if len(points)>2:
		p = output
		p.time =points[0]
		p.X=points[1]
		p.Y=points[2]
		p.Z=points[3]
		data.append(p)
	else :
		print "nothing"
	
def dealDegree(str):
	points = str.split(",")
	print points
	if len(points)>2:
		p = degree
		p.time =points[0]
		p.X=points[1]
		p.Y=points[2]
		p.Z=points[3]
		degr.append(p)
	else :
		print "nothing"

		
main()