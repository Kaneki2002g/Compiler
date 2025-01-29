# Nazwa pliku wykonywalnego
TARGET = compilero

# Kompilator i flagi
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Pliki źródłowe
LEXER_SRC = lexic.l
PARSER_SRC = grammar.y
MAIN_SRC = main.cpp
LOGIC_SRC = brainpart.cpp

# Pliki wygenerowane
LEXER_CPP = lexic.cpp
PARSER_CPP = grammar.cpp
PARSER_HPP = grammar.hpp
LOG = log.txt

# Obiekty do kompilacji
OBJECTS = $(LEXER_CPP:.cpp=.o) $(PARSER_CPP:.cpp=.o) main.o brainpart.o

# Reguła domyślna
all: $(TARGET)

# Reguła budowy pliku wykonywalnego
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generowanie plików lexer.cpp i parser.cpp
$(LEXER_CPP): $(LEXER_SRC) $(PARSER_HPP)
	flex -o $@ $<

$(PARSER_CPP) $(PARSER_HPP): $(PARSER_SRC)
	bison -o $(PARSER_CPP) -d $(PARSER_SRC)

# Kompilacja plików źródłowych na obiekty
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych
clean:
	rm -f $(LEXER_CPP) $(PARSER_CPP) $(PARSER_HPP) *.o $(TARGET) $(LOG)

.PHONY: all clean