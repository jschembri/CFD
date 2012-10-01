# This python script solves the heat equation by calling up different C++ scripts
# created by Jeremy Schembr on September 30, 2012

from sys import argv
from matplotlib.patches import Patch
from pylab import *
import subprocess

def analytical_solution(x,y,t):
	test = subprocess.Popen('./analyticalHeatEquation %f %f %f' % (x,y,t), shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
	return float(test[0])
def test_solution(x,y):
	return x+y

if len(argv) < 2:
   calculated_time= "There is none"
else:
   script, calculated_time = argv

t = .01

dx, dy = 0.01, 0.01

x = arange(0, 1+dx, dx)
y = arange(0, 1+dy, dy)
X,Y = meshgrid(x, y)
T =  zeros((len(y), len(x))) 
#print T
i = 0


for x_cordinate in x:
	j = 0
	for y_cordinate in y:
		T[j,i] = analytical_solution(x[i], y[j],t)
		j += 1

	i += 1


pcolor(X,Y, T)
cb = colorbar()
axis([0,1,0,1])
title("Temperature Colour Plot")
xlabel('X Axis (Length)')
ylabel('Y Axis (Width)')
cb.set_label('Degrees Celsius ')

show()

