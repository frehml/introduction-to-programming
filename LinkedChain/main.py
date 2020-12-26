class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class LinkedChain:
    def __init__(self):
        self.first = None

    def isEmpty(self):
        return self.first is None

    def getLength(self):
        if self.first is None:
            return 0

        if self.first.next is None:
            return 1

        ele = self.first.next
        i = 0

        while ele != self.first:
            ele = ele.next
            i += 1

        return i

    def retrieve(self, idx):
        if idx - 1 > self.getLength():
            return [None, False]

        ele = self.first

        for i in range(idx):
            ele = ele.next

        return [ele.data, True]

    def get_node(self, index):
        current = self.first
        for i in range(index):
            current = current.next
            if current == self.first:
                return None
        return current

    def insert_after(self, ref_node, new_node):
        new_node.prev = ref_node
        new_node.next = ref_node.next
        new_node.next.prev = new_node
        ref_node.next = new_node

    def insert_at_end(self, new_node):
        if self.first is None:
            self.first = new_node
            new_node.next = new_node
            new_node.prev = new_node
        else:
            self.insert_after(self.first.prev, new_node)

    def insert_at_beg(self, new_node):
        self.insert_at_end(new_node)
        self.first = new_node

    def insert(self, idx, ele):
        if idx - 1 > self.getLength():
            return False

        new_node = Node(ele)
        ref_node = self.get_node(idx - 1)

        if idx == 1:
            self.insert_at_beg(new_node)
        elif idx == self.getLength() - 1:
            self.insert_at_end(new_node)
        else:
            self.insert_after(ref_node, new_node)

        return True

    def remove(self, node):
        if self.first.next == self.first:
            self.first = None
        else:
            node.prev.next = node.next
            node.next.prev = node.prev
            if self.first == node:
                self.first = node.next

    def delete(self, idx):
        if idx - 1 > self.getLength() or idx < 1:
            return False

        self.remove(self.get_node(idx))
        return True

    def save(self):
        array = [self.first.data]
        ele = self.first.next

        while ele != self.first:
            array.append(ele.data)
            ele = ele.next

        return array

    def load(self, chain):
        self.remove(self.first)
        num = 1
        for ele in chain:
            self.insert(num, ele)
            num += 1


l = LinkedChain()
print(l.isEmpty())
print(l.getLength())
print(l.retrieve(4)[1])
print(l.insert(4, 500))
print(l.isEmpty())
print(l.insert(1, 500))
print(l.retrieve(1)[0])
print(l.retrieve(1)[1])
print(l.save())
print(l.insert(1, 600))
print(l.save())
l.load([10, -9, 15])
l.insert(3, 20)
print(l.delete(0))
print(l.save())
print(l.delete(1))
print(l.save())