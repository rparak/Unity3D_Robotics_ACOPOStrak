# Unity3D Industrial Robotics: B&R Automation ACOPOStrak transport system

## Requirements:

**Software:**
```bash
B&R Automation Studio, Blender, Unity3D 2020.3.3f1, Visual Studio 2017/2019
```

**Supported on the following operating systems:**
```bash
Universal Windows Platform, Android
```

| Software/Package      | Link                                                                                  |
| --------------------- | ------------------------------------------------------------------------------------- |
| Blender               | https://www.blender.org/download/                                                     |
| Unity3D               | https://unity3d.com/get-unity/download/archive                                        |
| Unity HDRI Pack       | https://assetstore.unity.com/packages/2d/textures-materials/sky/unity-hdri-pack-72511 |
| B&R Automation        | https://www.br-automation.com/en/downloads/#categories=Software-1344987434933         |
| SceneViewer B&R       | https://www.br-automation.com/en/downloads/software/simulation/br-scene-viewer/       |
| Visual Studio         | https://visualstudio.microsoft.com/downloads/                                         |

## Project Description:

The project is focused on a simple demonstration of client / server communication via OPC UA, which is implemented in Unity3D (Server - B&R Automation PLC, Client - Unity3D). The project demonstrates the Digital-Twin of the ACOPOStrak with some additional functions. The application uses performance optimization using multi-threaded programming.

The main idea of the application is to demonstrate the control of an amazing machine that can be used for adaptive production. For visual inspection of the object, we use a B&R 2D camera/sensor with additional light and the entire control program (velocity and / or position control of shuttles (min 1 - max 6) around multiple sectors (A, B), alarm handling, and others) is programmed on the PLC (OPC UA Server).

The Unity3d digital-twin application is used to visualize the scene and randomly change the colors of objects. The application also uses a package (Human-Machine interface - mappView) for data visualization. This data can be viewed locally on the PC panel or remotely on any device using a standard web browser (data management in mappView is completely based on OPC UA).

**MappView (HMI):**
```bash
Simulation Address
PLC_ADDRESS = localhost or 127.0.0.1

http://PLC_ADDRESS:81/index.html?visuId=acp_trak_dt
```

Main functions of the ACOPOStrak Digital-Twin model:
- Camera Control
- Connect/Disconnect -> Real HW or Simulation (OPC UA Communication - tested for simulation model only)
- Read Data (Position of the Shuttles, Camera position, etc.)
- Detection of the objects, change the color of objects, etc.
- NVIDIA PhysX, etc.

Note:
Another case of controlling a digital-twin application is the use of a simulation tool designed by B&R Automation (Scene Viewer).

The application can be installed on a mobile phone, tablet or computer, but for communication with the machine it is necessary to be in the same network.

The project was realized at Institute of Automation and Computer Science, Brno University of Technology, Faculty of Mechanical Engineering (NETME Centre - Cybernetics and Robotics Division).

**Appendix:**

Example of a simple data processing application (OPC UA):

[OPC UA B&R Automation - Data Processing](https://github.com/rparak/OPCUA_Simple)

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_2.PNG" width="800" height="500">
</p>

## Project Hierarchy:

**Repositary [/Unity3D_Robotics_ACOPOStrak/]:**

```bash
/ACOPOSTrak_OPCUA_Unity_App/ -> Unity3D Project
[ Data Processing              ] /Assets/Script/ACOPOSTrak_Control/
[ Object / Light Control, etc. ] /Assets/Script/Service/
[ Individual objects (.blend)  ] /Assets/Object/Blender/
[ Scene of the Application     ] /Assets/Scenes/

/Scene_Viewer/Trak/ -> Scene Viewer Digital-Twin
[ Main 3D Simulation Model ] /gAssembly_1_GuideSystem.scn
[ Main 2D Simulation Model ] /gAssembly_1.scn

/acoposTrak_simple_control/ -> Automatio Studio B&R Project
[ Main Program (control of the main state machine)                  ] /Logical/Technology/tCTRL_m/Main.c
[ Header File (auxiliary functions, declaration of variables, etc.) ] /Logical/Technology/tCTRL_m/Main.h
[ MappView Visualization                                            ] /Logical/mappView/
[ ACOPOStrak Configuration (Sectors, Shuttles, etc.)                ] /Physical/Config1/X20CP3687X/mappMotion/TrakOval/
```

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_1.PNG" width="800" height="500">
</p>

## Application:

**Unity3D Digital-Twin:**

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_3.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_4.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_5.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_6.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_7.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_8.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/dt_9.png" width="800" height="450">
</p>

**Scene Viewer Digital-Twin:**

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/sv_1.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/sv_2.png" width="800" height="450">
</p>

## HMI (Human-Machine Interface) - MappView:

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/mv_1.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/mv_2.png" width="800" height="450">
<img src="https://github.com/rparak/Unity3D_Robotics_ACOPOStrak/blob/main/images/mv_3.png" width="800" height="450">
</p>

## Result:

Youtube: https://www.youtube.com/watch?v=Dnw5PxeZf7k

## Contact Info:
Roman.Parak@outlook.com

## License
[MIT](https://choosealicense.com/licenses/mit/)

