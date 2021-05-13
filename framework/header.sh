prot=$(find . -name '*.c' | xargs cat | sed -e '/^\w/!d')
# echo "${prot}"
TABS=$(echo "${prot}" | sed 's/\t.*//g' | awk '{print length($0)}' | sort -nr | head -n 1 | xargs -I{} expr {} / 4 + 1)

echo "${prot}" | sed 's/\t//g'
# echo "${prot}" | awk '{print $0}' | sed 's/\t//g'