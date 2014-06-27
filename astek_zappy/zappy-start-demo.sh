#!/bin/sh
cd /afs/epitech.net/users/all/astek/public/
./zappy-server-freebsd -p 4242 -t 10 -n toto titi &
./zappy-gfx-freebsd localhost 4242 &

