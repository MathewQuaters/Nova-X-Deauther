<h1 align="center">
  <br>
  <a href="https://github.com/MathewQuaters/Nova-X-Deauther"><img src="https://github.com/MathewQuaters/Nova-X-Deauther/blob/main/img/frontera-development.png" width="200"></a>
  <br>
</h1>

Original repository can be found [here](https://github.com/warwick320/Nova-X-5G-Deauther).

Công cụ kiểm tra bảo mật WiFi và quảng cáo BLE được thiết kế dành cho nền tảng ESP32C5 với hỗ trợ màn hình OLED U8g2.

> Phần mềm đang trong thử nghiệm beta.

## Bảng nội dung

- [Liên hệ & Khắc phục sự cố](#liên-hệ--khắc-phục-sự-cố)
- [Tính Năng](#tính-năng)
- [Yêu cầu phần cứng](#yêu-cầu-phần-cứng)
- [Cấu hình các chân IO](#cấu-hình-các-chân-io)
- [Yêu cầu phần mềm](#yêu-cầu-phần-mềm)
- [Cài đặt](#cài-đặt)
- [Cách sử dụng](#cách-sử-dụng)
- [Hệ thống Menu](#hệ-thống-menu)
- [Chi tiết kỹ thuật](#chi-tiết-kỹ-thuật)
- [Tuyên bố miễn trừ trách nhiệm pháp lý](#tuyên-bố-miễn-trừ-trách-nhiệmm-pháp-lý)
- [Giấy phép](#giấy-phép)

## Liên hệ & Khắc phục sự cố

- **Vấn đề & Khắc phục sự cố**: [Máy chủ Discord Nova-X](https://discord.gg/gvzkwguAkh)


## Tính năng

### Kiểm tra bảo mật WiFi 
**Tấn công hủy xác thực**
- Chế độ Tất Cả Điểm Truy Cập
- Nhắm vào kênh cụ thể
- Nhắm vào điểm truy cập cụ thể
- Nhắm vào STA cụ thể

**Tràn Xác thực**
- Truyền phát khung xác thực hàng loạt
- Tấn công xác thực theo kênh
- Tấn công xác thực có chọn lọc

**Tràn ASC**
- Tấn công tràn bằng yêu cầu ASC
- Tấn công ASC theo kênh
- Chèn khung ASC theo mục tiêu

**Thao tác khung tín hiệu**
- Nhân bản tất cả SSID
- Nhân bản SSID đã chọn
- Tạo SSID ngẫu nhiên
- Tràn Khung tín hiệu theo kênh
- Tùy chỉnh Tràn tiền tố khung tín hiệu

**AP Spoofing**
- Tràn khung tín hiệu đa kênh
- Lan truyền SSID được nhân bản
- Chèn phản hồi probe
- Hủy xác thực định kì (trong 10s)

> Nhân bản thông tin điểm truy cập (SSID/BSSID) và phát tín hiệu trên tất cả các kênh, khiến các máy khách không thể xác định điểm truy cập thực. 


**Theo dõi gói tin**
- Tựu động chuyển kênh giữa 2 băng tần 2.4Ghz ~ 5Ghz
- Tỉ lệ truyền tải gói dữ liệu bằng biểu đồ


### BLE Advertisement Spoofing

- Hỗ trợ giả lập thiết bị iOS
- Hỗ trợ giả lập thiết bị Samsung

### Giao diện

- Màn hình OLED SSD1306 (128x64)
- Hệ thống điều hướng 4 nút

### Quét mạng

**Hỗ trợ WiFi băng tần kép**
- 2.4GHz:  Kênh 1-14
- 5GHz:  Kênh 36-165
- Thuật toán quét liên tục
- Đo lường RSSI
- Lập bản đồ kênh
- Phát hiện mã hóa
## Yêu cầu phần cứng

### Vi điều khiển
- Mô-đun ESP32C5

### Màn hình
- SSD1306 OLED (Độ phân giải 128x64)
- Giao tiếp I2C

### Nút bấm
- 4 nút nhấn nhả
## Cấu hình các chân IO

```cpp
// I2C Display Pins
I2C_SDA = GPIO 26
I2C_SCL = GPIO 25

// Button Pins
BTN_UP   = GPIO 24
BTN_DOWN = GPIO 23
BTN_OK   = GPIO 28
BTN_BACK = GPIO 10

// OLED Reset
OLED_RESET = -1 (not used)
```

### Sơ đồ nối dây

```
ESP32C5          SSD1306 OLED
GPIO 26  ------>  SDA
GPIO 25  ------>  SCL
3.3V     ------>  VCC
GND      ------>  GND

ESP32C5            Nút bấm
GPIO 24  ------>  Nút LÊN       ----> GND
GPIO 23  ------>  Nút XUỐNG     ----> GND
GPIO 28  ------>  Nút OK        ----> GND
GPIO 10  ------>  Nút QUAY LẠI  ----> GND
```

## Yêu cầu phần mềm

### Yêu cầu thư viện

```cpp
// Các thư viện lõi
- U8g2lib              // Driver màn hình OLED
- NimBLE-Arduino       // Bluetooth LE
- WiFi                 // Thư viện WiFi ESP32
- esp_wifi             // Chức năng WiFi cấp thấp

// Thư viện tiêu chuẩn
- Arduino.h
- Wire.h (I2C)
- vector (STL)
- string (STL)
- map (STL)
```

### Cài đặt thư viện

**Cách 1: Qua Arduino Library Manager**
```
Tools > Manage Libraries
Search:  "U8g2"        Install:  U8g2 by oliver
Search: "NimBLE"      Install: NimBLE-Arduino by h2zero
```

**Cách 2: Cài Đặt Thủ Công**
```bash
cd ~/Arduino/libraries/
git clone https://github.com/olikraus/u8g2.git
git clone https://github.com/h2zero/NimBLE-Arduino.git
```

## Cài đặt

### Bước 1: Thiết Lập Mạch (Nếu bạn thay đổi sketch)

1. Mở Arduino IDE
2. Đi tới `File > Preferences`
3. Thêm URL mạch ESP32 vào Additional Board Manager URLs: 
```
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```
4. Mở `Tools > Board > Board Manager`
5. Tìm "esp32" và cài đặt "esp32 by Espressif Systems"
6. Chọn `Tools > Board > ESP32 Arduino > ESP32C5 Dev Module`

### Bước 2: Tải Lên Sketch

### Cách 1 - Tải Lên Bằng Image Uploader (Khuyến Khích)

1. Tải Image Uploader mới nhất từ [trang phát hành của wardwick](https://github.com/warwick320/Nova-X-5G-Deauther/releases/tag/image_uploader)
2. Mở Image Uploader
3. Chọn cổng COM đã kết nối với ESP32C5
4. Nhấn Upload

### Cách 2 - Tải Lên Qua Sketch

> Trước khi bạn tải lên, bạn cần phải vá bộ soạn ESP32 - [Bộ vá](https://github.com/7h30th3r0n3/Evil-M5Project/tree/main/utilities/deauth_prerequisites) - Ví dụ: [platform.txt](https://github.com/7h30th3r0n3/Evil-M5Project/blob/main/utilities/deauth_prerequisites/plateform.txt)

1. Mở `nova-x-esp32c5/nova-x-esp32c5.ino`
2. Cài đặt các thông số mạch:
   - Board: ESP32C5 Dev Module
   - Upload Speed: 115200
   - Flash Frequency:  80MHz
   - Flash Mode: QIO
   - Partition Scheme:  Huge APP (3MB No OTA/1MB SPIFFS)
3. Chọn đúng cổng COM
4. Nhấn Upload

### Bước 3: Theo Dõi Nhật Ký Serial
```
Tools > Serial Monitor
Baud Rate: 115200
```


## Cách sử dụng

### Điều Hướng

- **Nút UP**: Đưa vùng chọn lên trên
- **Nút DOWN**: Đưa vùng chọn xuống dưới
- **Nút OK**:  Xác nhận lựa chọn / Bắt đầu hành động
- **Nút BACK**: Quay lại menu trước đó / Dừng hành động

### Workflow Cơ Bản

**1. Quét mạng**
```
Main Menu > Scan
```

**2. Chọn mục tiêu**
```
Main Menu > Settings > Select APs
```

**3. Thực hiện tấn công**
```
Main Menu > Exploit > [Attack Type] > [Mode]
```

## Hệ thống Menu

```
Nova-X ESP32C5
│
├── Exploit
│   ├── Deauth
│   │   │  
│   │   ├── APs
│   │   │   ├── All APs
│   │   │   ├── Channel
│   │   │   └── Selected
│   │   └── STAs
│   │        └── Selected
│   │
│   ├── Auth
│   │   ├── All APs
│   │   ├── Channel
│   │   └── Selected
│   │
│   ├── Assoc
│   │   ├── All APs
│   │   ├── Channel
│   │   └── Selected
│   │
│   ├── Beacon
│   │   ├── All SSIDs Dupe
│   │   ├── Selected Dupe
│   │   ├── Random
|   |   ├── Channel
│   │   └── Prefix
│   │
│   ├── AP Spoofing
│   │   └── Selected
│   │
│   └── B. T Adv
│       ├── Samsung
│       └── IOS
│
├── Scan
│
├── Packet Monitor
|
├── Settings
│   ├── Select APs
│   └── Select STAs
│
└── About
```

## Thông tin kĩ thuật

### Cấu trúc khung WiFi

**Khung Hủy xác thực (26 bytes)**
```cpp
Frame Control:     0xC0 0x00
Duration:          0x3A 0x01
Destination MAC:   FF:FF:FF:FF:FF:FF (broadcast or Selected STA Mac)
Source MAC:        [Target AP BSSID]
BSSID:             [Target AP BSSID]
Sequence:          0x00 0x00
Reason Code:       0x07 0x00
```

**Khung xác thực**
```cpp
Frame Control:     0xB0 0x00
Algorithm:         0x00 0x00 (Open System)
Sequence Number:   0x01 0x00
Status Code:       0x00 0x00
```

**Khung Yêu cầu ASC**
```cpp
Frame Control:     0x00 0x00
Capability Info:   0x21 0x04
Listen Interval:   0x0A 0x00
Tagged Parameters:  SSID, Supported Rates
```

**Khung tín hiệu**
```cpp
Frame Control:     0x80 0x00
Fixed Parameters: 
  - Timestamp
  - Beacon Interval:  0xE8 0x03
  - Capability Info:  0x21 0x00
Tagged Parameters: SSID, Rates, Channel
```

**Khung Phản hồi Probe**
```cpp
Frame Control:     0x50 0x00
Fixed Parameters:
  - Timestamp
  - Beacon Interval:  0xE8 0x03
  - Capability Info:  0x21 0x00
Tagged Parameters: SSID, Rates, Channel
Destination:        Client MAC
```

### Cấu hình kênh

**Băng tần 2.4GHz (14 kênh)**
```cpp
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
```

**Băng tần 5GHz (23 kênh)**
```cpp
36, 40, 44, 48, 52, 56, 60, 64,
100, 104, 108, 112, 116, 124, 128,
132, 136, 140,
149, 153, 157, 161, 165
```

**Tổng: 37 kênh**

### Dữ liệu Quảng cáo BLE

**Cấu trúc thiết bị iOS (31 bytes)**
```cpp
Size:          0x1e
Type:         0xFF (Manufacturer Specific)
Company ID:   0x4C 0x00 (Apple Inc.)
Subtype:      0x07 0x19
Device Type:  [varies by device]
```

**Cấu trúc thiết bị Samsung (15 bytes)**
```cpp
Size:         0x0E
Type:         0xFF (Manufacturer Specific)
Company ID:   0x75 0x00 (Samsung Electronics)
Subtype:      0x01
Model:        [device-specific byte]
```

## Tuyên bố miễn trừ trách nhiệm pháp lý

**QUAN TRỌNG: ĐỌC TRƯỚC KHI DÙNG**

Công cụ này được thiết kế dành riêng cho: 
- Kiểm thử xâm nhập được ủy quyền
- Mục đích giáo dục trong môi trường được kiểm soát
- Quản trị mạng trên cơ sở hạ tầng thuộc sở hữu
- Nghiên cứu an ninh với sự ủy quyền thích hợp

**Cảnh báo pháp lý**

Việc sử dụng phần mềm này trái phép có thể vi phạm pháp luật, bao gồm nhưng không giới hạn ở: 

- **Hợp Chủng Quốc Hoa Kỳ**: `"Computer Fraud and Abuse Act (CFAA), Federal Communications Act"` - Đạo luật chống gian lận và lạm dụng máy tính, Đạo luật truyền thông liên bang
- **Liên minh Châu Âu**: `"GDPR, Computer Misuse Act, national telecommunications laws"` - GDPR, Đạo luật chống lạm dụng máy tính, luật viễn thông quốc gia
- **Quốc Tế**: `"Local wireless communication regulations and computer crime statutes"` - Các quy định về truyền thông không dây trong nước và luật về tội phạm máy tính

Tấn công hũy xác thực WiFi, tràn ASC, và can thiệp mạng trái phép là **phạm pháp** ở hầu hết các khu vực pháp lý mà không có sự cho phép bằng văn bản rõ ràng từ chủ sở hữu mạng.

**Các hình phạt có thể bao gồm:**:
- Truy tố trách nhiệm hình sự
- Truy tố trách nhiệm dân sự
- Mức phạt nặng
- Giam giữ / Phạt tù / Cải tạo không giam giữ

**Trách nhiệm của người sử dụng**

Bằng việc sử dụng phần mềm này, bạn đã hiểu và xác nhận: 
1. Bạn có giấy ủy quyền bằng văn bản rõ ràng để kiểm tra các mục tiêu mạng
2. Bạn hiểu rõ các luật hiện hành tại vùng/quốc gia sở tại
3. Bạn chấp nhận toàn bộ tách nhiệm pháp lý đối với của nhành động của bản thân.
4. Tác giả (Tức Tôi - Mathew Quaters ; hay tác giả gốc - warwick320) **HOÀN TOÀN KHÔNG CHỊU TRÁCH NHIỆM PHÁP LÝ** đối với việc sử dụng sai mục đích dẫn đến hậu quả pháp lý.

**CHỈ SỬ DỤNG TRÊN MẠNG CỦA BẠN HOẶC MẠNG ĐÃ ĐƯỢC CẤP QUYỀN BẰNG VĂN BẢN.**

## Giấy phép

Dự án này được cấp phép theo **Giấy phép 2 điều BSD "Rút Gọn"**.

```
Copyright (c) 2024, warwick320
All rights reserved. 

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.
```

Xem tệp [LICENSE](https://github.com/MathewQuaters/Nova-X-Deauther/blob/main/LICENSE) để biết toàn bộ chi tiết.


---

*Hãy nhớ rằng: Quyền lực càng lớn, trách nhiệm đè lên càng nặng. Sử dụng công cụ này một cách có đạo đức và hợp pháp. -warwick320-*
