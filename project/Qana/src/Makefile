CC = g++
CFLAGS = -Wall -g -O2
export CC
export CFLAGS
RM = rm -f

CBaseData = CBaseData.o
CMonitorData = CMonitorData.o

OBJS = $(CBaseData) $(CMonitorData) $(Main)

all: $(OBJS)
	$(CC) main.cpp -o ven -L. -lvendat -I.

lib: $(OBJS)
	$(CC) $(LIBS) -shared -fPIC CBaseData.o CMonitorData.o -o libvendat.so

$(OBJS): %.o : %.cpp %.h
	$(CC) $(INCLUDES) -c $(CFLAGS) $< -o  $@

clean:
	$(RM) *.o
