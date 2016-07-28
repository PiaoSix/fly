
obj = life_game.o 



$(sub_target):$(obj)
	$(CC) -c -o $@ $(CFLAGS) $(^:.o=.c)

include $(obj:.o=.d)

%.d: %.c 
	set -e; rm -f $@; 
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY:clean

clean:
	rm -f *.o *.d





