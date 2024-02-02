BIN:=tuya_switch_comm
LDFLAGS:=-llink_core\
-lmiddleware_implementation\
-lplatform_port\
-lutils_modules\
-largp\
-lubus\
-lubox
# -lblobmsg


CPPFLAGS:=-I$(CURDIR)
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(BIN) $(OBJS)
