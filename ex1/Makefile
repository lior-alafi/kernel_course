obj-m:=ex1.o
ex1-objs :=exr1.o func.o

#to create a dependency module u need to:
#========================
#1. take the .o files 
#2. specify a main o file under 'obj-m' e.g 'obj-m := ex1.o'
#3. add the dependencies to your <main>-objs like 'ex1-objs := exr1.o func1.o func2.o'


#to create multiple modules
#==========================
# obj-m := module1.o 
# obj-m += module2.o
all:
	make -C /lib/modules/`uname -r`/build M=${PWD} modules

clean:

	make -C /lib/modules/`uname -r`/build M=${PWD} clean