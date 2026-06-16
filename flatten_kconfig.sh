#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-only
# PATCHED: skip missing source files (stubbed drivers) instead of erroring
set -e
while IFS= read -r line ; do
	if [[ "$line" =~ source\ \"(.*)\" ]] ; then
		f="${BASH_REMATCH[1]/(/{}"
		f="${f/)/\}}"
		expanded="$(eval echo "${f}")"
		if [ -f "$expanded" ]; then
			"$0" "$expanded"
		else
			printf "# SKIPPED missing source: %s\n" "$expanded"
		fi
	else
		printf "%s\n" "$line"
	fi
done < $1
