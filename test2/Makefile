

obj = aaa bbb ccc
add = include
sub_dir = hehe
all = a.out

all:$(sub_dir)
	echo $@ and $^

$(sub_dir): #
	@echo make -C
	$(MAKE) -C $@



