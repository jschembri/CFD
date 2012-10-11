# This python script solves the heat equation by calling up different C++ scripts
# created by Jeremy Schembr on September 30, 2012

from sys import argv
from matplotlib.patches import Patch
from pylab import *
import subprocess
import numpy as np
import math

def f_value(u):
	Re = 10000000
	return (u-1)/(u+1)-math.exp(-u*Re)

x_values  = arange(0,10,0.5)
y_values =[]
for x in x_values:
	y_values.append(f_value(x))



plt.plot(x_values, y_values, mfc='red', ms=12, label='Lax')
plt.xlabel('X Values')
show()

