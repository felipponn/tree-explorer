test_tree_infos:	test_tree_infos.cpp create_tree.cpp tree_infos.cpp
	g++ test_tree_infos.cpp create_tree.cpp tree_infos.cpp -o teste_tree_infos.exe
	./teste_tree_infos.exe

test_sort_list:	test_sort_list.cpp create_tree.cpp sort_list.cpp
	g++ test_sort_list.cpp create_tree.cpp sort_list.cpp -o test_sort_list.exe
	./test_sort_list.exe

test_create_tree:	test_create_tree.cpp create_tree.cpp
	g++ test_create_tree.cpp create_tree.cpp -o test_create_tree.exe
	./test_create_tree.exe

main:	main.cpp interface.cpp create_tree.cpp tree_infos.cpp BFS.cpp sort_list.cpp
	g++ -o main.exe main.cpp interface.cpp create_tree.cpp tree_infos.cpp BFS.cpp sort_list.cpp
	./main.exe