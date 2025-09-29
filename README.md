# baomat
BAI_TAP_1
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
Caesar
Affine
Hoán vị
Vigenère
Playfair

Với mỗi phương pháp, hãy tìm hiểu:
Tên gọi
Thuật toán mã hoá, thuật toán giải mã
Không gian khóa
Cách phá mã (mà không cần khoá)
Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

Thuật toán 1: Caesar.
Tên gọi:
Caesar cipher (mã Caesar) — một thuật toán mã hóa cổ điển đặt theo tên Julius Caesar. Nó là hình thức thay thế đơn giản: dịch mỗi chữ cái một số vị trí cố định trong bảng chữ cái.

Thuật toán mã hoá và giải mã:
Quy ước: ánh xạ chữ cái → số: a=0, b=1, ..., z=25. Khóa: số nguyên k (0..25).
Mã hoá: C=(P+k)mod26
Giải mã: P=(C−k+26)mod26

Không gian khóa:
Khóa k có 26 giá trị khả dĩ (0..25).
Kích thước không gian khóa = 26 (thực tế 25 khóa hữu dụng nếu bỏ k=0).
→ Rất nhỏ, dễ phá bằng brute-force.

Cách phá mã:
brute-force (thử 26) là đủ; phân tích tần suất giúp tự động hóa.
Code C++ và web ở trên cho phép bạn mã hoá/giải mã và thử brute-force; cả hai đều chuyển đầu vào về chữ thường trước xử lý.

Hình ảnh kiểm thử:
Mã Hóa
<img width="1347" height="1035" alt="image" src="https://github.com/user-attachments/assets/cfedf3b2-407d-424a-8dec-cdab138dd28e" />
Giải Mã
<img width="1449" height="1060" alt="image" src="https://github.com/user-attachments/assets/68c02e41-be74-4327-8622-42e3abb91978" />

Thuật toán 2: Affine
Tên gọi:
Affine cipher — mã Affine (một substitution cipher tuyến tính).

Thuật toán mã hoá & giải mã (ngắn gọn)
Quy ước: a=0, b=1, ..., z=25 (xử lý chữ thường).
Khóa gồm hai số nguyên: a và b.
Mã Hóa: c=(a⋅p+b)mod26
Giải Mã: cần nghịch đảo modular a^{-1} (mod 26), gọi là a_inv:
p=ainv​⋅(c−b)mod26

Không gian khóa
a phải nguyên tố cùng nhau với 26: các giá trị hợp lệ:
1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25 → 12 giá trị.

b có thể là 0..25 → 26 giá trị.
Tổng không gian khóa = 12 * 26 = 312 cặp (a,b).

Cách phá mã (không cần khóa) — ngắn gọn
Brute-force: thử hết 312 cặp (a,b) và kiểm tra kết quả (bằng mắt hoặc bằng dictionary) — nhanh.
Phân tích tần suất: giống substitution — nếu ciphertext đủ dài, map ký tự hay xuất hiện nhất về ký tự phổ biến → suy a,b.
Known-plaintext (crib): biết một đoạn plaintext → giải nhanh a,b.
Kết luận: Affine không an toàn cho ứng dụng thật vì không gian khóa nhỏ và có thể brute-force.

Hình ảnh kiểm thử:
Mã Hóa
<img width="1377" height="1072" alt="image" src="https://github.com/user-attachments/assets/8524d7fb-9665-4a0c-a29f-7cd7d240f07d" />
Giải Mã
<img width="1356" height="1053" alt="image" src="https://github.com/user-attachments/assets/5aa23bc3-314f-4ebb-a6f9-f252b77aaf3d" />

Thuật toán 3: Hoán vị
Tên gọi
Permutation cipher — mã hoán vị (thuộc nhóm transposition cipher).

Thuật toán mã hoá & giải mã
Ý tưởng: giữ nguyên ký tự nhưng đổi vị trí theo một khóa là hoán vị (ví dụ khóa độ dài n).
Chia văn bản gốc thành các khối (block) có độ dài n.
Với mỗi block:
Mã hoá: hoán đổi vị trí ký tự trong block theo thứ tự của khóa.
Giải mã: áp dụng hoán vị ngược để đưa ký tự về vị trí ban đầu.

