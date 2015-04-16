#!/bin/bash
to_format=$(
    find . | sed 's/^..//' |
        grep -E "^src/(common|engine|gamelogic)/.*\.(cpp|h|c)$" |
        grep -v "/ui/" | sort
)
echo "$to_format" | xargs -P 16 -I{} bash -c "echo 'Formatting {}' && clang-format -style=file -i {};"
