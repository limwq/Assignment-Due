# Assignment Due 🚪

A 3D horror escape room prototype built in Unreal Engine 5, focusing on modular interaction and dynamic puzzle solving. 

<img width="1280" height="720" alt="AssDue" src="https://github.com/user-attachments/assets/5fde343e-fe34-420a-84e4-770ee11b78d0" />


## 📌 Overview
Developed as a collaborative university project, **Assignment Due** requires players to navigate a tense environment by solving inventory-based puzzles and managing their states. This repository highlights the core C++ architecture, modular Blueprint systems, and UI/UX implementation.

* **Engine:** Unreal Engine 5 (C++ & Blueprints)
* **Role:** Gameplay Programmer & Game Designer

## 👥 The Team
* **Lim Wei Qi:** Lead Programmer & Level 1 Designer – Core gameplay systems, timer logic, inventory management, and technical C++ implementation for the scene manager. Focused on puzzle interaction and player mechanic for Level 1. 
* **Wong Jing Le:** Level 1 Designer, AI Programmer & UI/Media Designer – Development of the enemy AI behavior tree, UI element design, and production of game videos and animations.
* **Ham Xiao Tong:** Environment Artist, 3D Modeler & Level 2 Designer – Creation of school environment models (chairs, tables, lockers) and implementation of Level 2 mechanics.

## ⚙️ Key Technical Contributions (My Work)
If you are reviewing my code, I was responsible for architecting the following systems:

* **Modular Interaction (`BPI_Interactable`)**: Decoupled player logic from environmental objects using a Blueprint Interface. The player controller casts a dynamic line-trace, allowing seamless interactions with doors, lockers, and inventory items without hard-coded cast checks.
* **Core Game State & UI**: Engineered the C++ backend for the `BaseGameMode`, `MyGameInstance`, and `SceneManager` to handle level transitions and timers. Developed the UMG widget blueprints for the HUD, Pause Manager, and interactive passcode interfaces.
* **Character Controller (`BP_Player`)**: Scripted player movement, stamina management, and object pickup/validation logic.

## 🎮 Play the Game
A playable build is available on [itch.io](https://limwq.itch.io/assignment-due).

## 🚀 How to Run the Project Locally
1. Clone this repository.
2. Open Unreal Engine 5.
3. Browse and select the `AssignmentDue.uproject` file.
