#include "NetworkClient.h"
#include <iostream>

int main() {
    NetworkClient client("127.0.0.1", 9000);
    if (!client.connect()) {
        std::cerr << "Failed to connect to UAV" << std::endl;
        return 1;
    }

    // Example command frame
    std::string frame = "CMD_TAKEOFF";
    if (!client.sendFrame(frame)) {
        std::cerr << "Failed to send frame" << std::endl;
    }

    client.disconnect();
    return 0;
}
