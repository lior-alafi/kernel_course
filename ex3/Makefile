obj-m := ex3a.o #expose 1 func
obj-m += ex3b.o 
obj-m += ex3c.o 

all:
	make -C /lib/modules/`uname -r`/build M=${PWD} modules
clean:
	make -C /lib/modules/`uname -r`/build M=${PWD} clean