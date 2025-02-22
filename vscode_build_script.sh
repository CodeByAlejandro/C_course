main() {
	local workspace_dir="$1"
	local curr_file="$2"
	shift 2

	# Remove ending forwardslash from workspace directory if there is one
	workspace_dir="$(echo "${workspace_dir}" | sed -E 's|(.*)/$|\1|')"

	validate_vscode_input "${workspace_dir}" "${curr_file}"
	[ $? -ne 0 ] && return 1
	
	local project_dir # declaration must be separate or local command will override exit status
	project_dir="$(determine_project_directory "${workspace_dir}" "${curr_file}")"
	[ $? -ne 0 ] && return 1

	print_header "Running 'make $@' in '${project_dir}'"
	cd "${project_dir}" && make "$@"
	[ $? -ne 0 ] && return 1
	echo

	# Create symlinks to active project and binary in '.vscode' directory for reference in launch.json
	local project_name="$(basename "${project_dir}")"
	local project_bin_file="${project_dir}/bin/${project_name}"
	print_header 'Creating symlinks for launch.json'
	echo "ln -sf '${project_dir}' '${workspace_dir}/.vscode/launch_project'"
	ln -sfn "${project_dir}" "${workspace_dir}/.vscode/launch_project" # -n flag for no-dereference prevents recursion
	[ $? -ne 0 ] && return 1
	echo "ln -sf '${project_bin_file}' '${workspace_dir}/.vscode/launch_binary'"
	ln -sf "${project_bin_file}" "${workspace_dir}/.vscode/launch_binary"
	[ $? -ne 0 ] && return 1
	echo
}

validate_vscode_input() {
	local workspace_dir="$1"
	local curr_file="$2"

	if [[ "${workspace_dir}" != '/'* ]]; then
		echo "Error: the provided workspace directory is not an absolute path!" 1>&2
		return 1
	fi

	if [[ "${curr_file}" != '/'* ]]; then
		echo "Error: the provided current file is not an absolute path!" 1>&2
		return 1
	fi
}

determine_project_directory() {
	local workspace_dir="$1"
	local curr_file="$2"
	local project_dir="$(dirname "${curr_file}")"

	until [ "${project_dir}" == "${workspace_dir}" ]; do
		[ -f "${project_dir}/Makefile" ] && break
		project_dir="$(dirname "${project_dir}")"
	done
	if [ "${project_dir}" == "${workspace_dir}" ]; then
		echo "Error: could not find project directory for file ${curr_file}!" 1>&2
		return 1
	fi
	echo "${project_dir}"
}

print_header() {
	local header="$1"
	local header_length=$(echo -n "${header}" | wc -c)

	echo "${header}"

	# Print as much dashes as header is long
	eval printf -- '-%.0s' {1..${header_length}}; echo
}

main "$@"
