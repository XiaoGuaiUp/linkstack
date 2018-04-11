linkstack:linkstack.c
	gcc -g -o $@ $^

.PHONY:clean
	clean:
	rm -f linkstack
	
	
