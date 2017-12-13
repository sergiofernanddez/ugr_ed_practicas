SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g  -I$(INC) -c

	
# ************ Compilación de módulos ************
all: $(BIN)/union_cronologia $(BIN)/filtrado_intervalo $(BIN)/recuento_eventos $(BIN)/filtrado_palabra


$(BIN)/filtrado_palabra : $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o $(OBJ)/filtrado_palabra.o
	$(CXX) -o $(BIN)/filtrado_palabra $(OBJ)/FechaHistorica.o  $(OBJ)/Cronologia.o $(OBJ)/filtrado_palabra.o

$(BIN)/filtrado_intervalo : $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o $(OBJ)/filtrado_intervalo.o
	$(CXX) -o $(BIN)/filtrado_intervalo $(OBJ)/FechaHistorica.o  $(OBJ)/Cronologia.o $(OBJ)/filtrado_intervalo.o

$(BIN)/recuento_eventos : $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o $(OBJ)/recuento_eventos.o
	$(CXX) -o $(BIN)/recuento_eventos $(OBJ)/FechaHistorica.o  $(OBJ)/Cronologia.o $(OBJ)/recuento_eventos.o

$(BIN)/union_cronologia : $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o $(OBJ)/union_cronologia.o
	$(CXX) -o $(BIN)/union_cronologia $(OBJ)/FechaHistorica.o  $(OBJ)/Cronologia.o $(OBJ)/union_cronologia.o


$(OBJ)/filtrado_palabra.o : $(SRC)/filtrado_palabra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/filtrado_palabra.o $(SRC)/filtrado_palabra.cpp

$(OBJ)/recuento_eventos.o : $(SRC)/recuento_eventos.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/recuento_eventos.o $(SRC)/recuento_eventos.cpp

$(OBJ)/filtrado_intervalo.o : $(SRC)/filtrado_intervalo.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/filtrado_intervalo.o $(SRC)/filtrado_intervalo.cpp

$(OBJ)/union_cronologia.o : $(SRC)/union_cronologia.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/union_cronologia.o $(SRC)/union_cronologia.cpp

$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp 

$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/FechaHistorica.o $(SRC)/FechaHistorica.cpp


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
