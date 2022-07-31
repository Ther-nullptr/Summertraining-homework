#include <iostream>
#include <fstream>
#include <vector>
#include <google/protobuf/message.h> // for protobuf

#include "../include/player.pb.h" // for protobuf source file

int main()
{
    // TODO 2: initialize the object of student
    player::Player player1;
    
    // Initialize player Alice
    player1.set_life(10000);
    player1.set_nickname("Alice");
    player1.set_job(player::Job::SHOOTER);

    // Props
    auto prop1{player1.add_props()};
    prop1->set_cd(1000);
    prop1->set_name("SuperFast");
    auto prop2{player1.add_props()};
    prop2->set_cd(10);
    prop2->set_name("NuclearWeapon");
    
    // see the debug string
    std::cout << player1.DebugString() << std::endl;

    // serialize to file
    std::cout << "serialize to file." << std::endl;
    std::fstream output("./output.bin", std::ios::out | std::ios::binary );
    player1.SerializeToOstream(&output); 

}
