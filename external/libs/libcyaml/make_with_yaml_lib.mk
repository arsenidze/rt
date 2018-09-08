all:
	make -C yaml-0.2.1
	cp -f yaml-0.2.1/src/.libs/libyaml.a ./ 
	make

clean:
	make clean
	$(RM) -f libyaml.a
	make clean -C yaml-0.2.1
