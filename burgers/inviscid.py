# This python script solves the heat equation by calling up different C++ scripts
# created by Jeremy Schembr on September 30, 2012

from sys import argv
from matplotlib.patches import Patch
from pylab import *
import subprocess


if len(argv) < 2:
   calculated_time= "There is none"
else:
   script, calculated_time = argv

print calculated_time
print './laxInviscid %s' % calculated_time
data= subprocess.Popen('./laxInviscid %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_values = data[data.index('X Lax Value Start')+1:data.index("X Lax Value End")]
for i in range(0,len(x_values)):
   x_values[i] = float(x_values[i])

y_values = data[data.index('Y Lax Value Start')+1:data.index("Y Lax Value End")]
for i in range(0,len(y_values)):
   y_values[i] = float(y_values[i])


plt.plot(x_values, y_values, mfc='red', ms=12, label='Lax')
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('First Plot')
plt.axis([-1,7,-0.5,1.5])
legend()
show()

