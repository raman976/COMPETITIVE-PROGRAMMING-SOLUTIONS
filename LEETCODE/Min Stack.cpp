class MinStack:

    def __init__(self):
        self.elements=[]
        self.mins=[]

    def push(self, val: int) -> None:
        self.elements.append(val)
        if not self.mins:
            self.mins.append(val)
        else:
            self.mins.append(min(self.mins[-1],val))
    def pop(self) -> None:
        self.elements.pop()
        self.mins.pop()
    def top(self) -> int:
        return self.elements[-1]

    def getMin(self) -> int:
        return self.mins[-1]
        