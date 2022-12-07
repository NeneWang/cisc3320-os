current:
	make hw4

hw4:
	make compile-file-only-current dir="hw4" f="test_unit"

hw4-mac:
	make compile-file-only-current-mac dir="hw4" f="test_unit"

compile-file: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ${f} < inputfile



compile-file-only-current: 
	g++ ${f}.cpp -o ${f} 
	${f}

compile-file-only-current-mac: 
	g++ -std=c++11 ${f}.cpp -o ${f} 
	./${f}




save:
	git add --all
	git commit -m "progress :construction:"
	git push origin HEAD


compile-file-only: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ${f}

compile-file-only-mac: 
	cd ${dir} && g++ -std=c++11 ${f}.cpp -o ${f} 
	cd ${dir} && ./${f}



