from DoublyLinkedList import DoublyLinkedList


def main():
    dl_list = DoublyLinkedList()
    dl_list.addHead(4)
    dl_list.addAfter(4, 5)
    dl_list.addAfter(5, 6)
    dl_list.addBefore(4, 3)
    dl_list.addHead(2)
    dl_list.addTail(7)
    dl_list.addAfter(7, 8)
    dl_list.addBefore(2, 1)
    dl_list.addHead(0)
    dl_list.addTail(9)

    dl_list.printListForward()
    dl_list.printListReverse()
    dl_list.printHeadTail()

    dl_list.removeHead()
    dl_list.printListDetails()

    dl_list.removeTail()
    dl_list.printListDetails()

    dl_list.removeNode(1)
    dl_list.printListDetails()

    dl_list.removeNode(8)
    dl_list.printListDetails()

    dl_list.removeNode(5)
    dl_list.printListDetails()


if __name__ == '__main__':
    main()
