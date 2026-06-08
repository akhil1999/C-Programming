queue:	queue.c
	gcc -o queue queue.c
	
stack:	stack.c
	gcc -o stack stack.c
	
list:	list.c
	gcc -o list list.c
	
graph:	graph_alt_2.c
	gcc graph_alt_2.c list.c stack.c queue.c -g -o graph
	
vector: vector.c
	gcc vector.c -g -o vector

clean:
	rm queue
	rm stack
	rm list
	rm graph
	rm vector

