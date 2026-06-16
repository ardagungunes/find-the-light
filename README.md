# Find The Light

A personal Unreal Engine 5 project created to learn gameplay programming, component-based design, and C++ development in Unreal Engine.

The project is currently in an early prototype stage. My long-term goal is to develop a dungeon escape game featuring environmental puzzles, traps, locked doors, and exploration mechanics. At this stage, I am primarily experimenting with gameplay systems and Unreal Engine architecture before implementing the complete game logic.

## Current Focus

The project serves as a playground for testing and learning:

* Unreal Engine C++ workflows
* Component-based gameplay programming
* Actor movement systems
* Gameplay prototyping
* Unreal Engine architecture and debugging

## Custom Mover Component

One of the systems I implemented is a reusable `Mover` Actor Component written in C++.

### Features

* Attachable to any Actor
* Configurable movement offset
* Adjustable movement duration
* Smooth interpolation between positions
* Toggle-based movement behavior
* Editor-exposed parameters using `UPROPERTY`

### Implementation Details

The component:

* Stores the Actor's initial position during `BeginPlay()`.
* Calculates a target position based on a configurable movement offset.
* Uses `FMath::VInterpConstantTo()` to move the Actor smoothly between locations.
* Supports activating and deactivating movement through a boolean flag.
* Updates movement every frame through Unreal Engine's component tick system.

### Concepts Practiced

Through this implementation I gained experience with:

* Custom Actor Components
* Unreal Engine Tick System
* Delta Time based movement
* Actor ownership (`GetOwner()`)
* FVector operations
* Interpolation functions
* Exposing variables to the Unreal Editor
* Component reusability

## Planned Features

The project is still under active development. Planned gameplay systems include:

* Dungeon exploration
* Locked doors and keys
* Environmental traps
* Puzzle mechanics
* Interactive objects
* Escape-room style progression
* Additional reusable gameplay components

## Technologies

* Unreal Engine 5
* C++
* Visual Studio
* Git

## Purpose

This project is part of my ongoing effort to strengthen my Unreal Engine and C++ skills through practical game development. Rather than focusing on a finished product, the current goal is to experiment with gameplay systems, learn Unreal Engine architecture, and build a solid foundation for future related projects.
