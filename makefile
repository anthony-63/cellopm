OUT = cello

ifeq ($(OS),Windows_NT)
    OUT_BIN := $(OUT).exe
else
    OUT_BIN := $(OUT)
endif

SRC = src/*.c

$(OUT_BIN): $(SRC)
	gcc $(SRC) -o $(OUT_BIN)