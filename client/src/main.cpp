#include <protos/address.pb.h>
#include <protos/addressbook.grpc.pb.h>

#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>

#include <iostream>


int main(int argc, char* argv[])
{
    // Setup request
    dbproto::NameQuerry query;
    dbproto::Address result;
    query.set_name("John");

    // Call
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr<dbproto::AddressBook::Stub> stub = dbproto::AddressBook::NewStub(channel);
    grpc::ClientContext context;
    grpc::Status status = stub->GetAddress(&context, query, &result);

    // Output result
    std::cout << "I got:" << std::endl;
    std::cout << "Name: " << result.name() << std::endl;
    std::cout << "City: " << result.city() << std::endl;
    std::cout << "Zip:  " << result.zip() << std::endl;
    std::cout << "Street: " << result.street() << std::endl;
    std::cout << "Country: " << result.country() << std::endl;

    return 0;
}
