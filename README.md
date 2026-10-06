# Robot Types - Strategy Design Pattern (Low-Level Design)

A clean Low-Level Design (LLD) demonstration of the **Strategy Design Pattern** in C++, emphasizing **Composition over Inheritance**.

## 📌 Core Problem & Motivation
In standard Object-Oriented Design, attempting to represent complex combinations of behaviors through class inheritance leads to **class explosion** (e.g. `WalkTalkNoFlyRobot`, `NoWalkTalkFlyRobot`, etc.).

By using the **Strategy Pattern**:
- Behaviors (`WalkableRobot`, `TalkableRobot`, `FlyableRobot`) are encapsulated into distinct strategy interfaces.
- The base `Robot` class composes these behaviors (**HAS-A relationship**) rather than inheriting them.
- New behaviors and robot types can be added without modifying existing code (Open/Closed Principle).

---

## 🏗️ Architecture

```mermaid
classDiagram
    class Robot {
        <<abstract>>
        #WalkableRobot* walkBehavior
        #TalkableRobot* talkBehavior
        #FlyableRobot* flyBehavior
        +walk() void
        +talk() void
        +fly() void
        +projection()* void
    }

    class CompanionRobot {
        +projection() void
    }

    class TalkableRobot {
        <<interface>>
        +talk()* void
    }
    class NormalTalk {
        +talk() void
    }
    class NoTalk {
        +talk() void
    }

    class WalkableRobot {
        <<interface>>
        +walk()* void
    }
    class NormalWalk {
        +walk() void
    }
    class NoWalk {
        +walk() void
    }

    class FlyableRobot {
        <<interface>>
        +fly()* void
    }
    class NormalFly {
        +fly() void
    }
    class NoFly {
        +fly() void
    }

    Robot <|-- CompanionRobot : Inheritance (IS-A)
    Robot o--> TalkableRobot : Composition (HAS-A)
    Robot o--> WalkableRobot : Composition (HAS-A)
    Robot o--> FlyableRobot : Composition (HAS-A)

    TalkableRobot <|.. NormalTalk
    TalkableRobot <|.. NoTalk
    WalkableRobot <|.. NormalWalk
    WalkableRobot <|.. NoWalk
    FlyableRobot <|.. NormalFly
    FlyableRobot <|.. NoFly
```

---

## 🚀 How to Build and Run

### Prerequisites
- GCC / G++ (C++11 or higher)

### Compile & Execute
```bash
g++ -std=c++17 StrategyDesignPattern.cpp -o StrategyDesignPattern.exe
./StrategyDesignPattern.exe
```

### Expected Output
```text
Projecting hologram companion...
Walking normally...
Talking normally...
Cannot fly.
```
