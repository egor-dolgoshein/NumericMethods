import matplotlib.pyplot as plt 
import math

#h = 0.1
h = 0.03

def exact_sol(h):
    y_list = []
    x_list = []
    x = 0
    y = 0
    ylist = []
    for i in range((int)(1/h)):
        x_list.append(x)
        y_list.append(y)
        x += h
        y = 10*(math.sin(5*x) + math.pow(math.e, math.sin(-5*x))-1)
        ylist.append(1)
    plt.plot(x_list,y_list, label = "exact solution")




def f(x,y):
    return 25*math.sin(10*x) - 5*y*math.cos(5*x)


def explTailor(h):
    x = 0
    y = 0
    xlist = []
    ylist = []
    for i in range((int)(1/h)):
        xlist.append(x)
        ylist.append(y)
        y += h * f(x, y)
        x += h
    plt.plot(xlist, ylist, label = "explicit Tailor")

def startRK(h):
    #Runge-Kutta 4
    y = 0
    x = 0
    k1 = h*f(x,y)
    k2 = h*f(x+h/2., y+k1/2)
    k3 = h*f(x+h/2.,y+k2/2)
    k4 = h*f(x+h, y+k3)
    return y+k1/6+k2/3+k3/3+k4/6


def implSimpson(h):
    x = 0
    y0 = 0
    y1 = startRK(h)
    y2 = y0
    xlist = []
    ylist = []
    xlist.append(x)
    xlist.append(x+h)
    ylist.append(y0)
    ylist.append(y1)
    for i in range((int)(1/h)):
        y2 = (y0 + h/3.*(25*math.sin(10*(x+2*h))+4*f(x+h, y1)+f(x,y0)))/(1+5*h/3*math.cos(5*(x+2*h)))
        ylist.append(y2)
        y0 = y1
        y1 = y2
        x += h
        xlist.append(x+h)
    plt.plot(xlist, ylist, label = "implicit Simpson")

def explRungeKutta3(h):
    x = 0
    y = 0
    xlist = []
    ylist = []
    for i in range((int)(1/h)):
        xlist.append(x)
        ylist.append(y)
        k1 = h * f(x, y)
        k2 = h * f(x + h, y + h)
        k3 = h * f(x + h / 2., y + 1. / 4 * k1 + 1. / 4 * k2)
        y = y + k1 / 6 + k2 / 6 + 2 * k3 / 3
        x += h
    plt.plot(xlist, ylist, label = "explicit Runge-Kutta 3rd order")


exact_sol(0.001)
explTailor(h)
implSimpson(h)
explRungeKutta3(h)
plt.title("Graphics with "+ str(h) + " step")
plt.legend(loc = "upper left")
plt.show()