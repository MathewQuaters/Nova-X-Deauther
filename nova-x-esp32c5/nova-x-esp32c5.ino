#include "globals.h"
#include "display.h"

nx::menu m;

std:: vector<menuItem> mainMenu = {
  menuItem("Tấn Công",nullptr,{
    menuItem("Hủy Xác Thực", nullptr, {
      menuItem("APs",nullptr,{
        menuItem("Tất Cả AP",[](){m.deauthAttack();},{}),
        menuItem("Kênh",[](){m.deauthByChannel();},{}),
        menuItem("Đã chọn",[](){m.deauthSelected();},{})
      }),
      menuItem("STA",nullptr,{
        menuItem("Đã chọn",[](){m.attackSelectedBySTAs();},{})
      })
    }),
    menuItem("Xác thực", nullptr, {
      menuItem("Tất Cả AP",[](){m.authAttack();},{}),
      menuItem("Kênh",[](){m.authByChannel();},{}),
      menuItem("Đã chọn",[](){m.authSelected();},{})
    }),
    menuItem("ASC", nullptr, {
      menuItem("Tất Cả AP",[](){m.assocAttack();},{}),
      menuItem("Kênh",[](){m.assocByChannel();},{}),
      menuItem("Đã chọn",[](){m.assocSelected();},{})
    }),
    menuItem("Beacon", nullptr, {
      menuItem("Nhân Bản SSID",[](){m.beaconAllSSID();},{}),    
      menuItem("Nhân Bản Đã Chọn",[](){m.beaconSSIDDupe();},{}),  
      menuItem("Ngẫu Nhiên",[](){m.beaconRandom();},{}),
      menuItem("Kênh",[](){m.beaconDupeByChannel();},{}),
      menuItem("Tiền Tố",[](){m.beaconCustomPrefix(prefix);},{})
    }),
    menuItem("AP Spoofing", nullptr, {
      menuItem("Đã chọn",[](){m.APSpoofing();},{})
    }),
    menuItem("Q.C. Bluetooth",nullptr,{
      menuItem("Samsung",[](){m.drawSamsungAdv();},{}),
      menuItem("IOS",[](){m.drawIosAdv();},{})
    })
  }),
  menuItem("Quét",nullptr,{
    menuItem("Điểm Truy Cập",[](){m.scanWiFi();},{}),
    menuItem("STA",[](){m.scanSTA();},{})
  }),
  menuItem("Theo Dõi Gói Tin",[](){m.drawPacketMonitor();},{}),
  menuItem("Settings",nullptr,{
    menuItem("Select APs",[](){m.drawSelectMenu();},{}),
    menuItem("Select STAs",[](){m.drawSelectMenuSTA();},{})
  }),
  menuItem("About",[](){m.drawAbout();},{}),
};

void setup(){
  Serial.begin(SERIAL_SPEED);
  Serial.println("[SERIAL] Started");
  Serial.println(F("=============================================================="));
  m.init();
  
}

void loop(){
  m.menuHandler(mainMenu,m.index);

}
