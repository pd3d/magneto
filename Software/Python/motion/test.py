"""
test

"""

from    paths      import *
from    motion     import *


#x, y, z, r, theta = helix()
#x, y, t = unit_helix()
x, y, z = prog_helix( 50, 50, 200 )

speed = 1200                            # mm/min

gcode_gen( "_helix_1200", x, y, z, speed )
