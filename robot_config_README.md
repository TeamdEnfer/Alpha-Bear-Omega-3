Fichiers à modifier pour champ

# Chemin des fichiers de configuration du robot

**URDF:** control/ros_ws/src/alphabearomega3/worlds/Robot.urdf
**Joints:** control/ros_ws/src/alphabear_config/config/joints/joints.yaml
**Links:** control/ros_ws/src/alphabear_config/config/links/links.yaml
**Gait:** control/ros_ws/src/alphabear_config/config/gait/gait.yaml
**Référence des paramètres du gait:** control/ros_ws/src/champ_setup_assistant/docs/images/gait_parameters.png

# Paramètres du gait

### Paramètres à ne pas modifier

* knee_orientation
* pantograph_leg

### Paramètres pouvant être modifiés

* **odom_scaler :** facteur d'échelle pour compensation d'erreurs d'odométrie [1.0, 1.2]
* **max_linear_velocity_x :** vitesse max avant/arrière (m/s)
* **max_linear_velocity_y :** vitesse max déplacement vers gauche/droite (m/s)
* **max_angular_velocity_z :** vitesse max rotation (rad/s)
* **com_x_translation :** offset du point de référence dans l'axe X (i.e. compenser si centre de masse de la jambe pas aligné avec l'épaule) (m)
* **swing_height :** distance entre le sol et le centre de la patte au point le plus haut de l'élévation (m)
* **stance_depth :** delta distance du genou au point le plus bas durant un cycle (m)
* **stance_duration :** temps qu'une jambe passe appuyée au sol durant un cycle (s)
* **nominal_height :** distance entre l'épaule et le sol durant un cycle (m)