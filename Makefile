PROJECTS = $(shell find . -mindepth 2 -maxdepth 2 -type f -name Makefile -print0 | xargs -0 dirname)

create:
ifdef PROJECT
	mkdir -p './$(PROJECT)/src' && mkdir './$(PROJECT)/include'
	cp ./template.mk './$(PROJECT)/Makefile'
	sed -i 's/%final_program%/$(PROJECT)/g' './$(PROJECT)/Makefile'
else
	$(error [ERROR] PROJECT variable is required on command line e.g. 'make create PROJECT=SomeProject'!)
endif

clean:
ifdef PROJECT
	cd '$(PROJECT)' && $(MAKE) clean
else
endif
