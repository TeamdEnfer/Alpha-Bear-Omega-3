# ROS | Nodes and topics diagram

::: mermaid

%%{ init: { 'flowchart': { 'curve': 'catmullRom' } } }%%

flowchart TB;
    subgraph RPi4B
        direction TB
        PiNode([RPi 4B])
        rplidar[[RPLIDAR]]

        rplidar -- distances --> PiNode
    end

    subgraph CHAMP
        direction LR
        velocity_smoother([velocity smoother])
        trajectory_controller([trajectory controller])
        teleop([teleop])

        imu/data[IMU data]
    end

    subgraph Arduino Mega
        direction BT
        ArduiNode([Arduino Mega])
        servos[["Servos (x12)"]]

        ArduiNode -- "servo cmd" --> servos
    end

    subgraph Arduino Uno
        direction TB
        BNode([Arduino Uno])
        bno[[BNO]]
        bno-- quaternion --> BNode
    end

    bno_feedback_topic[BNO feedback]

    BNode --> bno_feedback_topic
    bno_feedback_topic --> imu/data
    
    subgraph GUI
        GUI_Node([GUI])
    end

    servo_id_topic[servo id]
    servo_cmd_topic[servo cmd]

    GUI_Node --> servo_id_topic
    GUI_Node --> servo_cmd_topic

    subgraph Controller
        direction TB
        joystick[[Controller]]
        joyNode([Joy])

        joystick -- inputs --> joyNode
        joyNode -- magic --> teleop

    end
:::
