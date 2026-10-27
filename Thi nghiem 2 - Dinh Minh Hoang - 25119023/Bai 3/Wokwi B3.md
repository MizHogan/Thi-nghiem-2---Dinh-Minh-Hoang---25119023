
# Bài 3 - Đọc ADC, lọc nhiễu và điều khiển LED bằng PWM trên ESP32

## 1. Giới thiệu

Dự án sử dụng vi điều khiển ESP32 để đọc tín hiệu analog
thông qua bộ chuyển đổi ADC, xử lý dữ liệu bằng phương pháp
lọc trung bình trượt và điều khiển độ sáng LED bằng PWM.

Mạch được thiết kế và mô phỏng trên nền tảng Wokwi.

**Link mô phỏng:**  
https://wokwi.com/projects/479070295841494017

## 2. Mục tiêu

- Tìm hiểu cách đọc tín hiệu analog bằng ADC trên ESP32.
- Thực hành xử lý và giảm nhiễu tín hiệu đo.
- Tìm hiểu nguyên lý điều khiển độ sáng LED bằng PWM.
- Quan sát dữ liệu đầu vào và dữ liệu sau lọc trên Serial Monitor.
- Làm quen với việc mô phỏng và kiểm thử mạch điện trên Wokwi.

## 3. Phần cứng và môi trường

### Phần cứng mô phỏng

- ESP32 DevKit-C V4
- LED điều khiển độ sáng
- Nguồn tín hiệu analog theo sơ đồ mạch
- Các dây nối và linh kiện phụ trợ theo sơ đồ Wokwi

### Phần mềm

- Wokwi ESP32 Simulator
- Arduino framework
- Serial Monitor

## 4. Cấu hình chân GPIO

| Chức năng | Chân ESP32 |
|---|---|
| Đọc tín hiệu ADC | GPIO 34 |
| Điều khiển LED bằng PWM | GPIO 18 |
| Giao tiếp Serial | 115200 baud |

## 5. Nguyên lý hoạt động

### 5.1. Đọc tín hiệu ADC

ESP32 đọc giá trị analog tại GPIO 34 bằng hàm
`analogRead()`.

Với cấu hình đọc mặc định trong chương trình, giá trị ADC
được xử lý theo thang đo từ 0 đến 4095.

### 5.2. Lọc nhiễu bằng trung bình trượt

Chương trình lưu 8 mẫu gần nhất vào một bộ đệm vòng.
Sau mỗi lần đọc, giá trị trung bình của 8 mẫu được tính
để giảm sự biến động của tín hiệu đầu vào.

Công thức:

Giá trị lọc = Tổng 8 mẫu / 8

### 5.3. Điều khiển độ sáng LED bằng PWM

Giá trị ADC sau lọc được ánh xạ từ khoảng 0–4095 sang
khoảng giá trị PWM 0–255 bằng hàm `map()`.

Chương trình sử dụng PWM với:
- Tần số: 5000 Hz
- Độ phân giải: 8 bit
- Giá trị duty cycle: 0–255

Khi giá trị ADC sau lọc tăng, độ sáng LED tăng theo.
Khi giá trị ADC giảm, độ sáng LED giảm theo.

## 6. Quy trình hoạt động

1. Khởi tạo giao tiếp Serial ở tốc độ 115200 baud.
2. Thiết lập PWM cho GPIO 18.
3. Khởi tạo bộ đệm lọc gồm 8 mẫu.
4. Đọc giá trị ADC tại GPIO 34.
5. Đưa dữ liệu vào bộ lọc trung bình trượt.
6. Chuyển giá trị đã lọc thành giá trị PWM.
7. Cập nhật độ sáng LED.
8. In dữ liệu ADC thô và dữ liệu sau lọc ra Serial Monitor.
9. Lặp lại chu trình sau mỗi 20 ms.

## 7. Hướng dẫn mô phỏng

1. Truy cập link dự án Wokwi ở phần Giới thiệu.
2. Nhấn nút Start Simulation để chạy mô phỏng.
3. Mở Serial Monitor để theo dõi dữ liệu.
4. Thay đổi tín hiệu analog đầu vào theo sơ đồ mạch.
5. Quan sát sự thay đổi của giá trị ADC thô, giá trị sau lọc
   và độ sáng LED.

## 8. Kết quả mong đợi

- ESP32 đọc được tín hiệu analog đầu vào.
- Giá trị sau lọc ít biến động hơn so với tín hiệu thô
  khi đầu vào có nhiễu.
- Độ sáng LED thay đổi theo giá trị ADC sau lọc.
- Serial Monitor hiển thị dữ liệu phục vụ việc theo dõi
  và đánh giá hoạt động của chương trình.

## 9. Kết luận

Dự án minh họa quy trình thu nhận tín hiệu analog,
xử lý dữ liệu bằng bộ lọc trung bình trượt và điều khiển
thiết bị đầu ra thông qua PWM trên ESP32.

Qua mô phỏng, người thực hiện có thể tìm hiểu mối liên hệ
giữa tín hiệu đầu vào, thuật toán xử lý và tín hiệu điều khiển
đầu ra trong một hệ thống nhúng cơ bản.

## 10. Tài liệu tham khảo

- Dự án mô phỏng Wokwi:
  https://wokwi.com/projects/479070295841494017
- Tài liệu mô phỏng ESP32 trên Wokwi:
  https://docs.wokwi.com/guides/esp32

