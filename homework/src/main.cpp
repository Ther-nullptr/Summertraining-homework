#include <iostream>
#include <fstream>
#include <vector>
#include <google/protobuf/message.h> // for protobuf

#include "../include/player.pb.h" // for protobuf source file

int main()
{
    // TODO 2: initialize the object of student
    player::Player player1;
    player1.set_life(10000);
    player1.set_nickname("Alice");
    player1.set_job(player::SHOOTER);
    player::Prop* props1=player1.add_props();
    props1->set_cd(1000);
    props1->set_name("SuperFast");
    player::Prop* props2=player1.add_props();
    props2->set_cd(10);
    props2->set_name("NuclearWeapon");
    // see the debug string
    std::cout << player1.DebugString() << std::endl;

    // serialize to file
    std::cout << "serialize to file." << std::endl;
    std::fstream output("./output.bin", std::ios::out | std::ios::binary );
    player1.SerializeToOstream(&output); 

}