# The overall python script that runs the C++ program and displays the results

# analytic C++ displays the analytic answer
from __future__ import division
from math import *
from matplotlib.patches import Patch
from pylab import *
import subprocess
from sys import argv
from datetime import datetime


def std_and_max(an_array):
	var = 0
	abs_an_array =[]
	for i in range(len(an_array)-1):
		var = var + an_array[i]**2
		abs_an_array.append(abs(an_array[i]))
	std = (var/len(an_array))**(0.5)
	max_element = max(abs_an_array)
	return std, max_element


if len(argv) < 2:
   calculated_time= "There is none"
else:
   script, calculated_time = argv

print "Process | Time(s) | Standard Deviation | Max Error" 


# Calculating the Difference in Euler Explicit equations
t0 = datetime.now()
data= subprocess.Popen('./upwind %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_ee_values = data[data.index('X Euler Value Start')+1:data.index("X Euler Value End")]
for i in range(0,len(x_ee_values)):
   x_ee_values[i] = float(x_ee_values[i])

y_ee_values = data[data.index('Y Euler Value Start')+1:data.index("Y Euler Value End")]
for i in range(0,len(y_ee_values)):
   y_ee_values[i] = float(y_ee_values[i])

diff_ee_values = []
for i in range(0,len(y_ee_values)):
	analytic_answer = float(subprocess.Popen('./answer %s %s' % (calculated_time,x_ee_values[i]), shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()[0])
	diff_ee_values.append(analytic_answer - y_ee_values[i])
std, max_element = std_and_max(diff_ee_values)
t1 = datetime.now()
time = (t1-t0).seconds
print "%s | %s | %.3f | %.3f " % ("Upwind", time, std, max_element)

### Calculating the Implicit
t0 = datetime.now()
data= subprocess.Popen('./implicit %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_i_values = data[data.index('X Implicit Value Start')+1:data.index("X Implicit Value End")]
for i in range(0,len(x_i_values)):
   x_i_values[i] = float(x_i_values[i])

y_i_values = data[data.index('Y Implicit Value Start')+1:data.index("Y Implicit Value End")]
for i in range(0,len(y_i_values)):
   y_i_values[i] = float(y_i_values[i])

diff_i_values = []
for i in range(0,len(y_i_values)):
	analytic_answer = float(subprocess.Popen('./answer %s %s' % (calculated_time,x_i_values[i]), shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()[0])
	diff_i_values.append(analytic_answer - y_i_values[i])
std, max_element = std_and_max(diff_i_values)
t1 = datetime.now()
time = (t1-t0).seconds
print "%s | %s | %.3f | %.3f " % ("Implicit", time, std, max_element)


## Calculating LaxWendroff
t0 = datetime.now()
data= subprocess.Popen('./laxWendroff %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_lax_values = data[data.index('X Lax Value Start')+1:data.index("X Lax Value End")]
for i in range(0,len(x_lax_values)):
   x_lax_values[i] = float(x_lax_values[i])

y_lax_values = data[data.index('Y Lax Value Start')+1:data.index("Y Lax Value End")]
for i in range(0,len(y_lax_values)):
   y_lax_values[i] = float(y_lax_values[i])

diff_lax_values = []
for i in range(0,len(y_lax_values)):
	analytic_answer = float(subprocess.Popen('./answer %s %s' % (calculated_time,x_lax_values[i]), shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()[0])
	diff_lax_values.append(analytic_answer - y_lax_values[i])
std, max_element = std_and_max(diff_lax_values)
t1 = datetime.now()
time = (t1-t0).seconds
print "%s | %s | %.3f | %.3f " % ("Lax", time, std, max_element)

#Calculating Rusanov
data= subprocess.Popen('./rusanov %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")

x_rusanov_values = data[data.index('X Rusanov Value Start')+1:data.index("X Rusanov Value End")]
for i in range(0,len(x_rusanov_values)):
   x_rusanov_values[i] = float(x_rusanov_values[i])

y_rusanov_values = data[data.index('Y Rusanov Value Start')+1:data.index("Y Rusanov Value End")]
for i in range(0,len(y_rusanov_values)):
   y_rusanov_values[i] = float(y_rusanov_values[i])

diff_rusanov_values = []
for i in range(0,len(y_rusanov_values)):
	analytic_answer = float(subprocess.Popen('./answer %s %s' % (calculated_time,x_rusanov_values[i]), shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()[0])
	diff_rusanov_values.append(analytic_answer - y_rusanov_values[i])
std, max_element = std_and_max(diff_rusanov_values)
t1 = datetime.now()
time = (t1-t0).seconds
print "%s | %s | %.3f | %.3f " % ("Rusanov", time, std, max_element)






plt.plot(x_ee_values, diff_ee_values, mfc='red', ms=12, label='Upwind', linewidth=4)
plt.plot(x_i_values, diff_i_values, mfc='orange', ms=12, label='Implicit',linewidth=4)
plt.plot(x_lax_values, diff_lax_values, mfc='black', ms=12, label='Lax',linewidth=4)
plt.plot(x_rusanov_values, diff_rusanov_values, mfc='red', ms=12, label='Rusanov',linewidth=4)
plt.xlabel('X Values')
plt.ylabel('U delta')
plt.title('Difference')
plt.axis([0,2,-3,3])
legend()
show()

