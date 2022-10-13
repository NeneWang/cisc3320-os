test:
	make compilef file=AnalyzeWords

save:
	git add --all
	git commit -m "progress :construction:"
	git push origin HEAD

test-all:
	make compilef file=thread-exec 
	make compilef file=bank

compile:
	g++ main.cpp -std=c++11 && ./a.out


compilef:
	g++ ${file}.cpp -std=c++11 && ./a.out








