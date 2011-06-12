help:
	@echo "   install      to install pyhard module"
	@echo "   uninstall    to uninstall pyhard module"
	@echo "   clean        to clean build files"

install:
	@echo "Installing"
	@python setup.py build
	@python setup.py install --record installed_files.txt

uninstall: clean
	@cat installed_files.txt | xargs rm -rf
	@rm installed_files.txt    

clean:
	@rm -rf build
