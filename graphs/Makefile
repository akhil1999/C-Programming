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

heap:	heap.c
	gcc heap.c -g -o heap

priorityqueue:	priority_queue.c
	gcc priority_queue.c -g -o pq

weightedgraph:	weighted_graph.c
	gcc weighted_graph.c -g -o wg

dijkstra: dijkstra.c weighted_graph.c priority_queue.c
	gcc dijkstra.c weighted_graph.c priority_queue.c -g -o dijkstra

clean:
	rm queue
	rm stack
	rm list
	rm graph
	rm vector
	rm heap

