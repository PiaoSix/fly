obj =
sub_dir = display


all:$(sub_target)

$(sub_target):$(sub_dir)
	$(LD) -r -o $@ $^

include $(obj:.o=.d)

%.d: %.c 
	set -e; rm -f $@; 
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(sub_dir):
	$(MAKE) -C $@

.PHONY:clean $(sub_dir)

clean:
	rm -f $(sub_target) $(obj) $(obj:.o=.d)





