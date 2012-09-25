# The overall python script that runs the C++ program and displays the results

# analytic C++ displays the analytic answer
from __future__ import division
from math import *
from matplotlib.patches import Patch
from pylab import *

import subprocess

data= subprocess.Popen('./analytic', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_values = data[data.index('X Value Start')+1:data.index("X Value End")]
for i in range(0,len(x_values)):
   x_values[i] = int(x_values[i])

y_values = data[data.index('Y Value Start')+1:data.index("Y Value End")]
for i in range(0,len(y_values)):
   y_values[i] = int(y_values[i])



print "The x values of the analytic equation are: ", x_values
print "The y values of the analytic equation are: ", y_values

y_test = randn(11)

plt.plot(x_values, y_values, mfc='red', ms=12, label='line label')
plt.plot(x_values, y_test)
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('First Plot')
legend()
show()

