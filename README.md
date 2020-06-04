# linux-sample-priv-escalation-attack

## Overview
Just sample program code. There's no contain any code for attack.

## Before Compilation
You need to write a file path to db/id.list

~~~
$ vim fileman/fileman.h

#define DB  /your/path/to/db/id.list
~~~

## Compile Script
`compile.sh` script requires `sudo` command.
~~~
sudo chown -v root:root db/id.db
sudo chmod -v 0600 db/id.db
sudo chown -v root:root target.bin
sudo chmod -v 4755 target.bin
~~~

## How to compile
Just run `compile.sh`
~~~
./compile.sh
~~~
