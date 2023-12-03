Thuật toán trên không đảm bảo cho kết quả là một thứ tự tô pô vì nó chỉ đánh dấu mỗi đỉnh theo khoảng cách tăng dần tới
đỉnh nguồn của nó, mà không quan tâm đến các đỉnh kề của nó. Do đó, nếu có các đỉnh kề cùng khoảng cách tới đỉnh nguồn,
thứ tự tô pô của chúng có thể bị đảo lộn.

Ví dụ, giả sử chúng ta có đồ thị sau:

```
  A - B
 /     |
D - C - E
```

Nếu chúng ta chạy thuật toán BFS từ đỉnh A, ta sẽ đánh dấu các đỉnh theo thứ tự A -> D -> B -> C -> E. Tuy nhiên, nếu ta
muốn tô pô các đỉnh theo thứ tự từ trái sang phải, từ trên xuống dưới, ta cần phải tô pô các đỉnh theo thứ tự A -> D ->
C -> B -> E.

Do đó, để đảm bảo cho kết quả là một thứ tự tô pô, chúng ta cần phải sử dụng thuật toán khác, chẳng hạn như thuật toán DFS
hoặc thuật toán tô pô mà chúng ta đã học trước đó.
