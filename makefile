advection.pdf : advection.txt CB_graph.py
	python CB_graph.py

advection.txt : CB_advection.cpp
	c++ CB_advection.cpp -o adv
	./adv > advection.txt
