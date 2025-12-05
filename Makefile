################################################################################
## Fichero «Makefile» para los programas de la práctica 4:
## «natrurales-grandes-test» (programa de prueba del módulo 
## «naturales-grandes»), «fibonacci», «primera-potencia», y «lychrel»
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS
SOURCE_DIR = src
TEST_DIR = test
EXAMPLE_DIR = example
TESTING_LIB_DIR = ../practica3/test/testing-prog1
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) $(TEST_DIR) $(TESTING_LIB_DIR) $(EXAMPLE_DIR)

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -Og -Wall -Wextra -I$(SOURCE_DIR) -I$(TESTING_LIB_DIR)


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
FACTORIAL_OBJECTS =  $(addprefix $(BUILD_DIR)/, factorial-main.o \
                                                naturales-grandes.o)

FIBONACCI_OBJECTS =  $(addprefix $(BUILD_DIR)/, fibonacci-main.o \
                                                naturales-grandes.o)

POTENCIA_OBJECTS =  $(addprefix $(BUILD_DIR)/, primera-potencia-main.o \
                                                naturales-grandes.o)

LYCHREL_OBJECTS =  $(addprefix $(BUILD_DIR)/, lychrel-main.o \
                                                naturales-grandes.o)

SUMA_NAT_GRANDES_OBJECTS =  $(addprefix $(BUILD_DIR)/, suma-nat-grandes.o \
                                                naturales-grandes.o)

TESTING_OBJECTS = $(addprefix $(BUILD_DIR)/, naturales-grandes-test-main.o \
        naturales-grandes-test.o testing-prog1.o naturales-grandes.o)

OBJECTS = $(FACTORIAL_OBJECTS) $(FIBONACCI_OBJECTS) $(POTENCIA_OBJECTS) \
          $(LYCHREL_OBJECTS) $(SUMA_NAT_GRANDES_OBJECTS) $(TESTING_OBJECTS)

################################################################################
## Reglas del fichero «Makefile»

factorial: $(FACTORIAL_OBJECTS) | $(BIN_DIR)
	$(CXX) -Og $(FACTORIAL_OBJECTS) -o $(BIN_DIR)/$@ 

fibonacci: $(FIBONACCI_OBJECTS) | $(BIN_DIR)
	$(CXX) -Og $(FIBONACCI_OBJECTS) -o $(BIN_DIR)/$@ 

primera-potencia: $(POTENCIA_OBJECTS) | $(BIN_DIR)
	$(CXX) -Og $(POTENCIA_OBJECTS) -o $(BIN_DIR)/$@ 

lychrel: $(LYCHREL_OBJECTS) | $(BIN_DIR)
	$(CXX) -Og $(LYCHREL_OBJECTS) -o $(BIN_DIR)/$@ 

naturales-grandes-test: $(TESTING_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TESTING_OBJECTS) -o $(BIN_DIR)/naturales-grandes-test

suma-unsigned: example/suma-unsigned.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) example/suma-unsigned.cpp -o $(BIN_DIR)/$@ 

suma-nat-grandes: $(SUMA_NAT_GRANDES_OBJECTS) | $(BIN_DIR)
	$(CXX) -Og $(SUMA_NAT_GRANDES_OBJECTS) -o $(BIN_DIR)/$@ 


$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(OBJECTS): naturales-grandes.hpp 
$(BUILD_DIR)/naturales-grandes-test-main.o: naturales-grandes-test.hpp 
$(BUILD_DIR)/naturales-grandes-test.o: testing-prog1.hpp naturales-grandes.hpp
$(BUILD_DIR)/testing-prog1.o: testing-prog1.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -f $(OBJECTS) $(BIN_DIR)/*
endif
