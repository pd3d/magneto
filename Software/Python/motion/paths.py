"""
Paths

Module containing 3D functions generating 3D paths

Fluvio L Lobo Fenoglietto
"""

"""
Import Modules and Libraries
"""
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt



def helix():
    """
    Generates a default parametric helix obtained from the matplotlib examples
    """

    mpl.rcParams['legend.fontsize'] = 10
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    theta = np.linspace(0, 2*np.pi, 100)
    z = np.linspace(0, 1, 100)
    r = z + 1
    x = r * np.sin(theta)
    y = r * np.cos(theta)
    ax.plot(x, y, z, label='parametric curve')
    ax.legend()
    plt.show()
    
    return x, y, z, r, theta

def unit_helix():
    """
    Generates a unit helix
    """

    mpl.rcParams['legend.fontsize'] = 10
    fig = plt.figure()
    ax = fig.gca(projection='3d')


    t = np.linspace(0, 1, 1000)
    #z = np.linspace(0, 1, 100)
    #r = z + 1
    x = np.cos(t)
    y = np.sin(t)
    ax.plot(x, y, t, label='parametric curve')
    ax.legend()
    plt.show()
    
    return x, y, t

def prog_helix( max_x, max_y, max_z ):
    """
    Generates a helix based on the maximum ranges in x, y, and z, given by;
        x --> ( -max_x, max_x )
        y --> ( -max_y, max_y )
        z --> (      0, max_z )
    """

    mpl.rcParams['legend.fontsize'] = 10
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    z = np.linspace(0, max_z, 5000)
    x = max_x*np.cos(z)
    y = max_y*np.sin(z)
    ax.plot(x, y, z, label='parametric curve')
    ax.legend()
    plt.show()
    
    return x, y, z 
