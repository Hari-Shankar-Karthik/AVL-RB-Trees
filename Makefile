OUTFILE=a.out
OBJS=main.o AVLTree.o RBTree.o TreeNode.o
CXXFLAGS=-Wall -std=c++20 -O3

all: $(OUTFILE)

$(OUTFILE): $(OBJS)
	g++ -o $(OUTFILE) $(OBJS)

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -rf $(OUTFILE) $(OBJS)