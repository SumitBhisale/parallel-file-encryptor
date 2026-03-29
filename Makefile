CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -I. -Isrc/app/encryptDecrypt -Isrc/app/filehanding -Isrc/app/processes

MAIN_TARGET = encrypt_decrypt
CRYPTION_TARGET = cryption

MAIN_SRC = main.cpp \
		   src/app/encryptDecrypt/Cryption.cpp \
		   src/app/filehandling/IO.cpp \
		   src/app/filehandling/ReadEnv.cpp \
		   src/app/processes/ProcessManagement.cpp

CRYPTION_SRC = src/app/encryptDecrypt/CryptionMain.cpp \
			   src/app/encryptDecrypt/Cryption.cpp \
		  	   src/app/filehandling/IO.cpp \
		   	   src/app/filehandling/ReadEnv.cpp 
			   	 
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
CRYPTION_OBJ = $(CRYPTION_SRC:.cpp=.o)

all: $(MAIN_TARGET) $(CRYPTION_TARGET) #multiple executables are built in one command (cmd> make)

$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(CRYPTION_TARGET): $(CRYPTION_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(CRYPTION_OBJ) $(MAIN_TARGET) $(CRYPTION_TARGET)

.PHONY: clean all