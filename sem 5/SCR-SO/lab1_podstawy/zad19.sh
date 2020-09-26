#!/bin/bash
set -x
mkdir katalog
touch plik.txt plik2.txt
mv plik.txt zmieniony.txt
chmod u+rw zmieniony.txt
rm plik2.txt


