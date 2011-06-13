# Motivation

On Mac OSX, we can't create hard links using the `ln` command.

# Installation

    git clone http://mignev@github.com/mignev/pyhard.git
    cd pyhard

With `make`:

    make install

Without `make`:
    
    python setup.py build
    sudo python setup.py install

# Usage

Using `pyhard` python module:

    # python

    >> import pyhard
    >>
    >> #Creating hard link
    >> pyhard.link('/your/source/dir', '/your/destination/dir/')
    >>
    >> #Removing hard link
    >> pyhard.unlink('/your/hardlink/dir') 

Using `pyhard` executable:
    
    ### Creating hard link
    # pyhard <source_dir> <hardlink_dir>

    ### Removing hard link
    # pyhard rm <hardlink_dir>

# Copyright
PyHard is licensed under the GPL: http://www.gnu.org/licenses/gpl-3.0.html
