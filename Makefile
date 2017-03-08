CC=g++
CFLAGS=-c -static
LDFLAGS= -static
SOURCES= main.C Menu.C Input.C boolNode.C Interpreter.C Context.C Constant.C BooleanExpression.C Variable.C OR.C AND.C NOT.C NAND.C EQUIV.C XOR.C NOR.C View.C
OBJECTS=$(SOURCES:.C=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.C.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	-rm -f *.o *~ $(TARGET)
	