Không gian khóa
Với độ dài block = n, số hoán vị = n!.

Cách phá mã (không cần khóa)
Brute-force: thử tất cả hoán vị có thể (nhỏ thì khả thi).
Phân tích mẫu từ: nhìn cấu trúc chữ (bigram, trigram).
Phân tích tần suất: vị trí xuất hiện lặp lại → đoán cấu trúc khối.

Hình ảnh kiểm thử:
Mã Hóa
<img width="1325" height="1063" alt="image" src="https://github.com/user-attachments/assets/e81156ba-5554-450d-aad5-891fd203fd5a" />
Giải Mã
<img width="1354" height="1068" alt="image" src="https://github.com/user-attachments/assets/b92a2347-9751-45a7-9624-391b6da44a5c" />

Thuật toán 4:Vigenère
Tên gọi
Mã hóa Vigenère (Vigenère Cipher) – thuật toán thay thế đa bảng (polyalphabetic substitution).

Thuật toán mã hóa và giải mã
Mã hóa: Ci​=(Pi​+Ki​)mod26 Giải mã: Pi​=(Ci​−Ki​+26)mod26

Không gian khóa
Khóa là chuỗi chữ cái độ dài tùy ý.

Nếu chỉ dùng bảng chữ cái 26 chữ: số lượng khóa là (26)^𝑚
với m = độ dài khóa.

Cách phá mã (không cần khóa)
Phân tích tần suất nâng cao: tìm độ dài khóa bằng phương pháp Kasiski hoặc chỉ số trùng hợp (IC – Index of Coincidence).
Sau đó coi mỗi cột như Caesar Cipher để phá.
Tuy an toàn hơn Caesar, nhưng vẫn phá được nếu văn bản đủ dài

Hình ảnh kiểm thử:
Mã Hóa
<img width="1332" height="1019" alt="image" src="https://github.com/user-attachments/assets/6510a145-7b66-4dc5-aa7a-8ccb47ae60da" />
Giải Mã
<img width="1361" height="1046" alt="image" src="https://github.com/user-attachments/assets/3038db92-774a-4f0c-a18d-9c5f90bfd43c" />

Thuật toán 5: Playfair
Tên gọi
Mã hóa Playfair (Playfair Cipher) – là một dạng mã hóa thay thế theo cặp ký tự (digraph substitution cipher).

Thuật toán mã hóa và giải mã
Bước 1: Tạo ma trận khóa 5×5 từ một từ khóa (loại bỏ trùng, gộp J = I).
Bước 2: Chia văn bản gốc thành từng cặp chữ cái (digraph). Nếu hai chữ cái giống nhau → chèn thêm ‘X’. Nếu còn dư một chữ cái → thêm ‘X’.
Bước 3: Quy tắc mã hóa:
Hai chữ cái cùng hàng → thay bằng chữ bên phải (vòng tròn sang trái nếu ở cuối).
Hai chữ cái cùng cột → thay bằng chữ bên dưới.
Khác hàng & cột → mỗi chữ thay bằng chữ ở góc còn lại cùng hàng.
Bước 4: Giải mã → làm ngược lại (trái thay phải, trên thay dưới).

Không gian khóa
Có 25! khả năng sắp xếp ma trận khóa (rất lớn).
Nhưng trên thực tế phụ thuộc vào độ dài và nội dung từ khóa.

Cách phá mã (không cần khóa)
Dùng phân tích tần suất cặp chữ (digraph frequency analysis).
Với đủ văn bản, có thể suy ra khóa vì tiếng Anh (hay tiếng Việt) có các cặp xuất hiện phổ biến.

Hình ảnh kiểm thử:
Mã Hóa
<img width="1404" height="1033" alt="image" src="https://github.com/user-attachments/assets/0da69a87-b030-4e68-a94c-191d951579d2" />
Giải mã
<img width="1379" height="1020" alt="image" src="https://github.com/user-attachments/assets/51bfd175-c826-42c6-8fca-582b12755ce7" />
