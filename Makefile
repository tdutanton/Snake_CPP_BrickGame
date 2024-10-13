SHELL = /bin/sh

CC = gcc -std=c11
CPPC = g++ -std=c++17
FLAGS = -Wall -Werror -Wextra
NCUR = -lncurses
LFLAGS = -lcheck -lm -lsubunit
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_FILE_NAME_T = test_tetris
TEST_FILE_NAME_S = test_snake
LIB_NAME_SNAKE = s21_snake.a
LIB_NAME_TETRIS = s21_tetris.a
GCOV_NAME_T = gcov_tests_tetris.info
GCOV_NAME_S = gcov_tests_snake.info
GAME_NAME = ./s21_brick_game
MAIN_FILE_CLI = ./brick_game/s21_brick_game_cli.c

LIB_SRC_C = $(wildcard brick_game/tetris/*.c)
LIB_SRC_S = $(wildcard brick_game/snake/*.cpp)
FRONT_SRC = $(wildcard gui/cli/*.c)
TEST_SRC = $(wildcard tests/*.c)
TEST_SRC_S = $(wildcard tests/*.cpp)

LIB_O_C = $(LIB_SRC_C:.c=.o)
LIB_O_CPP = $(LIB_SRC_S:.cpp=.o)
TEST_O = $(TEST_SRC:.c=.o)
TEST_O_CPP = $(TEST_SRC:.cpp=.o)

.PHONY: all install uninstall clean dvi dist tests test_tetris test_snake gcov_report clang_check clang_fix valgrind s21_tetris.a s21_snake.a valgrind dvi_install

all: clean install run

clean:
	@rm -f $(LIB_NAME_SNAKE) $(LIB_NAME_TETRIS) $(TEST_FILE_NAME)
	@rm -rf ./brick_game/tetris/*.o ./brick_game/snake/*.o ./tests/*.o *.gcno *.gcda ./report *.o ./*.a gui/desktop/*.o
	@rm -rf menu snake tetris
	@rm -rf $(TEST_FILE_NAME_T) $(TEST_FILE_NAME_S)
	@rm -rf html/
	@rm -rf latex/
	@rm -rf $(GAME_NAME).tgz
	@rm -rf $(GAME_NAME)
	@rm -rf gui/desktop/moc_* gui/desktop/Makefile.* gui/desktop/.qmake.* gui/desktop/ui_mainwindow.h
	@rm -rf report test
	@rm -rf gui/desktop/s21_snake_desktop gui/desktop/s21_tetris_desktop
	@rm -rf documentation

install: 
	@make tetris
	@make snake
	@$(CPPC) $(FLAGS) main_menu.cpp -o $(GAME_NAME)

run:
	@./$(GAME_NAME)

snake: s21_snake.a
	@$(CPPC) $(FLAGS) -DSNAKE $(MAIN_FILE_CLI) $(FRONT_SRC) -o snake -lsubunit -L. -l:$(LIB_NAME_SNAKE) $(NCUR)
	@cd gui/desktop && qmake DEFINES+=SNAKE && make clean && make
	@mv gui/desktop/s21_brickgame_desktop gui/desktop/s21_snake_desktop


tetris: s21_tetris.a
	@$(CC) $(FLAGS) -DTETRIS $(MAIN_FILE_CLI) $(FRONT_SRC) -o tetris -lsubunit -L. -l:$(LIB_NAME_TETRIS) $(NCUR)
	@cd gui/desktop && qmake DEFINES+=TETRIS && make clean && make
	@mv gui/desktop/s21_brickgame_desktop gui/desktop/s21_tetris_desktop

uninstall: clean
	-rm -rf $(GAME_NAME) snake_high_score.txt tetris_high_score.txt documentation

s21_snake.a: $(LIB_O_CPP)
	@ar rc $(LIB_NAME_SNAKE) $(LIB_O_CPP)
	@ranlib $(LIB_NAME_SNAKE)
	@rm -rf lib/*.o

s21_tetris.a: $(LIB_O_C)
	@ar rc $(LIB_NAME_TETRIS) $(LIB_O_C)
	@ranlib $(LIB_NAME_TETRIS)
	@rm -rf lib/*.o

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

%.o: %.cpp
	@$(CPPC) $(FLAGS) -c $< -o $@

tests: test_tetris test_snake

test_tetris: $(TEST_O) $(LIB_NAME_TETRIS)
	@echo "Testing Tetris"
	@$(CC) $(FLAGS) $(TEST_O) -o $(TEST_FILE_NAME_T) -L. -l:$(LIB_NAME_TETRIS) $(LFLAGS)
	@./$(TEST_FILE_NAME_T)

test_snake: $(TEST_O) $(LIB_NAME_SNAKE)
	@echo "Testing Snake"
	@$(CPPC) $(FLAGS) -DTEST $(LIB_SRC_S) $(TEST_SRC_S)  -o $(TEST_FILE_NAME_S) -lm -lpthread -lgtest -pthread -lstdc++
	@./$(TEST_FILE_NAME_S)

gcov_report: gcov_report_tetris gcov_report_snake

gcov_report_tetris: clean
	$(CC) $(FLAGS) -c $(LIB_SRC_C) --coverage
	$(CC) $(FLAGS) -c $(TEST_SRC) 
	$(CC) *.o -o $(TEST_FILE_NAME_T) $(LFLAGS) $(GCOV_FLAGS)
	./$(TEST_FILE_NAME_T)
	@lcov -t "gcov_tests" -o $(GCOV_NAME_T) -c -d .
	@genhtml -o report $(GCOV_NAME_T)
	@rm -rf *.o *.gcno *.gcda *.gcov $(GCOV_NAME_T)
	@rm -rf $(TEST_FILE_NAME_T)

gcov_report_snake: clean
	$(CPPC) $(FLAGS) -c $(LIB_SRC_S) --coverage
	$(CPPC) $(FLAGS) -c $(TEST_SRC_S) 
	$(CPPC) *.o -o $(TEST_FILE_NAME_S) -lgtest $(GCOV_FLAGS)
	./$(TEST_FILE_NAME_S)
	@lcov -t "gcov_tests" -o $(GCOV_NAME_S) -c -d . \
		--exclude '/usr/include/c++/11/*' \
		--exclude '/usr/include/c++/11/bits/*' \
		--exclude '/usr/include/c++/11/ext/*' \
		--exclude '/usr/include/gtest/*' \
		--exclude '/usr/include/gtest/internal/*'
	@genhtml -o report $(GCOV_NAME_S)
	@rm -rf *.gcno *.gcda *.gcov $(GCOV_NAME_S) *.o
	@rm -rf $(TEST_FILE_NAME_S)

valgrind: tests
	-valgrind --tool=memcheck --leak-check=yes ./test_tetris
	-valgrind --tool=memcheck --leak-check=yes ./test_snake

clang_check:    
	@cp ../materials/linters/.clang-format .clang-format
	find . -name '*.c' -exec clang-format -n {} \;
	find . -name '*.cpp' -exec clang-format -n {} \;
	find . -name '*.h' -exec clang-format -n {} \;
	@rm -rf .clang-format

clang_fix:
	@cp ../materials/linters/.clang-format .clang-format
	find . -name '*.c' -exec clang-format -i {} \;
	find . -name '*.cpp' -exec clang-format -i {} \;
	find . -name '*.h' -exec clang-format -i {} \;
	@rm -rf .clang-format

dist: uninstall install
	mkdir -p BrickGame_v2.0/gui/desktop
	cp $(GAME_NAME) BrickGame_v2.0/
	cp -R gui/desktop/s21_snake_desktop BrickGame_v2.0/gui/desktop/
	cp -R gui/desktop/s21_tetris_desktop BrickGame_v2.0/gui/desktop/
	cp snake BrickGame_v2.0/
	cp tetris BrickGame_v2.0/
	tar cvzf BrickGame_v2.0.tgz BrickGame_v2.0/
	rm -rf BrickGame_v2.0/

dvi:
	@mkdir documentation
	@doxygen Doxyfile
	@cd latex && xelatex refman.tex && cd ../

dvi_install:
	sudo apt-get install texlive-xetex
	sudo apt-get install texlive-lang-cyrillic