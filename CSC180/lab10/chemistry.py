class atom:
    def __init__(self,num):
        self.atomNum=num
        self.bondList=[]

    def addBond(self,bondStr,addAtom):
        self.bondList.append([bondStr,addAtom])
        newAtom=atom(addAtom)
        

    def printStructure(self):
        for 
