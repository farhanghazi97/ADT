
class LinkedList:

	def __init__(self, nodes=None):
		self.head = None
		self.tail = None
		if nodes is not None:
			node = Node(nodes.pop(0))
			self.head = node
			for elem in nodes:
				node.next = Node(data=elem)
				node = node.next
		self.tail = node

	def __repr__(self):
		curr_node = self.head
		nodes = []
		while curr_node is not None:
			nodes.append(curr_node.data)
			curr_node = curr_node.next
		nodes.append("None")
		return ' -> '.join(nodes)

	def prepend(self, node):
		node.next = self.head
		self.head = node

	def append(self, node):
		self.tail.next = node
		self.tail = node

class Node:

	def __init__(self, data):
		self.data = data
		self.next = None

	def __repr__(self):
		return self.data

if __name__ == "__main__":

	LL = LinkedList(["a", "b", "c", "d", "e"])
	print(LL)