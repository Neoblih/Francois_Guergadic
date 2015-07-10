sed '1~2d' | cut -d: -f 1 | rev | sort -r | sed -n '$MY_LINE1,$MY_LINE2p' | tr '\n' ',' | sed 's/,/, /g' | sed 's/.S//g' | sed 's/.$/./g' | sed 's/.$//g' | sed 's/.$/.\n/g'
