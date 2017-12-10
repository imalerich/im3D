## Ian Malerich - Com S 424 - Final Project

3D software rasterization renderer with OpenMP parallel optimizations.

## Build

The project requires no dependencies other than gcc. Simply run 
'make' to build the application.

## Run

A simple test run can be performed using 'make run', which will
render the 'models/war.obj' test scene. To run other models manually,
the syntax is of the form:

im3D NUM_THREADS MODEL_NAME

Running 'make run' executes the following, which renders war using 4 threads. 

./im3D 4 models/war.obj

## Sample Renders

- [alt tag](https://raw.githubusercontent.com/imalerich/im3D/master/samples/war.png)
- [alt tag](https://raw.githubusercontent.com/imalerich/im3D/master/samples/dragon.png)
