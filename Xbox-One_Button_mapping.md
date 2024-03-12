# Xbox One Controller button mapping

## Axes

0: Joystick gauche: gauche <-> droite \[-32767, 32767\]
1: gauche: haut <-> bas \[-32767, 32767\]
2: Trigger (analog) gauche \[-32767, 32767\]
3: Joystick droite: gauche <-> droite \[-32767, 32767\]
4: Joystick droit: haut <-> bas \[-32767, 32767\]
5: Trigger (analog) droite \[-32767, 32767\]
6: D-pad gauche <-> droite {-32767, 32767}
7: D-pad haut <-> bas {-32767, 32767}

	N.B. ROS: \[-1.0, 1.0\], {-1.0, 1.0}

## Boutons

0: A
1: B
2: X
3: Y
4: Bumper gauche
5: Bumper droit
6: Select
7: Menu
8: Media/share (non-fonctionnel)
9: Joystick gauche: appui
10: Joystick droit: appui

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

If the core hasn't been started yet, type:

```console
$ roscore
```

If the core has been started (through *roscore* or *roslaunch*), in a new terminal, set the parameters of the node:

```console
$ rosparam set joy_node/dev "/dev/input/jsX"
$ rosparam set joy_node/deadzone 0.25
```

Then start the node:

```console
$ rosrun joy joy_node
```

To observe the commands read from the controller, in a new terminal, type:

```console
$ rostopic echo joy
```
