#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "SerialPortControl_stream.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************
500 000 tick per sec by experiment...>>
*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	ros::init(boost::unit_test::framework::master_test_suite().argc, boost::unit_test::framework::master_test_suite().argv, "timer");
	ros::NodeHandle n("~");
	std::string str("no");

	
	SerialPortControl spaa(9600,n);
	std::cout << "ENCODER ERESOL " <<spaa.readEncoderResolution() << std::endl;
	spaa.writeHome();
	std::string y;
	while(1){
		std::cout<<"Debut"<<std::endl;
		//std::cin >> str;
		std::cin >> y;
		if(strcmp("vitesse", str.c_str())== 0){
			spaa.readRealSRW();
		}
		else if(y=="yo"){
			std::cout << "we areeeeee at "<<spaa.readLencoder()<<std::endl;
		}
		else{		
			//str=str+"\n";
			//spaa.writePoseRelativeL(y);
			//spaa.writeMove();
			//spaa.readLencoder();
			y=y+"\n";
			spaa.writePort(y);
		}
		//std::cout<<"endddd "<<spaa.readRealSLW()<<std::endl;
	}

}
