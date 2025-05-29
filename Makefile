# Set template file for project makefiles
TEMPLATE_MF := ./.templates/template-makefile.mk

# Set template file for standard C header file
TEMPLATE_MAIN_H := ./.templates/template-main.h
# Set template file for standard C source file
TEMPLATE_MAIN_C := ./.templates/template-main.c

# Set template for VS Code configuration files
TEMPLATE_VSCODE_CONFIG := ./.templates/template-vscode/*

# Get list of all project directories in this workspace directory
PROJECTS := $(shell find . -mindepth 2 -maxdepth 2 -type f -name Makefile -printf "%P\n" | xargs dirname)

# Remove optional forward slash at the end of the PRJ command line variable
override PRJ := $(PRJ:%/=%)

# Set debug argument for calling make in sub-directories if it was passed to this level
ifdef DEBUG
DEBUG_ARG := DEBUG=1
else
DEBUG_ARG :=
endif

# Define template for rule commands for build target
# This template will be reused for each project when no project is defined on the command line (PRJ variable)
# Note the newline at the end of the block is necessary because the '$(foreach ...)'-function only uses space separators
define BUILD_TEMPLATE
$(MAKE) -C $(PROJECT) $(DEBUG_ARG)
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
cp ./.templates/template-makefile.mk ./$(PROJECT)/Makefile
sed -i 's/%final_program%/$(PROJECT)/g' ./$(PROJECT)/Makefile
@echo

endef

# Define template for rule commands for update_vscode_config target
# This template will be reused for each project when no project is defined on the command line (PRJ variable)
# Note the newline at the end of the block is necessary because the '$(foreach ...)'-function only uses space separators
define UPDATE_VSCODE_CONFIG_TEMPLATE
mkdir -p ./$(PROJECT)/.vscode
cp -r ./.templates/template-vscode/* ./$(PROJECT)/.vscode
@echo

endef

# Specifies rule for default 'build' target to build one or all projects
# Pass PRJ=SomeProject on the command line to set the project to build
.PHONY: build
build:
ifdef PRJ
	$(MAKE) -C $(PRJ) $(DEBUG_ARG)
else
	@echo Building all projects:
	@echo ----------------------
	$(foreach PROJECT,$(PROJECTS),$(BUILD_TEMPLATE))
endif

# Specifies rule for 'clean' target to clean one or all projects
# Pass PRJ=SomeProject on the command line to set the project to clean
.PHONY: clean
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
.PHONY: create
create:
ifdef PRJ
	mkdir -p ./$(PRJ)/src && mkdir -p ./$(PRJ)/include && mkdir -p ./$(PRJ)/.vscode
	cp $(TEMPLATE_MF) ./$(PRJ)/Makefile
	sed -i 's/%final_program%/$(PRJ)/g' ./$(PRJ)/Makefile
	cp -r $(TEMPLATE_VSCODE_CONFIG) ./$(PRJ)/.vscode
	cp $(TEMPLATE_MAIN_H) ./$(PRJ)/include/main.h
	cp $(TEMPLATE_MAIN_C) ./$(PRJ)/src/main.c
	./.vscode-workspace/generate_workspace_projects.sh
else
	$(error PRJ variable is required on command line e.g. 'make create PRJ=SomeProject'!)
endif

# Specifies rule for 'update_makefile' target to update the makefile in a project
# Pass PRJ=SomeProject on the command line to set the project to update the Makefile for
# The current version of the template will be used for updating the Makefile
# %..% variables will be replaced in the template
.PHONY: update_makefile
update_makefile:
ifdef PRJ
	cp $(TEMPLATE_MF) ./$(PRJ)/Makefile
	sed -i 's/%final_program%/$(PRJ)/g' ./$(PRJ)/Makefile
else
	@echo Updating Makefile for all projects:
	@echo -----------------------------------
	$(foreach PROJECT,$(PROJECTS),$(UPDATE_MAKEFILE_TEMPLATE))
endif

# Specifies rule for 'update_vscode_config' target to update the VS Code configuration files in a project
# Pass PRJ=SomeProject on the command line to set the project to update the VS Code configuration files for
# The current version of the template directory will be used for updating the VS Code configuration files
.PHONY: update_vscode_config
update_vscode_config:
ifdef PRJ
	mkdir -p ./$(PRJ)/.vscode
	cp -r $(TEMPLATE_VSCODE_CONFIG) ./$(PRJ)/.vscode
else
	@echo Updating VS Code configuration files for all projects:
	@echo ------------------------------------------------------
	$(foreach PROJECT,$(PROJECTS),$(UPDATE_VSCODE_CONFIG_TEMPLATE))
endif

# Specifies rule for 'delete' target to delete an existing project
# Pass PRJ=SomeProject on the command line to set the project to delete
# Note that the PRJ variable is required for this rule
.PHONY: delete
delete:
ifdef PRJ
	rm -rf ./$(PRJ)/
	./.vscode-workspace/generate_workspace_projects.sh
else
	$(error PRJ variable is required on command line e.g. 'make delete PRJ=SomeProject'!)
endif
