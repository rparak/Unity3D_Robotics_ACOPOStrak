# B&R Automation ACOPOStrak transport system - Unity3D Industrial Robotics

## Requirements:

**Software:**
```bash
B&R Automation Studio, Unity3D 2020.3.3f1, Visual Studio 2017/2019
```

**Supported on the following operating systems:**
```bash
Universal Windows Platform, Android
```

Unity3D: https://unity3d.com/get-unity/download/archive

Unity HDRI Pack: https://assetstore.unity.com/packages/2d/textures-materials/sky/unity-hdri-pack-72511

B&R Automation: https://www.br-automation.com/en/downloads/#categories=Software-1344987434933

Visual Studio: https://visualstudio.microsoft.com/downloads/

## Project Description:

Example of a simple data processing application (OPC UA):

[OPC UA B&R Automation - Data Processing](https://github.com/rparak/OPCUA_Simple)

Main functions of the ACOPOStrak Digital-Twin model:
- Camera Control
- Connect/Disconnect -> Real HW or Simulation (OPC UA Communication - tested for simulation model only)
- Read Data (Position of the Shuttles, Camera position, etc.)
- Detection of the objects, change the color of objects, etc.
- NVIDIA PhysX, etc.

The application can be installed on a mobile phone, tablet or computer, but for communication with the machine it is necessary to be in the same network.

The project was realized at Institute of Automation and Computer Science, Brno University of Technology, Faculty of Mechanical Engineering (NETME Centre - Cybernetics and Robotics Division).

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

## Application:

## Result:

Youtube: ...

## Contact Info:
Roman.Parak@outlook.com

## License
[MIT](https://choosealicense.com/licenses/mit/)

