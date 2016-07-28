#nullstring :=
export sub_target = build-in.o
export srctree = $(shell pwd)
export head_flag :=
export CFLAGS := 
export LD = ld

target := a.out

sub_dir += game
sub_dir += board

all:



.PHONY:clean $(sub_dir)

clean:
	rm -f $(target) *.o *.d
