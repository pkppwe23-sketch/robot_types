#include <iostream>

using namespace std;

// ============================================================================
// 1. STRATEGY INTERFACES
// ============================================================================

class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

// ============================================================================
// 2. CONCRETE STRATEGIES FOR WALK
// ============================================================================

class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Walking normally..." << endl;
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Cannot walk." << endl;
    }
};

// ============================================================================
// 3. CONCRETE STRATEGIES FOR TALK
// ============================================================================

class NormalTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Talking normally..." << endl;
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Cannot talk." << endl;
    }
};

// ============================================================================
// 4. CONCRETE STRATEGIES FOR FLY
// ============================================================================

class NormalFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Flying normally..." << endl;
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Cannot fly." << endl;
    }
};

// ============================================================================
// 5. BASE CONTEXT CLASS (Robot) USING COMPOSITION
// ============================================================================

class Robot {
protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }

    void walk() {
        walkBehavior->walk();
    }

    void talk() {
        talkBehavior->talk();
    }

    void fly() {
        flyBehavior->fly();
    }

    virtual void projection() = 0; // Abstract method for subclasses
};

// ============================================================================
// 6. CONCRETE ROBOT SUBCLASS
// ============================================================================

class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Projecting hologram companion..." << endl;
    }
};

// ============================================================================
// 7. MAIN FUNCTION
// ============================================================================

int main() {
    // Composition in action: Injecting concrete strategy behaviors
    Robot* robot = new CompanionRobot(
        new NormalWalk(),
        new NormalTalk(),
        new NoFly()
    );

    robot->projection();
    robot->walk();
    robot->talk();
    robot->fly();

    return 0;
}
