class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def createList(self):
        while True:
            try:
                val = int(input("Enter number\n"))
                if(self.head is None):
                    self.head = self.tail = Node(val)
                else:
                    n = Node(val)
                    self.tail.next = n
                    self.tail = n
                self.size += 1
            except ValueError:
                print("Not a number! Please enter a valid number!")
            except EOFError:
                break

    def getListHead(self):
        return self.head.data

    def getListTail(self):
        return self.tail.data

    def printList(self):
        ptr = self.head
        while(ptr is not None):
            print("{0} -> ".format(ptr.data), end='')
            ptr = ptr.next
        print('X')

    def getListData(self):
        print("HEAD: {0}\nTAIL: {1}\nSIZE: {2}".format(
            self.head.data, self.tail.data, self.size))

    def sumList(self):
        ptr = self.head
        sum = 0
        while(ptr is not None):
            sum += ptr.data
            ptr = ptr.next
        return sum

    def insertBeforeIndex(self, index, val):
        curr_ptr = self.head
        newNode = Node(val)
        if(index == 1):
            newNode.next = self.head
            self.head = newNode
        elif(index == 0):
            print("Indexing starts from 1!")
        elif(index > self.size):
            print("Insert not possible!")
        elif(index < 0):
            print("Insert index can't be negative!")
        else:
            count = 1
            while(count < (index - 1)):
                count += 1
                curr_ptr = curr_ptr.next
            newNode.next = curr_ptr.next
            curr_ptr.next = newNode

    def mergeSortList(self, head=None):

        if head is None or head.next is None:
            return head

        temp = head
        slow = head
        fast = head

        while(fast is not None and fast.next is not None):
            temp = slow
            slow = slow.next
            fast = fast.next.next

        temp.next = None

        L = self.mergeSortList(head)
        R = self.mergeSortList(slow)
        return self.merge(L, R)

    def merge(self, L, R):

        sorted_temp = Node(0)
        current_node = sorted_temp

        while(L is not None and R is not None):
            if(L.data < R.data):
                current_node.next = L
                L = L.next
            else:
                current_node.next = R
                R = R.next
            current_node = current_node.next

        if(L is not None):
            current_node.next = L
            L = L.next

        if(R is not None):
            current_node.next = R
            R = R.next

        return sorted_temp.next


if __name__ == "__main__":

    LL = LinkedList()
    LL.createList()

    newLL = LL.mergeSortList(LL.head)
    temp = newLL
    while(temp.next is not None):
        print(temp.data)
        temp = temp.next
