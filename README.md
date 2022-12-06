# ROS 2 chat application 

ros2 chat app is a simple topic publisher/subscriber-based ROS 2 node that can chat with each other with user input. We can run multiple instances of this node to create each chat room in the terminal.

# Prerequisites

* [Ubuntu 22.04 Focal Fossa](https://releases.ubuntu.com/22.04/)
* [ROS 2 humble hawksbill ](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)

# To build the code:

1. To build this package, you either need a ROS 2 workspace or create a new one. Here is the instructions to create a new ROS 2 workspace, build the package and run the instances of chat app

```
mkdir -p ~/ros2_ws/src

cd  ~/ros2_ws/src

git clone https://github.com/aleenalentin/ros2_chat-app

cd ~/ros2_ws

colcon build --packages-select cpp_pubsub

. install/setup.bash
```

# To run the code

Open 2 new terminals. Execute following commands in the corresponding terminal

Terminal 1:
```
. install/setup.bash
ros2 run cpp_pubsub listener --ros-args --remap __node:=chat_node_1 -p send_topic:=chat1 -p  recv_topic:=chat2

```
Terminal 2:

```bash
. install/setup.bash
ros2 run cpp_pubsub listener --ros-args --remap __node:=chat_node_2 -p send_topic:=chat2 -p  recv_topic:=chat1
```

# Demo 

Click on the following image to see the demo video








