RM := rm -f

CFLAGS = \
	-D_FORTIFY_SOURCE=2    \
	-D_POSIX_SOURCE=199506 \
	-Iinclude              \
	-O3                    \
	-Wall                  \
	-Wextra                \
	-Wformat=2             \
	-Wmissing-declarations \
	-Wmissing-include-dirs \
	-Wnull-dereference     \
	-Wpedantic             \
	-Wpointer-arith        \
	-Wstrict-overflow=5    \
	-g                     \
	-o$(@)                 \
	-std=c99

OBJS := \
	source/checkParams.o \
	source/copyright.o   \
	source/exit.o        \
	source/getSum.o      \
	source/help.o        \
	source/initData.o    \
	source/main.o        \
	source/open.o        \
	source/patch.o       \
	source/read.o

BIN := agbsum

$(BIN): $(OBJS)
	$(CC) -o$(BIN) $(OBJS)

$(OBJS): include/agbsum.h

.PHONY: clean install purge

clean:
	$(RM) $(OBJS)

purge: clean
	$(RM) $(BIN)

install: $(BIN)
	mkdir -pm755 "$(BINDIR)"
	install -m755 "agbsum" "$(BINDIR)"
