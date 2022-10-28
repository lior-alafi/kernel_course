obj-m := source.o
obj-m += destination.o


#allow debug messages:
#ccflags-y := DDEBUG
all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean