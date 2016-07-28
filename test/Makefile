

target = a.out
obj = main.o
CC = gcc

dir = $(shell pwd)
head = -I$(dir)/include1 -I$(dir)/include2

CFLAGS = $(head)

#test:
#	@echo $(head)

all:$(target)

$(target):$(obj)
	$(CC) $^ -o $@


include $(obj:.o=.d)

%.d: %.c
	set -e; rm -f $@; 
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


.PHONY:clean

clean:
	rm -f  $(target) $(obj:.o=.d) $(obj)


