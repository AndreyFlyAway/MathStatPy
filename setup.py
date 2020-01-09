#!/usr/bin/env python

import os
import os.path
import sys


""" defines """
NAME = "MathStatPy"
VERSION = "0.1"
AUTHOR = "Yanikeev Andrey"
AUTHOR_EMAIL = "ggg235235@gmail.com"
URL= "https://github.com/AndreyFlyAway/MathStatPy"
DESCRIPTION = "Some functions that can be used in probability theory and mathematical statistics"
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

module1 = Extension(NAME,
		    include_dirs = ['./common'],
                    #libraries = ['tcl83'],
                    #library_dirs = ['/home/user/Install/Python-3.8.1/build/lib.linux-x86_64-3.8/'],
                    sources = ['MathStatPy.c', "./common/combinatorics.cpp", "./common/combinatorics.h"])

setup (name=NAME,
       version=VERSION,
       author=AUTHOR,
       author_email=AUTHOR_EMAIL,
       url=URL,
       description = 'This is a spam package',
       ext_modules = [module1])