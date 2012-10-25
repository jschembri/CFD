# This python script solves the heat equation by calling up different C++ scripts
# created by Jeremy Schembr on September 30, 2012
from sys import argv
from matplotlib.patches import Patch
from pylab import *
import subprocess

# calculating the analytic answer
data= subprocess.Popen('./answer', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")
x_values = data[data.index('X Values Start')+1:data.index("X Values End")]
for i in range(0,len(x_values)):
   x_values[i] = float(x_values[i])
y_values = data[data.index('Y Values Start')+1:data.index("Y Values End")]
for i in range(0,len(y_values)):
   y_values[i] = float(y_values[i])

## calculating the explicit steady-state
data= subprocess.Popen('./explicit', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_explicit_values = data[data.index('X Explicit Value Start')+1:data.index("X Explicit Value End")]
for i in range(0,len(x_explicit_values)):
   x_explicit_values[i] = float(x_explicit_values[i])

y_explicit_values = data[data.index('Y Explicit Value Start')+1:data.index("Y Explicit Value End")]
for i in range(0,len(y_explicit_values)):
   y_explicit_values[i] = float(y_explicit_values[i])

data= subprocess.Popen('./FTCS', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")
x_FTCS_values = data[data.index('X FTCS Start')+1:data.index("X FTCS End")]
for i in range(0,len(x_FTCS_values)):
   x_FTCS_values[i] = float(x_FTCS_values[i])
y_FTCS_values = data[data.index('Y FTCS Start')+1:data.index("Y FTCS End")]
for i in range(0,len(y_FTCS_values)):
   y_FTCS_values[i] = float(y_FTCS_values[i])

data= subprocess.Popen('./MacCormack', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")
x_Mac_values = data[data.index('X Mac Start')+1:data.index("X Mac End")]
for i in range(0,len(x_Mac_values)):
   x_Mac_values[i] = float(x_Mac_values[i])
y_Mac_values = data[data.index('Y Mac Start')+1:data.index("Y Mac End")]
for i in range(0,len(y_Mac_values)):
   y_Mac_values[i] = float(y_Mac_values[i])




plt.plot(x_explicit_values, y_explicit_values, mfc='red', ms=12, label='Brailovskaya',linewidth=4)
plt.plot(x_values, y_values, mfc='black', ms=12, label='Answer',linewidth=4)
plt.plot(x_FTCS_values, y_FTCS_values, mfc='blue', ms=12, label='FTCS',linewidth=4)
#plt.plot(x_Mac_values, y_Mac_values, mfc='blue', ms=12, label='MacCormack',linewidth=4)
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('Burger\'s Viscous Equation')
plt.axis([0,1,-0.5,1.5])
legend()
show()

