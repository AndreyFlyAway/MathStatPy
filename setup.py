#!/usr/bin/env python

import os
import os.path
import sys


""" defines """
NAME = "MathStatPy"
VERSION = "0.0.1"
AUTHOR = "Yanikeev Andrey"
AUTHOR_EMAIL = "ggg235235@gmail.com"
URL= "https://github.com/AndreyFlyAway/MathStatPy"
DESCRIPTION = "Some functions that can be used in probability theory and mathematical statistics"
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

module1 = Extension(NAME,
		    include_dirs=['src', ],
            sources=['MathStatPy.c',
                     os.path.join('src', 'combinatorics.cpp'),
                     os.path.join('src', 'probability_type.cpp',),
                     os.path.join('src', 'probability_theory.cpp',),
                     ]
                    )

setup (name=NAME,
       version=VERSION,
       author=AUTHOR,
       author_email=AUTHOR_EMAIL,
       url=URL,
       description='This is a not spam package',
       package_dir={'src': 'src'},
       #ext_modules=[module1])
       ext_modules=[module1])