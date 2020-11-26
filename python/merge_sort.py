from random import randint

class MergeSortAlgorithm:

	def __init__(self):
		self.nums = []
		self.size = int(input("How many numbers do you want in your list ?\n"))
		for i in range(0, self.size):
			self.nums.append(randint(0, 1000))

	def showArray(self):
		print(self.nums)

	def mergeSort(self, arr=None):
		
		if arr is None:
			arr = self.nums

		if len(arr) > 1:
			
			mid = len(arr) // 2 
			L = arr[:mid] 
			R = arr[mid:] 

			self.mergeSort(L)
			self.mergeSort(R)

			i = j = k = 0
	         
	        # Copy data to temp arrays L[] and R[]
			while i < len(L) and j < len(R):
			    if L[i] < R[j]:
			        arr[k] = L[i]
			        i += 1
			    else:
			        arr[k] = R[j]
			        j += 1
			    k += 1
			 
			# Checking if any element was left
			while i < len(L):
			    arr[k] = L[i]
			    i += 1
			    k += 1
			 
			while j < len(R):
			    arr[k] = R[j]
			    j += 1
			    k += 1


if __name__ == "__main__":

	MSA = MergeSortAlgorithm()
	MSA.mergeSort()
	MSA.showArray()
	


