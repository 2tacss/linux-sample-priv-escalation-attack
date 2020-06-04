#!/bin/sh

echo '\e[32mStarting proceess...\e[m'
echo
if [ -e 'target.bin' ]; then
	echo '[*] \e[33mRemove the old execution file\e[m.'
	echo
	rm -f target.bin
fi

echo '[*] Compiling with...'
echo '[gcc: \e[36mg3, O0, fno-stack-protector execstack ]\e[m'
echo
gcc -m32 -g3 -O0  -fno-stack-protector -zexecstack main.c fileman/fileman.c fileman/fileman.h exception/exception.c exception/exception.h -o target.bin

echo '[*] Change `\e[36mdb/id.list\e[m` owner to `\e[33mroot\e[m`'
sudo chown -v root:root db/id.db
echo

echo '[*] Change \e[36mthe file bit\e[m to `\e[33m0600\e[m`'
sudo chmod -v 0600 db/id.db
echo

echo '[*] Change `\e[36mtarget.bin\e[m` owner to `\e[33mroot\e[m`'
sudo chown -v root:root target.bin
echo

echo '[*] Set a bit of `\e[36mset uid\e[m` priv to `\e[33mtarget.bin\e[m`'
sudo chmod -v 4755 target.bin
echo

echo
echo "[*] \e[32mWe've Done\e[m."

#gcc -m32 -Iexception/ -Ifileman/ main.c exception/exception.c exception/exception.h fileman/fileman.c fileman/fileman.h  -o target.bin
