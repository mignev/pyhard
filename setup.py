from distutils.core import setup, Extension

pyhardmodule = Extension('pyhard',
                    sources = ['lib/pyhardmodule.c'])

setup (name = 'PyHard',
       version = '1.0',
       author='Marian Ignev',
       author_email='m@ignev.net',
       url='http://m.ignev.net/code/pyhard',
       description = 'Creating hard links with python on MacOS',
       ext_modules = [pyhardmodule],
       scripts = ["bin/pyhard"],
       )
