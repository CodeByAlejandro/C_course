# Get list of all project directories in this workspace directory
PROJECTS = $(shell find . -mindepth 2 -maxdepth 2 -type f -name Makefile | xargs dirname)

# Remove optional forward slash at the end of the PRJ command line variable
override PRJ := $(PRJ:%/=%)

# Define template for rule commands for build target
# This template will be reused for each project when no project is defined on the command line (PRJ variable)
# Note the newline at the end of the block is necessary because the '$(foreach ...)'-function only uses space separators
define BUILD_TEMPLATE
$(MAKE) -C $(PROJECT) $(MAKEFLAGS)
@echo

endef

# Define template for rule commands for clean target
# This template will be reused for each project when no project is defined on the command line (PRJ variable)
# Note the newline at the end of the block is necessary because the '$(foreach ...)'-function only uses space separators
define CLEAN_TEMPLATE
$(MAKE) -C $(PROJECT) clean
@echo

endef

# Define template for rule commands for update_makefile target
# This template will be reused for each project when no project is defined on the command line (PRJ variable)
# Note the newline at the end of the block is necessary because the '$(foreach ...)'-function only uses space separators
define UPDATE_MAKEFILE_TEMPLATE
cp ./template.mk ./$(PROJECT)/Makefile
sed -i 's/%final_program%/$(PROJECT)/g' ./$(PROJECT)/Makefile
@echo

endef

# Specifies rule for default 'build' target to build one or all projects
# Pass PRJ=SomeProject on the command line to set the project to build
build:
ifdef PRJ
	$(MAKE) -C $(PRJ) $(MAKEFLAGS)
else
	@echo Building all projects:
	@echo ----------------------
	$(foreach PROJECT,$(PROJECTS),$(BUILD_TEMPLATE))
endif

# Specifies rule for 'clean' target to clean one or all projects
# Pass PRJ=SomeProject on the command line to set the project to clean
clean:
ifdef PRJ
	$(MAKE) -C $(PRJ) clean
else
	@echo Cleaning all projects:
	@echo ----------------------
	$(foreach PROJECT,$(PROJECTS),$(CLEAN_TEMPLATE))
endif

# Specifies rule for 'create' target to create a new project from template
# Pass PRJ=SomeProject on the command line to set the project to create
# Note that the PRJ variable is required for this rule
create:
ifdef PRJ
	mkdir -p ./$(PRJ)/src && mkdir ./$(PRJ)/include
	cp ./template.mk ./$(PRJ)/Makefile
	sed -i 's/%final_program%/$(PRJ)/g' ./$(PRJ)/Makefile
else
	$(error PRJ variable is required on command line e.g. 'make create PRJ=SomeProject'!)
endif

# Specifies rule for 'update_makefile' target to update the makefile in a project
# Pass PRJ=SomeProject on the command line to set the project to update the Makefile for
# The current version of the template 'template.mk' will be used for updating the Makefile
# %..% variables will be replaced in the template
update_makefile:
ifdef PRJ
	cp ./template.mk ./$(PRJ)/Makefile
	sed -i 's/%final_program%/$(PRJ)/g' ./$(PRJ)/Makefile
else
	@echo Updating Makefile for all projects:
	@echo -----------------------------------
	$(foreach PROJECT,$(PROJECTS),$(UPDATE_MAKEFILE_TEMPLATE))

endif
