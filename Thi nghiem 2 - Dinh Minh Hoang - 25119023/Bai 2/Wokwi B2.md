
# Bài 2 - Chống dội nút nhấn trên ESP32

## 1. Giới thiệu

Dự án mô phỏng hệ thống đọc nút nhấn trên ESP32,
sử dụng ngắt ngoài và thuật toán chống dội (debounce)
để phân biệt tín hiệu chuyển mức thô với các lần nhấn
được chấp nhận sau khi lọc.

**Link mô phỏng Wokwi:**
https://wokwi.com/projects/479067237009381377

## 2. Mục tiêu

- Tìm hiểu ngắt ngoài trên ESP32.
- Hiểu hiện tượng dội tiếp điểm của nút nhấn.
- Thực hành lọc tín hiệu nút nhấn bằng khoảng thời gian debounce.
- Theo dõi số lần kích hoạt qua Serial Monitor.

## 3. Phần cứng

- ESP32 DevKit-C V4
- Nút nhấn
- Dây nối theo sơ đồ mạch trên Wokwi

## 4. Cấu hình

| Thông số | Giá trị |
|---|---|
| Chân nút nhấn | GPIO 4 |
| Chế độ chân | INPUT_PULLUP |
| Thời gian chống dội | 50 ms |
| Tốc độ Serial | 115200 baud |
| Cạnh kích hoạt ngắt | FALLING |

## 5. Nguyên lý hoạt động

Nút nhấn được cấu hình ở chế độ INPUT_PULLUP.
Khi nhấn nút, tín hiệu tại GPIO 4 chuyển từ HIGH
sang LOW và tạo cạnh xuống (FALLING).

Hàm xử lý ngắt ghi nhận cạnh xuống thô và kiểm tra
khoảng thời gian kể từ lần nhấn hợp lệ gần nhất.
Nếu khoảng thời gian đạt ít nhất 50 ms, chương trình
chấp nhận sự kiện và tăng bộ đếm số lần nhấn hợp lệ.

## 6. Dữ liệu hiển thị

Serial Monitor hiển thị:

- Số cạnh xuống thô (raw): số sự kiện cạnh xuống
  được ghi nhận bởi trình xử lý ngắt.
- Số lần nhấn đã lọc (debounced): số sự kiện được
  chấp nhận sau khi kiểm tra thời gian chống dội.

Hai giá trị giúp quan sát ảnh hưởng của hiện tượng
dội tiếp điểm lên tín hiệu nút nhấn.

## 7. Hướng dẫn mô phỏng

1. Mở dự án Wokwi bằng liên kết ở phần Giới thiệu.
2. Nhấn Start Simulation.
3. Mở Serial Monitor.
4. Nhấn nút và quan sát các bộ đếm.
5. So sánh số cạnh xuống thô với số lần nhấn đã lọc.

## 8. Kết quả mong đợi

Chương trình ghi nhận tín hiệu nút nhấn qua ngắt,
áp dụng khoảng thời gian chống dội 50 ms và hiển thị
thống kê trên Serial Monitor.

Lưu ý: Bộ lọc thời gian đơn giản có thể không loại bỏ
hoàn toàn mọi dạng dội tiếp điểm trong mọi điều kiện.

## 9. Tài liệu tham khảo

- [Dự án mô phỏng Wokwi](https://wokwi.com/projects/479067237009381377)
- [Tài liệu ESP32 trên Wokwi](https://docs.wokwi.com/guides/esp32)
