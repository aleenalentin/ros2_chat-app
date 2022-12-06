# ROS 2 chat application 
In this chatapp, we created a node with 2 instance. Each instance have a publisher and subscriber and we use parameters to change the topic name using commandline. 

# Prerequisites

* [Ubuntu 22.04 Focal Fossa](https://releases.ubuntu.com/22.04/)
* [ROS 2 humble hawksbill ](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)

# Create a package 

Open a terminal  source ROS 2 environment. 
Create a ros2_ws directory, inside it create a src folder.

```bash
mkdir -p ~/ros2_ws/src
cd  ros2_ws/src

```
 Clone to a ROS2 workspace inside src folder, do colcon build & source setup files.

```bash

cd ~/ros2_ws/src

https://github.com/aleenalentin/ros2_chat-app.git

cd ~/ros2_ws

colcon build --packages-select cpp_pubsub

. install/setup.bash

```

Now open 2 new terminal 

Terminal 1:
```bash
. install/setup.bash
ros2 run cpp_pubsub listener --ros-args --remap __node:=my_listener -p topic1:=chat1 -p  topic2:=chat2

```
Terminal 2:

```bash
. install/setup.bash
ros2 run cpp_pubsub listener --ros-args --remap __node:=my_listener -p topic1:=chat2 -p  topic2:=chat1
```

# Demo 

Click on the following image to see the demo video








