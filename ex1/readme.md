To Build Modules:

	make -C /lib/modules/`uname -r`/build M=${PWD} modules

To clean:

	make -C /lib/modules/`uname -r`/build M=${PWD} clean