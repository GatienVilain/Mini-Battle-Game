CC = g++
CXX = g++

TARGET_EXEC ?= mini_battle_game.exe

BUILD_DIR ?= ./build
SRC_DIRS ?=

# ? Ce find ne semble pas fonctionner correctement.
# Il ne trouve que le fichier main.cpp mais fonctionne dans la console (manuellement)
# SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
# Solution de remplacement:
SRCS := ./src/personnages/heros/chevalier.cpp ./src/personnages/heros/clerc.cpp ./src/personnages/heros/creerHeros.cpp ./src/personnages/heros/hero.cpp ./src/personnages/heros/ninja.cpp ./src/personnages/monstres/monstre.cpp ./src/personnages/monstres/gererMonstres.cpp ./src/personnages/personnage.cpp ./src/console/afficherScene.cpp ./src/console/affichageCreerHeros.cpp ./main.cpp
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
