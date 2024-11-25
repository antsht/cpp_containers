ifeq ($(origin CXX), default)
	CXX=g++
endif
override CXXFLAGS+=-std=c++17 -Wall -Werror -Wextra -pedantic -g -I./
override LDFLAGS+=-lgtest
TEST_SOURCES=$(wildcard tests/s21_*.cc)
TEST_OBJECTS=$(TEST_SOURCES:.cc=.o)
S21_VALGRIND?=true
S21_SANITIZERS?=false
ifeq ($(S21_VALGRIND), true)
	override CXXFLAGS+=-g
endif
ifeq ($(S21_SANITIZERS), true)
  override S21_SANITIZERS_FLAGS=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
	override LDFLAGS+=$(S21_SANITIZERS_FLAGS)
	override CXXFLAGS+=-g $(S21_SANITIZERS_FLAGS)
endif

.PHONY: all
all: test

.PHONY: check
check:
	@cppcheck --enable=all --inline-suppr --suppress=missingIncludeSystem --suppress=noExplicitConstructor -I./ .
	@find . -type f \( -name "*.cc" -o -name "*.h" \) -exec echo "Checking {} with clang-format" \; -exec clang-format -i --style=Google {} \;
	@find . -type f \( -name "*.cc" -o -name "*.h" \) -exec echo "Checking {} with clang-format" \; -exec clang-format -n --style=Google {} \;

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(TEST_OBJECTS) $(LIBNAME) tests/tests tests/tests.info tests/*.gcda tests/*.gcno *.gcda *.gcno RESULT_VALGRIND.txt
	$(RM) -r report

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY:  test
test: $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(OBJECTS) $(TEST_OBJECTS) -o tests/tests $(LDFLAGS)
ifeq ($(S21_VALGRIND), true)
	valgrind -s --leak-check=full --trace-children=yes --track-origins=yes --log-file=RESULT_VALGRIND.txt tests/tests
else
	tests/tests
endif

.PHONY: gcov_report
gcov_report: override CXXFLAGS+=--coverage
gcov_report: override LDFLAGS+=-lsubunit -lgcov
gcov_report: test
	lcov --ignore-errors gcov,gcov --ignore-errors mismatch,mismatch -t "tests" -o tests/tests.info -c -d .
	lcov --remove tests/tests.info '/usr/include/*' '*/tests/*' -o tests/tests.info
	genhtml -o report tests/tests.info