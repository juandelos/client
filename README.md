# client
Simple publisher suscriber that squares a given number and then shits down Ros Master.
## Build
Create caktin_ws and clone repository in src

From root of directory:
```
catkin_make
```

## Run
from root of directory 
```
source devel/setup.bash
roslaunch client start.launch num:=<number tobe sqaured>
```
