# Button mapping for controllers

Button maps for other controllers can be found [here](http://wiki.ros.org/joy#Application)

## Xbox One controller

### Axes

0: Joystick gauche: gauche <-> droite \[-32767, 32767\]  
1: gauche: haut <-> bas \[-32767, 32767\]  
2: Trigger (analog) gauche \[-32767, 32767\]  
3: Joystick droite: gauche <-> droite \[-32767, 32767\]  
4: Joystick droit: haut <-> bas \[-32767, 32767\]  
5: Trigger (analog) droite \[-32767, 32767\]  
6: D-pad gauche <-> droite {-32767, 32767}  
7: D-pad haut <-> bas {-32767, 32767}

	N.B. ROS: [-1.0, 1.0], {-1.0, 1.0}

### Boutons

0: A  
1: B  
2: X  
3: Y  
4: Bumper gauche  
5: Bumper droit  
6: Select  
7: Start  
8: Power/Menu  
9: Joystick gauche: appui  
10: Joystick droit: appui

## PlayStation 3 controller

### Axes
0: Joystick gauche: gauche <-> droite \[-32767, 32767\]  
1: gauche: haut <-> bas \[-32767, 32767\]  
2: Trigger (analog) gauche \[-32767, 32767\]  
3: Joystick droite: gauche <-> droite \[-32767, 32767\]  
4: Joystick droit: haut <-> bas \[-32767, 32767\]  
5: Trigger (analog) droite \[-32767, 32767\]

### Boutons

0: X  
1: O  
2: 🔺  
3: 🟥  
4: Bumper gauche  
5: Bumper droit  
6: Trigger gauche (bool)  
7: Trigger droit (bool)  
8: Select  
9: Start  
10: Power/Menu  
11: Trigger gauche: appui  
12: Trigger droit: appui  
13: D-pad Up  
14: D-pad Down  
15: D-pad Left  
16: D-pad Right

# Making the controller accessible by ROS joy node

```console
$ ls -l /dev/input/jsX
```

Output:  
	crw-rw-r--+ 1 root input 13, 0 Mar 12 08:05 /dev/input/jsX

if XX is rw: the device is configured properly.  
if XX is -- or r-, you need to:

```console
$ sudo chmod a+rw /dev/input/jsX
```

# Running the node

## prerequisites

### roscore

If the core hasn't been started yet, type:

```console
$ roscore
```

## Parameters

Below are examples of parameters that can be changed before running the node. For a complete list of parameters, see [the source documentation](http://wiki.ros.org/joy#Parameters).

```console
$ rosparam set joy_node/dev "/dev/input/jsX"
$ rosparam set joy_node/deadzone 0.25
```

    N.B. the deadzone parameter defaults to 0.05, but I find it too sensitive at that value. Value range: [0, 1]

## Starting the node

In a new terminal, type:

```console
$ roslaunch champ_teleop teleop.launch joy:=true
```

The champ_teleop node launches the joy node when the argument *joy* is set to true, so there is no need for *rosrun*.

To observe the commands read from the controller, in a new terminal, type:

```console
$ rostopic echo joy
```
