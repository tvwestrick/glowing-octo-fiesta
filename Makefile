CLANG=clang++
CPPFLAGSDEBUG=-Wall -Werror -g
BINDIR=bin
vpath %.cpp src
vpath %.h include
vpath %.hpp include
vpath %.o src

%.o : %.cpp
	@echo "Creating Objects from Source"
	$(CLANG) $(CPPFLAGSDEBUG) $< -c -o $@

equation_tests: equation_tests.o equation.o
	@echo "Creating Executable from Objects"
	$(CLANG) $(CPPFLAGSDEBUG) $^ -o $(BINDIR)/$@
	$(RM) equation_tests.o equation.o
