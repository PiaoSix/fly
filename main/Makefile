out_dir = $(out_path)/main
obj := main.o
CFLAGS += -I$(srctree)/board/include -I$(srctree)/game/include

include $(srctree)/board/Makefile.rules
#out_obj = $(foreach n, $(obj), $(out_dir)/$(n))
#depends = $(patsubst $(out_dir)/%.o, $(out_dir)/%.d, $(out_obj))
#
#all:$(sub_target)
#
#$(sub_target): $(out_obj)
#	$(LD) -r -o $(out_dir)/$@ $^
#$(out_dir)/%.o: %.c
#	$(CC) $(CFLAGS) -c -o $@ $<
#include $(depends)
#
#$(out_dir)/%.d: %.c 
#	set -e; rm -f $@; 
#	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
#	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
#	rm -f $@.$$$$
#
#.PHONY: all




