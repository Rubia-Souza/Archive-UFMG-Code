import sys

class memoryAccessFileReader:

    def __init__(self, memoryAccessFilePath):
        
        self.memoryAccessFilePath = memoryAccessFilePath

    # reads the memory access file in 
    # hexadecimal and returns a list 
    # of memory accesses in decimal 
    def read(self):

        decMemoryAccess = []

        with open(self.memoryAccessFilePath, "r") as file:
            
            for line in file:
                
                # removes the \n from 
                # the end of the line
                hex = line.strip()

                dec = int(hex, 16)

                decMemoryAccess.append(dec)
            
        return decMemoryAccess



class Line:

    def __init__(self, index, tag):

        self.index = index
        self.tag = tag
        self.valid = 0


    # returns True if there is a hit 
    # and False if the tags don't match 
    # (that doesn't mean it's a miss)
    def doTagsMatch(self, tagThatIsBeingSearched):

        if self.valid and self.tag == tagThatIsBeingSearched:
            
            # hit
            return True
        
        else:
            
            # tags don't match
            return False


    # updates the tag of the line
    def update(self, newTag):

        self.tag = newTag
        self.valid = 1

    
    # example:
    # 002 1 0x00048D15
    def __str__(self):

        if not self.valid and self.tag == 0:

            return "{:03d}".format(self.index) + " " + str(self.valid)

        return "{:03d}".format(self.index) + " " + str(self.valid) + " " + "0x{:08X}".format(self.tag)
    


class Group:

    def __init__(self, index, lines):
            
        self.index = index
        self.lines = lines
        self.nextLineToBeReplaced = 0
    
    
    # if the block is found in the group,
    # returns True (indicating it was a hit), 
    # otherwise, it returns False (indicating 
    # it was a miss)
    def isHit(self, tag):

        for line in self.lines:

            # if the block is found
            # (hit) in the group
            if line.doTagsMatch(tag):

                return True
        
        return False
    

    def isBlockInGroup(self, tag):

        isHit = self.isHit(tag)

        # if the block is not
        # found in the group
        if not isHit:

            # replce the next line according to FIFO
            self.lines[self.nextLineToBeReplaced].update(tag)
            self.nextLineToBeReplaced = (self.nextLineToBeReplaced + 1) % len(self.lines)

        return isHit


    # example:
    # 000 1 0x00048D15
    # 001 1 0x0000000B
    def __str__(self):

        #string = "--- Group " + str(self.index) + " ----" + "\n"
        string = ""

        for i in range(len(self.lines)):

            if len(self.lines) - 1 == i:
                
                string += str(self.lines[i])

            else:

                string += str(self.lines[i]) + "\n"
        
        return string
    


class Cache:

    def __init__(self, cacheSize, lineSize, groupSize):

        self.cacheSize = cacheSize
        self.lineSize = lineSize
        self.groupSize = groupSize
        self.numLines = int(cacheSize // lineSize)
        self.numGroups = int(cacheSize // groupSize)
        self.numLinesPerGroup = int(self.numLines // self.numGroups)
        self.groups = []

        self.hits = 0
        self.misses = 0

        currentLineIndex = 0   
            
        for i in range(self.numGroups): # for each group

            lines = []

            for j in range(self.numLinesPerGroup): # for each line in the group

                lines.append(Line(currentLineIndex, 0))

                currentLineIndex += 1

            self.groups.append(Group(i, lines))

    
    # emulates the memory access
    # if the block is found in 
    # the cache,incremets hit, 
    # otherwise, increments miss
    def accessMemory(self, memoryAccess):

        # represents the group in the 
        # memory where the address is
        memoryGroupIndex = memoryAccess // self.groupSize

        # represents the group in the
        # cache where the group in the 
        # memory (where the address is) 
        # maps to
        cacheGroupIndex = memoryGroupIndex % self.numGroups
        tag = memoryAccess // self.lineSize

        if self.groups[cacheGroupIndex].isBlockInGroup(tag):

            self.hits += 1
        
        else:
                
            self.misses += 1

    
    # example:
    # =================
    # IDX V ** ADDR **
    # 000 1 0x00048D15
    # 001 1 0x0000000B
    # 002 1 0x0000000A
    # 003 0 
    def __str__(self):

        string = "================" + "\n"
        string += "IDX V ** ADDR **" + "\n"

        for i in range(len(self.groups)):

            if len(self.groups) - 1 == i:
                
                string += str(self.groups[i])
            
            else:
                
                string += str(self.groups[i]) + "\n"
        
        return string
    


if __name__ == "__main__":
    
    # checks if the number of arguments is correct
    # if not, prints the correct usage and exits
    if len(sys.argv) != 5:
        print("Use: python3 simulador.py <cache size (bytes)> <line size (bytes)> <number of lines per group> <path/to/memory/access/file>")
        exit(1)
    
    # reads the arguments
    cacheSize = int(sys.argv[1])
    lineSize = int(sys.argv[2])
    # sys.argv[3] --> lines per group
    groupSize = int(sys.argv[3]) * lineSize
    memoryAccessFilePath = sys.argv[4]

    if cacheSize % lineSize != 0:
        print("Cache size must be a multiple of line size")
        exit(1)
    
    if cacheSize % groupSize != 0:
        print("Cache size must be a multiple of group size")
        exit(1)
    
    if cacheSize < groupSize:
        print("Cache size must be at least as big as group size")
        exit(1)

    # reads the memory access file
    memoryAccessFile = memoryAccessFileReader(memoryAccessFilePath)
    decMemoryAccess = memoryAccessFile.read()

    cache = Cache(cacheSize, lineSize, groupSize)

    with open("output.txt", "w") as file:

        # simulates the memory access
        # address by address printing
        # the cache after each access
        for memoryAccess in decMemoryAccess:

            cache.accessMemory(memoryAccess)

            file.write(str(cache) + "\n")

        # writes the hit and miss 
        # results after the simulation
        file.write("\n")
        file.write("#hits: " + str(cache.hits) + "\n")
        file.write("#miss: " + str(cache.misses))

