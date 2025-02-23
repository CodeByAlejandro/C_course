#!/usr/bin/env bash

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
WORKSPACE_FILE="${SCRIPT_DIR}/C_course.code-workspace"

# Regenerate C_course.code-workspace file with up-to-date project list
main() {
	local temp_file="$(mktemp)"

	local skip_lines=false
	while IFS= read -r line; do
		if [ "$skip_lines" == false ]; then
			echo "$line" >> "${temp_file}"
		else
			if [[ "$line" =~ ']' ]]; then
				echo "$line" >> "${temp_file}"
				skip_lines=false
			fi
		fi

		if [[ "$line" =~ '"folders":'[[:space:]]+'[' ]]; then
			skip_lines=true
			local indent_lvl=$(($(echo -en "$line" | sed -r 's/^(\t*).*/\1/' | wc -c) + 1))
			echo "$(generate_projects_json ${indent_lvl})" >> "${temp_file}"
		fi
	done < "${WORKSPACE_FILE}"
	if [ -n "$line" ]; then
		echo "$line" >> "${temp_file}"
	fi

	# Overwrite the C_course.code-workspace file (atomic-IO) and cleanup temp file
	mv "${temp_file}" "${WORKSPACE_FILE}"
	rm -f "${temp_file}"
}

# Generate JSON-code for all projects found in workspace to add in C_course.code-workspace file
# It takes into account the current indentation lvl
generate_projects_json() {
	local indent_lvl=$1
	local -a projects

	print_indentation ${indent_lvl}
	echo -en '{\n'
	((indent_lvl++))
	print_indentation ${indent_lvl}
	echo -en '"name": ".vscode-workspace",\n'
	print_indentation ${indent_lvl}
	echo -en '"path": "./"\n'
	((indent_lvl--))
	print_indentation ${indent_lvl}
	echo -en '}'

	readarray -t projects < <(ls -m1 "${SCRIPT_DIR}/../")

	local project_name
	for project in "${projects[@]}"; do
		if [ -d "${SCRIPT_DIR}/../${project}" ]; then
			# Split project directory into words based on capital letters and numbers and capitalize the first word
			project_name="$(echo "${project}" | sed -r 's/([A-Z])/ \1/g;s/([[:digit:]]+)/ \1/g' | sed 's/^ //' | sed 's/.*/\u&/')"

			echo -en ',\n'
			print_indentation ${indent_lvl}
			echo -en '{\n'
			((indent_lvl++))
			print_indentation ${indent_lvl}
			echo -en '"name": "'
			echo -n "${project_name}"
			echo -en '",\n'
			print_indentation ${indent_lvl}
			echo -en '"path": "../'
			echo -n "${project}"
			echo -en '"\n'
			((indent_lvl--))
			print_indentation ${indent_lvl}
			echo -en "}"
		fi
	done
	echo
}

# Print x number of tabs
print_indentation() {
	local indent_lvl=$1

	# Print as many tabs as the number in the indent_lvl variable
	eval printf '\\t%.0s' {1..${indent_lvl}}
}

main "$@"