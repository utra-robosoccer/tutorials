#include <iostream>
#include <exercises/practice1_data_structures.h>
#include <exercises/practice2_oop.h>
#include <exercises/practice3_lambda_functions.h>
#include <exercises/practice4_templates.h>
#include <exercises/practice5_memory.h>
#include <exercises/practice6_threading.h>

#include <ros/subscriber.h>
#include <ros/publisher.h>
#include <ros/ros.h>
#include <ros/message.h>

int main() {
    // Complete the exercises first, do all the ones you are not sure about. All of the exercises will be helpful for this project
    e6();
    return 0;
    // Final Project This is quite an advanced exercise, it should take about 8-16 hours depending on skill level. Work until you give up and discuss with partners

    // 1. Add a template T to the Message Class specifying the type of message you want the publisher and subscriber to transmit.

    // 2. Create the ROS data structure messages which is an unordered map between message names and shared_ptrs of message_bases

    Ros ros;

    // 3. Create a Publisher class, the publisher should be created via the function Publisher<Type> = ros.advertise<Type>("name_of_message");
    // This will add a new mapping between a message name and message base if it doesn't exist
    // This will return a Publisher class, which will contain a shared_ptr copy of the Message type
    Publisher<int> int_publisher = ros.advertise<int>("Int");

    // 3. Create a Subscriber class, the subscriber should be created via the function Subscriber<Type> = ros.subscribe<Type>("name_of_message");
    // This will add a new mapping between a message name and message base if it doesn't exist
    // This will return a Subscriber class, which will contain a shared_ptr copy of the Message type. Do this in the same way the publisher is made. Instead there is more
    // Add an extra argument in the ros.subscribe<int>("Int", [](){}) The second argument should be a pointer to a lambda function.
    // This lambda function should be stored in the message class, as part of a vector of lambda functions

    // 4. Create the publish function, this should search the unordered map between the message names and the shared pointer
    // Test the publish function to see if it calls the lambda functions

    // 5. Super Bonus create the threading loop, make the publishers and subscibers multithreaded and voila you are done ros
    while(true) {
//        int_publisher.publish();
    }

    // 6. Super fucking bonus: Implement networking, and you just made ros

    return 0;
}