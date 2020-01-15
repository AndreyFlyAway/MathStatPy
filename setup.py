#!/usr/bin/env python

import os
import os.path
import sys


""" defines """
NAME = "MathStatPy"
VERSION = "0.3"
AUTHOR = "Yanikeev Andrey"
AUTHOR_EMAIL = "ggg235235@gmail.com"
URL= "https://github.com/AndreyFlyAway/MathStatPy"
DESCRIPTION = "Some functions that can be used in probability theory and mathematical statistics"
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

module1 = Extension(NAME,
		    include_dirs=['common', ],
            sources=['MathStatPy.c',
                     os.path.join('common', 'combinatorics.cpp'),
                     os.path.join('common', 'probability_type.cpp',),
                     ]
                    )

setup (name=NAME,
       version=VERSION,
       author=AUTHOR,
       author_email=AUTHOR_EMAIL,
       url=URL,
       description='This is a not spam package',
       package_dir={'common': 'common'},
       #ext_modules=[module1])
       ext_modules=[module1])