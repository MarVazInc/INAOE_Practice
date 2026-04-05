class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Create two nodes
head = Node("First")
second = Node("Second")
head.next = second

print(f"Start of list: {head.data}")
print(f"Next item: {head.next.data}")
