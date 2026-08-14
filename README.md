# Find the Light

Find the Light is an early-stage first-person dungeon escape prototype built with Unreal Engine 5 and C++. The project explores reusable gameplay systems for environmental puzzles, including collectible keys, interactive locks, pressure plates, and smoothly moving doors or platforms.

The long-term goal is to turn these systems into an atmospheric escape game centered on exploration, traps, and puzzle-driven progression.

## Project Status

This project is currently a learning prototype, not a finished or packaged game. Its main purpose is to practice Unreal Engine gameplay programming, component-based design, debugging, and C++/Blueprint integration.

## Implemented Features

- First-person movement, camera control, and jumping
- Enhanced Input-based interaction system
- Sphere-sweep interaction detection with configurable range and radius
- Collectible items identified by editable item names
- Lightweight player inventory for collected items
- Locks that accept and return matching key items
- Reusable moving-actor component for doors, platforms, and similar objects
- Pressure plates that activate moving actors while tagged objects overlap them
- Editor-exposed gameplay settings through `UPROPERTY`
- Debug lines and spheres for visualizing interaction traces

## Core Gameplay Systems

### Interaction and Inventory

The first-person character performs a sphere sweep from the camera when the interact action is triggered. If the trace finds a collectible, the item's name is added to the character's inventory and the world actor is removed.

When the player interacts with a lock, the game checks the inventory for the required item name. A matching item can be placed into the lock to activate its connected mover and can later be removed and returned to the inventory.

### Mover Component

`UMover` is a reusable actor component that moves its owning actor between an initial position and a configurable target offset.

It supports:

- An editor-configurable movement offset
- An adjustable movement duration
- Frame-rate-independent movement using delta time
- Constant-speed interpolation with `FMath::VInterpConstantTo`
- Reversible movement through a simple active/inactive state

The component can be attached to doors, platforms, walls, or other actors that need puzzle-controlled movement.

### Trigger and Pressure Plate Component

`UTriggerComponent` extends Unreal's box component and can act as a pressure plate. It watches for overlapping actors tagged `PressurePlateActivator` and controls a `UMover` on a referenced actor.

An overlap counter allows multiple valid actors to occupy the trigger without closing or resetting the connected mover until the last activator leaves.

### Locks and Keys

`ALock` connects the interaction, inventory, and movement systems. Each lock has an editable required key name, a mesh representing the inserted item, and a trigger component linked to the actor that should move.

## Project Structure

```text
FindTheLight/
├── Config/                         # Engine, game, collision, and input settings
├── Source/
│   ├── FindTheLight/               # Main runtime module
│   │   ├── FindTheLightCharacter.* # First-person controls and interaction
│   │   ├── CollectableItem.*       # Collectible item actor
│   │   ├── Lock.*                  # Key-operated lock actor
│   │   ├── Mover.*                 # Reusable moving-actor component
│   │   ├── TriggerComponent.*      # Pressure plate and overlap logic
│   │   ├── Variant_Horror/         # Horror template character and UI code
│   │   └── Variant_Shooter/        # Shooter template, weapons, AI, and UI code
│   └── FindTheLight.Target.cs
└── FindTheLight.uproject
```

## Requirements

- Unreal Engine 5.7
- Visual Studio 2022 with the **Game development with C++** workload
- Windows 10 or 11

## Opening the Project

1. Clone or download the repository.
2. Make sure the project's `Content/` directory is present. The source-only archive does not include Unreal assets, maps, Blueprints, or Enhanced Input assets.
3. Right-click `FindTheLight.uproject` and select **Generate Visual Studio project files**.
4. Open the generated solution in Visual Studio 2022.
5. Select the **Development Editor** configuration and **Win64** platform, then build the `FindTheLight` target.
6. Open `FindTheLight.uproject` in Unreal Engine 5.7.
7. Allow Unreal Engine to rebuild project modules if prompted.

## Editor Setup Notes

The gameplay code expects several references and conventions to be configured in Unreal Editor:

- Assign the character's Enhanced Input actions, including the interact action.
- Set collectible actors' `itemName` values.
- Set each lock's `keyItemName` to the exact matching collectible name.
- Assign a mover actor to the relevant trigger component.
- Add a `UMover` component to every actor controlled by a lock or pressure plate.
- Enable `isPressurePlate` for triggers that should react to overlaps.
- Tag valid pressure-plate objects with `PressurePlateActivator`.
- Ensure interactable collision blocks the custom `Interact` trace channel.

## Technologies and Concepts

- Unreal Engine 5.7
- C++
- Enhanced Input
- Actor and scene components
- Collision channels and sphere sweeps
- Overlap events and actor tags
- Delta-time-based interpolation
- C++ and Blueprint integration
- StateTree and Unreal AI modules
