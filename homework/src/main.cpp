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
    player1.set_job(player::Job::SHOOTER);

    player::Prop* prop1 = player1.add_props();
    prop1->set_name("SuperFast");
    prop1->set_cd(1000);
    player::Prop* prop2 = player1.add_props();
    prop2->set_name("NuclearWeapon");
    prop2->set_cd(10);

    // see the debug string
    std::cout << player1.DebugString() << std::endl;
    std::cout << "----------------player info-----------------" << std::endl
                << "life: " << player1.life() << std::endl
                << "nickname: " << player1.nickname() << std::endl
                << "job (0:assassin, 1:shooter, 2:warrior): " << (int)player1.job() << std::endl
                << "props: " << std::endl;
    for(int i = 0;i<player1.props_size();i++)
    {
        std::cout << " " << i << ". "
                    << "cd: " << player1.props(i).cd() << " "
                    << "name: " << player1.props(i).name() << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    // serialize to file
    std::cout << "serialize to file." << std::endl;
    std::fstream output("./output.bin", std::ios::out | std::ios::binary );
    player1.SerializeToOstream(&output); 
    std::cout << "serialize to array." << std::endl;
    size_t size = player1.ByteSizeLong();
    unsigned char* data = new unsigned char [size];
    player1.SerializeToArray(data, player1.ByteSizeLong()); // 序列化为数组

}