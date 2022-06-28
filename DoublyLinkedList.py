from Node import Node


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def addHead(self, newData):
        newNode = Node(newData)

        if self.head is None:
            self.head = newNode
        else:
            if self.head.next is None:
                self.tail = self.head

            newNode.next = self.head
            self.head = newNode
            newNode.next.prev = newNode

    def addBefore(self, beforeNumber, newData):
        if self.head is not None:
            curr = self.head

            while curr is not None:
                if curr.data == beforeNumber:
                    newNode = Node(newData)

                    if curr == self.head:
                        self.addHead(newData)
                    else:
                        curr.prev.next = newNode
                        newNode.prev = curr.prev
                        newNode.next = curr
                        curr.prev = newNode

                    break

                curr = curr.next

    def addAfter(self, afterNumber, newData):
        if self.head is not None:
            curr = self.head

            while curr is not None:
                if curr.data == afterNumber:
                    newNode = Node(newData)

                    if curr.next is None:
                        self.addTail(newData)
                    else:
                        curr.next.prev = newNode
                        newNode.prev = curr
                        newNode.next = curr.next
                        curr.next = newNode

                    break

                curr = curr.next

    def addTail(self, newData):
        if self.head is not None:
            newNode = Node(newData)

            if self.tail is not None:
                self.tail.next = newNode
                newNode.prev = self.tail
                self.tail = newNode
            else:
                self.head.next = newNode
                newNode.prev = self.head
                self.tail = newNode

    def removeHead(self):
        if self.head is not None:
            removeNode = self.head

            if self.tail is None:
                self.head = None
            else:
                self.head = self.head.next
                self.head.prev = None
                removeNode.next = None

    def removeNode(self, removeNumber):
        if self.head is not None:
            curr = self.head

            while curr is not None:
                if curr.data == removeNumber:
                    if curr == self.head:
                        self.removeHead()
                    elif curr == self.tail:
                        self.removeTail()
                    else:
                        curr.prev.next = curr.next
                        curr.next.prev = curr.prev
                        curr.prev = None
                        curr.next = None
                        break

                curr = curr.next

    def removeTail(self):
        if self.tail is not None:
            removeNode = self.tail

            if self.tail.prev == self.head:
                self.tail = None
                self.head.next = None
            else:
                self.tail = self.tail.prev
                self.tail.next = None
                removeNode.prev = None

    def printListForward(self):
        if self.head is not None:
            if self.tail is not None:
                curr = self.head

                print('\nnull <--- ', end='')

                while curr != self.tail:
                    if curr.next is None:
                        arrow = ' ---> '
                    else:
                        arrow = ' <---> '

                    print(str(curr.data) + arrow, end="")
                    curr = curr.next

                print(str(self.tail.data) + ' ---> null')
            else:
                print('\nnull <--- ' + str(self.head.data) + ' ---> null')

    def printListReverse(self):
        if self.head is not None:
            if self.tail is not None:
                curr = self.tail

                print('\nnull <--- ', end='')

                while curr != self.head:
                    if curr.prev is None:
                        arrow = ' ---> '
                    else:
                        arrow = ' <---> '

                    print(str(curr.data) + arrow, end='')
                    curr = curr.prev

                print(str(self.head.data) + ' ---> null')
            else:
                print('\nnull <--- ' + str(self.head.data) + ' ---> null')

    def printHeadTail(self):
        if self.head is None:
            head = 'null'
        else:
            head = str(self.head.data)

        if self.tail is None:
            tail = 'null'
        else:
            tail = str(self.tail.data)

        print('\n(' + head + ', ' + tail + ')')

    def printListDetails(self):
        self.printListForward()
        self.printListReverse()
        self.printHeadTail()
