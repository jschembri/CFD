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

data= subprocess.Popen('./laxInviscid %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")
x_lax_values = data[data.index('X Lax Value Start')+1:data.index("X Lax Value End")]
for i in range(0,len(x_lax_values)):
   x_lax_values[i] = float(x_lax_values[i])
y_lax_values = data[data.index('Y Lax Value Start')+1:data.index("Y Lax Value End")]
for i in range(0,len(y_lax_values)):
   y_lax_values[i] = float(y_lax_values[i])

#data= subprocess.Popen('./ImplicitInviscid %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
#data = data[0].split(",")
#x_implicit_values = data[data.index('X Implicit Value Start')+1:data.index("X Implicit Value End")]
#for i in range(0,len(x_implicit_values)):
#   x_implicit_values[i] = float(x_implicit_values[i])
#y_implicit_values = data[data.index('Y Implicit Value Start')+1:data.index("Y Implicit Value End")]
#for i in range(0,len(y_implicit_values)):
#	y_implicit_values[i] = float(y_implicit_values[i])

## actual answer
#data= subprocess.Popen('./answer %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
#data = data[0].split(",")
#x_values = data[data.index('X Value Start')+1:data.index("X Value End")]
#for i in range(0,len(x_values)):
#   x_values[i] = float(x_values[i])
#y_values = data[data.index('Y Value Start')+1:data.index("Y Value End")]
#for i in range(0,len(y_values)):
#   y_values[i] = float(y_values[i])

# Lax-Wendroff
data= subprocess.Popen('./laxWendroff  %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")
x_lw_values = data[data.index('X Lax-Wendroff Start')+1:data.index("X Lax-Wendroff End")]
for i in range(0,len(x_lw_values)):
   x_lw_values[i] = float(x_lw_values[i])
y_lw_values = data[data.index('Y Lax-Wendroff Start')+1:data.index("Y Lax-Wendroff End")]
for i in range(0,len(y_lw_values)):
   y_lw_values[i] = float(y_lw_values[i])

data= subprocess.Popen('./mac %s' % calculated_time, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,stdin=subprocess.PIPE).communicate()
data = data[0].split(",")
x_mac_values = data[data.index('X Mac Start')+1:data.index("X Mac End")]
for i in range(0,len(x_mac_values)):
   x_mac_values[i] = float(x_mac_values[i])
y_mac_values = data[data.index('Y Mac Start')+1:data.index("Y Mac End")]
for i in range(0,len(y_mac_values)):
	y_mac_values[i] = float(y_mac_values[i])


#plt.plot(x_values, y_values, mfc='red', ms=12, label='Answer',linewidth=4)
#plt.plot(x_implicit_values, y_implicit_values, mfc='blue', ms=12, label='Implicit',linewidth=4)
plt.plot(x_mac_values, y_mac_values, mfc='blue', ms=12, label='Mac',linewidth=4)
plt.plot(x_lax_values, y_lax_values, mfc='red', ms=12, label='Lax',linewidth=4)
plt.plot(x_lw_values, y_lw_values, mfc='red', ms=12, label='Lax-Wendroff',linewidth=4)
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('Burger\'s Inviscid')
legend()
show()

