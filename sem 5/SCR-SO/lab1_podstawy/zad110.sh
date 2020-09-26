#!/bin/bash

FILENAME="$1"
FOLDERNAME="$2"

while true; do
	read -p "czy utworzyc plik o nazwie ${FILENAME}? (y/n)  " yn
	case $yn in
		[Yy]* ) touch $FILENAME; break;;
		[Nn]* ) exit;;

	* ) 
esac
done

while true; do
	read -p "czy utworzyc folder o nazwie ${FOLDERNAME}? (y/n)  " yn
	case $yn in
		[Yy]* ) mkdir $FOLDERNAME; break;;
		[Nn]* ) exit;;

	* ) 
esac
done
