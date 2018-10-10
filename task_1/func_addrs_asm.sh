while IFS=""
read -r p || [ -n "$p" ] 
do
	objdump -D libclient_comms.so libclient_crypt.so | grep -A 5 "$p"
done < func_addrs.txt
