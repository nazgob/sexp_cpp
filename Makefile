_OBJS = \
       Context.o \
       VarExp.o


_TST_OBJS = \
						test_main.o \
						ContextTest.o \
						OperatorTest.o \
						SExpTest.o

CC = clang++ -g

BIN_EXEC = sexp_cpp
LIB_EXEC = libsexp_cpp.so
TST_EXEC = test_sexp_cpp

BIN_DIR = bin/
SRC_DIR = src/
LIB_DIR = lib/
TST_DIR = tst/
OBJ_DIR = obj/
DOC_DIR = doc/

OBJS = $(patsubst %,$(OBJ_DIR)%,$(_OBJS))
TST_OBJS = $(patsubst %,$(TST_DIR)%,$(_TST_OBJS))
 
BOOST_DIR = /opt/local/var/macports/software/boost/1.44.0_0/opt/local/include
W_FLAGS = -Wall -Wextra #TODO: -pedantic couses problems with long long and google test
I_FLAGS = -I/opt/local/include -I$(BOOST_DIR)
L_FLAGS = -L/opt/local/lib -lgtest -L./$(LIB_DIR) -lsexp_cpp

FLAGS = $(W_FLAGS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	$(CC) $(I_FLAGS) $(FLAGS) -c $< -o $@

$(TST_DIR)%.o : $(TST_DIR)%.cpp
	$(CC) $(I_FLAGS) $(FLAGS) -c $< -o $@

main: $(OBJS)
	@echo "Building $(LIB_EXEC)"
	ar rcs $(LIB_DIR)$(LIB_EXEC) $(OBJS)

test: $(TST_OBJS) main
	@echo "Compiling tests!"
	$(CC) $(TST_OBJS) $(FLAGS) $(I_FLAGS) $(L_FLAGS) -o $(BIN_DIR)$(TST_EXEC)
	@echo "Executing test!"
	$(BIN_DIR)$(TST_EXEC)

docs:
	@echo "Making doxygen docs!"
	doxygen $(DOC_DIR)/Doxyfile

clean:
	@echo "Cleaning all!"
	\rm -rf $(OBJ_DIR)*.o $(TST_DIR)*.o $(BIN_DIR)* $(LIB_DIR)$(LIB_EXEC)

