SOURCE_DIR:= .
BIN:=$(SOURCE_DIR)/bin
OBJECT_DIR:=$(BIN)
SOURCES:=$(wildcard $(SOURCE_DIR)/*.c)
OBJECT_FILES:=$(patsubst %.c, %.o, $(SOURCES))
OBJECTS=$(addprefix $(OBJECT_DIR)/,$(OBJECT_FILES))
#or you could do both steps above within a single assignment
#OBJECTS:=$(addprefix $(OBJECT_DIR)/,$(patsubst %.c, %.o, $(SOURCES)))
all: $(SOURCES) $(OBJECTS)
		
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	mkdir -p $(OBJECT_DIR)
	gcc -g -std=c99 -o $@ $<

clean:
	rm -rf $(OBJECT_DIR)/*.o
	rm -rf $(OBJECT_DIR)
