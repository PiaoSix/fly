export sub_target = build-in.o
export srctree = $(shell pwd)
export head_flag :=
export CFLAGS := -std=c99
export LD = ld
export CC = gcc
export out_tree := $(shell pwd)/out
export srctree = $(shell pwd)
export cut_line = -------------
target := a.out
out_dir = $(out_tree)

sub_dir += board
sub_dir += game
sub_dir += main
#a:
#	echo $(out_tree)

BUILDDIR = $(out_dir) $(foreach n, $(sub_dir), $(out_dir)/$(n))


all:$(BUILDDIR) $(sub_dir) $(target)

$(target):
	$(CC) $(CFLAGS) $(foreach n, $(sub_dir), $(out_dir)/$(n)/$(sub_target)) -o $(out_dir)/$@

$(sub_dir):
	@echo $(cut_line)$(cut_line) 开始子makefile $(cut_line)$(cut_line)
	make -C $@

$(BUILDDIR):
	mkdir -p $@

.PHONY:$(sub_dir) $(target) clean

clean:
	rm -rf out test


