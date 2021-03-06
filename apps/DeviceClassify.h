//
// Created by Arunan Sivanathan on 1/3/18.
//

#ifndef SDN_SIM3_OF_DEV_CLASSIFIER_H
#define SDN_SIM3_OF_DEV_CLASSIFIER_H


#include <controller.h>

#include <vector>
#include <fstream>
#include <getopt.h>

class DeviceClassify : public Controller {
private:
    char* mac_file;

public:
    typedef std::vector<std::string> char_vec_t;

    DeviceClassify(int ctrloptc, char **ctrloptv);

    SwitchBox *getServiceSwitch() const override {
        return Controller::getServiceSwitch();
    }

    void pushInitialRules() override;

    ushort
    toController(pPcap::sim_pack *new_packet, struct pPcap::packet_meta *p_m) override;

    void mirroredTraffic(pPcap::sim_pack *new_packet, int opt) override;

    int readMacList(const char *filePath, char_vec_t *macList);

    void initiateDeviceIdentificationRules(const char *deviceMac, const char *gatewayMac);
};


#endif //SDN_SIM3_OF_DEV_CLASSIFIER_H
