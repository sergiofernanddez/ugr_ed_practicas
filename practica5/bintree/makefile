INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 
AR = ar rvs		
AR_MACOS = libtool -static -o  

$(BIN)/usobintree : $(SRC)/usobintree.cpp $(INCLUDE)/bintree.h $(INCLUDE)/bintree.hxx $(INCLUDE)/node.hxx
	g++  -o $(BIN)/usobintree -I$(INCLUDE) $(SRC)/usobintree.cpp 

#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*


