UNIT_TEST_DIR=unittests
SRC=.
BIN=$(UNIT_TEST_DIR)/bin
LDFLAGS+=-lgtest -lgtest_main
INCLUDES+=-I $(SRC)

UNIT_TESTS_SRC:= \
	$(UNIT_TEST_DIR)/unitBehaviour.cpp \
	$(UNIT_TEST_DIR)/damagesBehaviour.cpp \
	$(UNIT_TEST_DIR)/mapBehaviour.cpp \
	$(SRC)/unit.cpp \
	$(SRC)/damages.cpp \

UNIT_TESTS_OBJS:=$(UNIT_TESTS_SRC:%.cpp=$(BIN)/%.o)

$(BIN)/unit_tests: $(UNIT_TESTS_OBJS)
	$(Q)$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	@echo "LD $@"

clean:
	rm $(BIN) -rf
	rm common -rf

unit_tests: $(BIN)/unit_tests
	./$(BIN)/unit_tests

########### Compilation generic rules ############

$(BIN)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $< $(CFLAGS) -std=c++11 $(INCLUDES) $(LDFLAGS) -o $@ -c
	@echo "CXX $<"

