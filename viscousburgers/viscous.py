# This python script solves the heat equation by calling up different C++ scripts
# created by Jeremy Schembr on September 30, 2012

from matplotlib.patches import Patch
from pylab import *
import subprocess

#plotting the steady-state results 
x_answer_values = arange(0,1,0.01)
y_answer_values = []

for x in x_answer_values:
	y_answer_values.append(float(subprocess.Popen('./answer %s' % x, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()[0]))

# calculating the explicit steady-state
data= subprocess.Popen('./explicit', shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_explicit_values = data[data.index('X Explicit Value Start')+1:data.index("X Explicit Value End")]
for i in range(0,len(x_explicit_values)):
   x_explicit_values[i] = float(x_explicit_values[i])

y_explicit_values = data[data.index('Y Explicit Value Start')+1:data.index("Y Explicit Value End")]
for i in range(0,len(y_explicit_values)):
   y_explicit_values[i] = float(y_explicit_values[i])




plt.plot(x_explicit_values, y_explicit_values, mfc='red', ms=12, label='Explicit')
plt.plot(x_answer_values, y_answer_values, mfc='red', ms=12, label='Answer')
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('First Plot')
legend()
show()

