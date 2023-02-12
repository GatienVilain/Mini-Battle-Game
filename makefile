CC = g++
CXX = g++

# Windows
# TARGET_EXEC ?= mini_battle_game.exe
# Linux
TARGET_EXEC ?= mini_battle_game

BUILD_DIR ?= ./build
SRC_DIRS ?=

SRCS := ./main.cpp ./src/console/afficherScene.cpp ./src/personnages/monstres/monstre.cpp ./src/personnages/monstres/creerMonstres.cpp ./src/personnages/personnage.cpp ./src/personnages/heros/chevalier.cpp ./src/personnages/heros/clerc.cpp ./src/personnages/heros/hero.cpp ./src/personnages/heros/ninja.cpp ./src/personnages/heros/creerHeros.cpp
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d -not -path "./.*")
INC_FLAGS := $(addprefix -I ,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -Wall -MMD -MP

$(TARGET_EXEC): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(OBJS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

exec: $(TARGET_EXEC)
	./$(TARGET_EXEC)

reload: clean exec

clean:
	$(RM) -r $(BUILD_DIR)

clean-all:
	$(RM) -r $(BUILD_DIR) $(TARGET_EXEC)

-include $(DEPS)

MKDIR_P ?= mkdir -p
