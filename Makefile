#顶层Makefile文件

sub_dir:=
sub_dir+= src

all:
	for i in ${sub_dir}; do \
		make -C $$i ; \
	done
	
clean:
	for i in ${sub_dir}; do \
		make -C $$i  clean ; \
	done
	
.PHONY : all clean