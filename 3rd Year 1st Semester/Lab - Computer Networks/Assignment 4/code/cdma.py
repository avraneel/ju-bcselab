import os, math

os.system("rm *.txt")	# refreshing all files

class Station: # Class for denoting every station
	
	def __init__(self, stn_num, num_data, cdma_code, frames):
		self.stn_num=stn_num
		self.num_data=num_data
		self.cdma_code=cdma_code
		self.frames=frames

	# Send data corresponding to index of frame list
	def sendData(self,index):

		if(self.frames[index]=='-'): # Meaning idle
			data=0
		elif(self.frames[index]=='0'):
			data=-1
		else:
			data=1

		codeword=[data*self.cdma_code[i] for i in range(len(self.cdma_code))]
		print("[SENDING] Station {}:\t{}".format(self.stn_num,"\t".join(map(str, codeword))))
		return codeword

# Function to create walsh tables
def createWalsh(r):
	global walsh
	walsh=[[int(bin(x&y),13)%2 or -1 for x in range(r)]for y in range(r)]

# Decode dataword for every station
def decode_cdma(codeword, num_stn, max_num_stn):
	for i in range(num_stn):
		data=[codeword[j]*walsh[i][j] for j in range(len(walsh[i]))]
		data=sum(data)
		data=int(data/max_num_stn)
		with open("station_{}.txt".format(chr(65+i)), 'a') as opfile:	# Writing decoded output in station			
			if(data==-1):
				data=0
				opfile.write(str(data))
			elif(data==0):
				opfile.write("-")
			else:
				opfile.write(str(data))

def start():
	num_stn = int(input('Enter number of stations:\t'))
	x = num_stn
	if x&(x-1) != 0 and x != 0:
		print("Number must be power of 2.")
		exit()

	num_data = int(input('Enter the length of the message:\t'))
 
	createWalsh(num_stn)
	with open("walsh.txt", 'w') as opfile:
		for x in walsh:
			print(*x, sep='\t',file=opfile)

	stns=[]

	for i in range(num_stn):
		frames = input('Station {} | Enter the required string of length {}:\t'.format(i,num_data))
		frames=list(frames)

		# Creating station object
		tempstn=Station(chr(65+i),num_data,walsh[i],frames)
		stns.append(tempstn)
  
	print("\nTransmitting")
	for i in range(num_stn):
		frames=num_data*'_'
		frames=list(frames)
		tempstn=Station(i,num_data,walsh[i],frames)
		stns.append(tempstn)


	# Send data for every data
	for i in range(num_data):
		code=[0 for i in range(num_stn)]
		# Send for every station
		for j in range(num_stn):
			code = [x+y for x,y in zip(code, stns[j].sendData(i))]
		print("SENT BIT {}\n".format(1+i))
		with open("channel.txt", 'a') as opfile:
			print("\t".join(map(str,code)),file=opfile)		# prints the message passed through the channel

		decode_cdma(code,num_stn,num_stn)

walsh=[]
start()
print("\nTransmission Complete")