Để tính thành phần liên thông mạnh chứa một đỉnh v cho trước, chúng ta có thể sử dụng thuật toán DFS (Depth First Search) để
duyệt đồ thị từ đỉnh v và đảm bảo rằng chúng ta đã duyệt hết tất cả các đỉnh thuộc cùng một thành phần liên thông mạnh. Sau
khi duyệt xong, tất cả các đỉnh đã được duyệt sẽ thuộc vào cùng một thành phần liên thông mạnh.

Dưới đây là mô tả của thuật toán:
1. Khởi tạo một mảng visited để đánh dấu các đỉnh đã được duyệt. Ban đầu, tất cả các đỉnh đều được đánh dấu là chưa duyệt.
2. Bắt đầu từ đỉnh v, chúng ta thực hiện thuật toán DFS để duyệt đồ thị. Khi duyệt một đỉnh u, chúng ta đánh dấu đỉnh u là đã
duyệt và tiếp tục duyệt các đỉnh kề của u chưa được duyệt.
3. Sau khi kết thúc quá trình duyệt DFS, tất cả các đỉnh thuộc cùng một thành phần liên thông mạnh với đỉnh v sẽ được đánh dấu
là đã duyệt trong mảng visited.

Để tính toán tất cả các thành phần liên thông mạnh của một đồ thị có hướng, chúng ta có thể sử dụng thuật toán DFS để duyệt qua
tất cả các đỉnh trong đồ thị. Khi duyệt một đỉnh chưa được duyệt, chúng ta sẽ thực hiện thuật toán DFS để duyệt tất cả các đỉnh
thuộc cùng một thành phần liên thông mạnh. Sau khi kết thúc quá trình duyệt DFS, chúng ta có thể tiếp tục duyệt các đỉnh chưa
được duyệt và lặp lại quá trình trên cho đến khi tất cả các đỉnh đều đã được duyệt.

Dưới đây là mô tả của thuật toán tính các thành phần liên thông mạnh của một đồ thị có hướng:
1. Khởi tạo một mảng visited để đánh dấu các đỉnh đã được duyệt. Ban đầu, tất cả các đỉnh đều được đánh dấu là chưa duyệt.
2. Duyệt qua tất cả các đỉnh trong đồ thị. Nếu đỉnh đó chưa được duyệt, thực hiện thuật toán DFS để duyệt tất cả các đỉnh thuộc
cùng một thành phần liên thông mạnh.
3. Sau khi kết thúc quá trình duyệt DFS, tiếp tục duyệt các đỉnh chưa được duyệt và lặp lại quá trình trên cho đến khi tất cả
các đỉnh đều đã được duyệt.
