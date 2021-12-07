#include <iostream>

//Animal -> Pet
//Superclass -> Subclass
//Father -> Son
//Base -> Derived

class Animal {
    std::string type;
    bool alive {true};
public:
    Animal(std::string type = "bacteria"): type(type) {
        //std::cout << this->type << " created" << std::endl;
    }
    virtual ~Animal() {
        //std::cout << this->type << " destroyed" << std::endl;
    }
    //ligação tardia
    virtual bool isAlive() const {
        return alive;
    }
    virtual void die() {
        alive = false;
    }
    virtual std::string getType() const {
        return type;
    }
    friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
        os << animal.type << ":" << (animal.alive ? "alive" : "dead");
        return os;
    }
};

class Pet : public Animal {
    std::string name;
public:
    Pet(std::string name, std::string type): Animal(type), name(name) {
        //std::cout << this->name << " created" << std::endl;
    }
    virtual ~Pet() {
        //std::cout << this->name << " destroyed" << std::endl;
    }
    virtual void play() const {
        if (this->isAlive())
            std::cout << this->name << " playing" << std::endl;
        else
            std::cout << "RIP" << std::endl;
    }
    virtual std::string getName() const {
        return name;
    }
    friend std::ostream& operator<<(std::ostream& os, const Pet& pet) {
        const Animal& animal = pet;
        os << pet.name << ":" << animal;
        return os;
    }
};

class Cat : public Pet {
    int lives {9};
public:
    Cat(std::string name, int lives = 9): Pet(name, "cat"), lives(lives) {
    }
    ~Cat() {
    }
    virtual void meow() const {
        std::cout << this->getName() << " meowing" << std::endl;
    }
    virtual void die() {
        if (this->lives == 0) {
            std::cout << "already deal, please stop!\n";
        } else if (this->lives > 1) {
            this->lives--;
            std::cout << "still alive, try again\n";
        } else {
            this->lives--;
            std::cout << "RIP\n";
            this->Animal::die();
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat) {
        const Pet* pet = &cat;
        os << *pet << ":" << cat.lives;
        return os;
    }
};


int main() {
    Cat cat {"Chaninha", 3};
    Animal& animal = cat;
    animal.die();
    animal.die();
    animal.die();
    std::cout << animal << std::endl;

    // Cat cat("Chaninha", 2);
    // std::cout << cat << std::endl;
    // cat.play();
    // cat.meow();
    // cat.die();
    // cat.die();
    // cat.die();
    // cat.play();
    // std::cout << cat << std::endl;
}
