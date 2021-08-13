**Để build được solution của TestGUIServer và TestGUIClient, cần phải cài và include thư viện của cURL và JSON library vào chương trình:
*Cài đặt thư viện JSON:
1. Copy folder single_include (trong file nộp) bỏ vào ổ đĩa C.
2. Trong solution TestGUIServer, dán #include</single_include/nlohmann/json.hpp> vào file Search.cpp
(Trong trường hợp, project build bị lỗi, cần phải sửa đường dẫn 1 chút)

*Cài đặt thư viện cURL: Thư viện đã được cài sẵn ở trong folder nộp, không cần phải cài đặt gì thêm
