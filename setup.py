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
		    include_dirs=['common'],
            sources=['MathStatPy.c'], )

module1_common = Extension('common',
		    include_dirs=['common'],
            sources=[os.path.join('common', 'combinatorics.cpp')], )

setup (name=NAME,
       version=VERSION,
       author=AUTHOR,
       author_email=AUTHOR_EMAIL,
       url=URL,
       description='This is a not spam package',
       package_dir={'common': 'common'},
       #ext_modules=[module1])
       ext_modules=[module1, module1_common])