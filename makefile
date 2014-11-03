
MAIN_FRONT = $(patsubst $(FRONT_CPP), $(FRONT_OBJ), $(FRONT_CPP))
MAIN_BACK   = $(patsubst $(BACK_CPP), $(BACK_OBJ), $(BACK_CPP))

FRONT_CPP = $(addprefix $(FRONT_DIR), symbolTable.cpp semanticChecker.cpp auxillaryMethods.cpp CFG.cpp)
BACK_CPP  = $(addprefix $(BACK_DIR), codeGenerator.cpp codeGenEnv.cpp)
FRONT_OBJ = $(addprefix $(FRONT_DIR), symbolTable.o semanticChecker.o auxillaryMethods.o CFG.o)
BACK_OBJ  = $(addprefix $(BACK_DIR), codeGenerator.o codeGenEnv.o)
NODE_OBJ  = $(patsubst $(DIR_NODE)%.cpp, $(DIR_NODE)%.o, \
			$(wildcard $(DIR_NODE)*.cpp))
CGEN_NODE = $(patsubst $(DIR_CGEN)%.cpp, $(DIR_CGEN)%.o, \
			$(wildcard $(DIR_CGEN)*.cpp))


FRONT_DIR = Front-End-Compiler/
DIR_NODE  = Front-End-Compiler/Nodes/
BACK_DIR  = Back-End-Compiler/
DIR_CGEN  = Back-End-Compiler/CodeGenNodes/


compile: $(MAIN_FRONT) $(MAIN_BACK) $(NODE_OBJ) $(CGEN_NODE) $(FRONT_DIR)lexer.cpp $(FRONT_DIR)parser.cpp main.cpp
	g++ $^ -lfl -o  compile  

Front-End-Compiler/parser.cpp: $(FRONT_DIR)parser.y 
	bison -d -o $(FRONT_DIR)parser.cpp $(FRONT_DIR)parser.y

Front-End-Compiler/lexer.cpp: $(FRONT_DIR)lexer.l 
	flex -o $(FRONT_DIR)lexer.cpp $(FRONT_DIR)lexer.l

clean:
	 rm -f $(addprefix $(DIR_NODE), *.o)
	 rm -f $(addprefix $(DIR_CGEN), *.o)
	 rm -f $(addprefix $(FRONT_DIR), *.o)
	 rm -f $(addprefix $(BACK_DIR), *.o)
	 rm -f *.o
	 rm -f $(addprefix $(DIR_NODE), *~)
	 rm -f $(addprefix $(DIR_CGEN), *~)
	 rm -f $(addprefix $(FRONT_DIR), *~)
	 rm -f $(addprefix $(BACK_DIR), *~)
	 rm -f *~
	 rm -f *.asm

