# The overall python script that runs the C++ program and displays the results

# analytic C++ displays the analytic answer
from __future__ import division
from math import *
from matplotlib.patches import Patch
from pylab import *
import subprocess
from sys import argv

if len(argv) < 2:
   calculated_time= "There is none"
else:
   script, calculated_time = argv



data= subprocess.Popen('./analytic %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

# Calculating the analytical answer
x_values = data[data.index('X Analytical Value Start')+1:data.index("X Analytical Value End")]
for i in range(0,len(x_values)):
   x_values[i] = float(x_values[i])

y_values = data[data.index('Y Analytical Value Start')+1:data.index("Y Analytical Value End")]
for i in range(0,len(y_values)):
   y_values[i] = float(y_values[i])

## Calculating the Euler Explicit equations
#data= subprocess.Popen('./upwind %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
#data = data[0].split(",")

#x_ee_values = data[data.index('X Euler Value Start')+1:data.index("X Euler Value End")]
#for i in range(0,len(x_ee_values)):
#   x_ee_values[i] = float(x_ee_values[i])

#y_ee_values = data[data.index('Y Euler Value Start')+1:data.index("Y Euler Value End")]
#for i in range(0,len(y_ee_values)):
#   y_ee_values[i] = float(y_ee_values[i])


## Calculating the Implicit
#data= subprocess.Popen('./implicit %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
#data = data[0].split(",")

#x_i_values = data[data.index('X Implicit Value Start')+1:data.index("X Implicit Value End")]
#for i in range(0,len(x_i_values)):
#   x_i_values[i] = float(x_i_values[i])

#y_i_values = data[data.index('Y Implicit Value Start')+1:data.index("Y Implicit Value End")]
#for i in range(0,len(y_i_values)):
#   y_i_values[i] = float(y_i_values[i])


## Calculating LaxWendroff
#data= subprocess.Popen('./laxWendroff %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
#data = data[0].split(",")

#x_lax_values = data[data.index('X Lax Value Start')+1:data.index("X Lax Value End")]
#for i in range(0,len(x_lax_values)):
#   x_lax_values[i] = float(x_lax_values[i])

#y_lax_values = data[data.index('Y Lax Value Start')+1:data.index("Y Lax Value End")]
#for i in range(0,len(y_lax_values)):
#   y_lax_values[i] = float(y_lax_values[i])

data= subprocess.Popen('./rusanov %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_rusanov_values = data[data.index('X Rusanov Value Start')+1:data.index("X Rusanov Value End")]
for i in range(0,len(x_rusanov_values)):
   x_rusanov_values[i] = float(x_rusanov_values[i])

y_rusanov_values = data[data.index('Y Rusanov Value Start')+1:data.index("Y Rusanov Value End")]
for i in range(0,len(y_rusanov_values)):
   y_rusanov_values[i] = float(y_rusanov_values[i])







plt.plot(x_values, y_values, mfc='red', ms=12, label='Analytical')
#plt.plot(x_ee_values, y_ee_values, mfc='blue', ms=12, label='Euler Upwind')
#plt.plot(x_i_values, y_i_values, mfc='orange', ms=12, label='Implicit')
#plt.plot(x_lax_values, y_lax_values, mfc='black', ms=12, label='Lax')
plt.plot(x_rusanov_values, y_rusanov_values, mfc='red', ms=12, label='Rusanov')
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('First Plot')
plt.axis([-1,7,-0.5,1.5])
legend()
show()

