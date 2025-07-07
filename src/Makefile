CC = g++ -Wall -Werror -Wextra -std=c++17
OBJ = *.cpp
TEST = -lgtest
STAT = *.cpp

# Определение операционной системы
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    # Для Alpine и других Linux дистрибутивов
    det_OS = -lrt -lpthread -lm
    for_lcov = --ignore-errors mismatch
    OPEN_CMD = xdg-open || true
else ifeq ($(UNAME_S),Darwin)
    # Для macOS
    det_OS = -lpthread
    for_lcov = --ignore-errors inconsistent
    OPEN_CMD = open
endif

all: s21_matrix_oop.a gcov_report

test: clean
	$(CC) $(OBJ) -o test $(TEST) $(det_OS) --coverage

gcov_report: test
	./test
	lcov -t "result" -o res.info --no-external $(for_lcov) -c -d . 
	genhtml -o report res.info 
	$(OPEN_CMD) report/index.html

s21_matrix_oop.a: clean
	$(CC) $(STAT) -c
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a
	rm -rf *.o

clean:
	rm -rf *.gcno *.gcda test *.o *.a *.info report

check:
	clang-format -style=Google -n *.cpp *.h
	clang-format -style=Google -i *.cpp *.h
	cppcheck --enable=all --suppress=missingIncludeSystem --language=c++ --check-config *.cpp *.h

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

.PHONY: all test gcov_report s21_matrix_oop.a clean check valgrind