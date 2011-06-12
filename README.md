# Motivation

On Mac OSX, we can't create hard links using the ln command.

# Installation

    git clone http://mignev@github.com/mignev/pyhard.git
    cd pyhard

With `make`:

    make install

Without `make`:
    
    python setup.py install

# Usage

    # python

    >> import pyhard
    >>
    >> #Creating hard link
    >> pyhard.link('/your/source/dir', '/your/destination/dir/')
    >>
    >> #Removing hard link
    >> pyhard.unlink('/your/hardlink/dir') 

