Để chứng minh rằng có tất cả 2 đồ thị V đỉnh có hướng không chứa cạnh song song, chúng ta có thể sử dụng phương pháp đếm cấu
hình.

Trong một đồ thị có hướng, mỗi cặp đỉnh (u, v) có thể có một trong hai trường hợp: có một cạnh từ u đến v, hoặc không có cạnh
từ u đến v. Vì vậy, với V đỉnh, có tổng cộng 2^(V*(V-1)) cách để chọn các cạnh.

Tuy nhiên, để đồ thị không chứa cạnh song song, chúng ta cần chắc chắn rằng không có cặp cạnh nào có cùng đỉnh đầu và đỉnh
cuối. Điều này có nghĩa là chúng ta chỉ có thể chọn một trong hai hướng của mỗi cạnh, nghĩa là chúng ta chỉ có 2^E cách để
chọn các cạnh mà không có cạnh song song.

Vì vậy, tổng số đồ thị có hướng không chứa cạnh song song là 2^(V*(V-1))/2^E.

Để chứng minh rằng có tất cả 2 đồ thị V đỉnh có hướng không chứa cạnh song song, chúng ta có thể sử dụng biện luận trên để
chứng minh rằng tổng số cách chọn cạnh mà không có cạnh song song là 2^(V*(V-1))/2^E, và do đó có tất cả 2 đồ thị V đỉnh có
hướng không chứa cạnh song song.
