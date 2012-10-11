# The overall python script that runs the C++ program and displays the results

# analytic C++ displays the analytic answer
from __future__ import division
from math import *
from matplotlib.patches import Patch
from pylab import *

import subprocess

data= subprocess.Popen('./analytic 2', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

print data

x_values = data[data.index('X Analytical Value Start')+1:data.index("X Analytical Value End")]
for i in range(0,len(x_values)):
   x_values[i] = float(x_values[i])

y_values = data[data.index('Y Analytical Value Start')+1:data.index("Y Analytical Value End")]
for i in range(0,len(y_values)):
   y_values[i] = float(y_values[i])

# Calculating the Euler Explicit equations
x_ee_values = data[data.index('X Euler Value Start')+1:data.index("X Euler Value End")]
for i in range(0,len(x_values)):
   x_ee_values[i] = float(x_ee_values[i])

y_ee_values = data[data.index('Y Euler Value Start')+1:data.index("Y Euler Value End")]
for i in range(0,len(y_values)):
   y_ee_values[i] = float(y_ee_values[i])





plt.plot(x_values, y_values, mfc='red', ms=12, label='Analytical')
plt.plot(x_ee_values, y_ee_values, mfc='blue', ms=12, label='Euler')
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('First Plot')
plt.axis([-1,7,-0.5,1.5])
legend()
show()

