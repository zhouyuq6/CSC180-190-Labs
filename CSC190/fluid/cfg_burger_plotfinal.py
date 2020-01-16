import matplotlib
from matplotlib import pyplot, cm
from matplotlib.colors import Normalize
from cfg_burger import *


i=0
ax = pyplot.figure() 
norm = Normalize() 
magnitude = numpy.sqrt(final_u[::2]**2 + final_v[::2]**2) 
pyplot.quiver(final_u[::2], final_v[::2], norm(magnitude), scale=60, cmap=pyplot.cm.jet) 
ax.savefig('frame'+str(i).zfill(5)+'.png',dpi=300) 
ax.clear() 
