import numpy as np
import matplotlib.pyplot as plt

def mandelbrot(c, max_iter):
    z = c
    for n in range(max_iter):
        if abs(z) > 2:
            return n
        z = z*z + c
    return max_iter

def draw_mandelbrot(xmin,xmax,ymin,ymax,width,height,max_iter):
    r1 = np.linspace(xmin, xmax, width)
    r2 = np.linspace(ymin, ymax, height)
    return (r1,r2,np.array([[mandelbrot(complex(r, i),max_iter) for r in r1] for i in r2]))

xmin, xmax, ymin, ymax = -2.0, 1.0, -1.5, 1.5
width, height = 1000, 1000  # Increase resolution to 1000x1000
max_iter = 256

x, y, z = draw_mandelbrot(xmin, xmax, ymin, ymax, width, height, max_iter)

plt.figure(figsize=(10, 10))
plt.imshow(z, extent=(xmin, xmax, ymin, ymax))
plt.show()
