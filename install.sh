#/bin/bash


echo "Choose what to install"
select mode in all git_submodules webots champ build;
do
	case $mode in

	all | git_submodules)  
	
		echo "installing git_submodules"
		git submodule init
		git submodule update
		pushd ./control/ros_ws/src/champ
		git submodule init
		git submodule update
		popd
		pushd ./control/ros_ws/src/champ_setup_assistant
		git checkout ubuntu2004python3
		popd;;&
	
	all | webots)  
		
		echo "installing webots"
		pushd ~/Downloads/
		wget https://github.com/cyberbotics/webots/releases/download/R2023b/webots_2023b_amd64.deb
		sudo apt install ./webots_2023b_amd64.deb -y
		sudo apt install ros-noetic-webots-ros -y
		rm -Rf ./webots_2023b_amd64.deb
		popd;;&

	all | champ)

		echo "installing champ"
		sudo apt install -y python3-rosdep
		pushd control/ros_ws
		rosdep install --from-paths src --ignore-src -r -y
		popd;;&

	all | build)

		echo "building the ros packages"
		pushd control/ros_ws
		catkin_make
		popd;;&
		
	
	esac;
	break;
done






