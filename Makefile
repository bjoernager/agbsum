RM := rm -f

CFLAGS = \
	-Iinclude              \
	-Wall                  \
	-Wextra                \
	-Wmissing-declarations \
	-Wpedantic             \
	-o$(@)                 \
	-std=c99

BIN := agbsum

OBJS := \
	src/chkpar.o \
	src/exi.o    \
	src/getsum.o \
	src/hlp.o    \
	src/inidat.o \
	src/main.o   \
	src/opn.o    \
	src/pat.o    \
	src/red.o

$(BIN): $(OBJS)
	$(CC) -o$(BIN) $(OBJS)

.PHONY: clean install purge

clean:
	$(RM) $(OBJS)

purge: clean
	$(RM) $(BIN)

install: $(BIN)
	mkdir -pm755 "$(BINDIR)"
	install -m755 "agbsum" "$(BINDIR)"
