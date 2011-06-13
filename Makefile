help:
	@echo "   install      to install pyhard module"
	@echo "   uninstall    to uninstall pyhard module"
	@echo "   clean        to clean build files"

install:
	@echo "Installing"
	@python setup.py build
	@echo "Enter your sudo password"
	@sudo python setup.py install --record installed_files.txt

uninstall: clean
	@echo "Enter your sudo password"
	@cat installed_files.txt | xargs sudo rm -rf
	@rm installed_files.txt    

clean:
	@rm -rf build
