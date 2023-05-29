RM := rm -f

CFLAGS = \
	-D_FORTIFY_SOURCE=2    \
	-D_GNU_SOURCE          \
	-Iinclude              \
	-O3                    \
	-Wall                  \
	-Wextra                \
	-Wmissing-declarations \
	-Wpedantic             \
	-g                     \
	-o$(@)                 \
	-std=c99

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

BIN := agbsum

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
