# N-Queen

Chuong trinh doc so nguyen `N` tu tep `input.txt` va ghi tat ca cac cach dat
`N` quan hau len ban co `N x N` vao tep `output.txt`.

## Dinh dang

`input.txt`

```txt
N
```

`output.txt`

```txt
[[cot_hang_1, cot_hang_2, ...], ...]
```

Moi cach giai the hien vi tri cot cua quan hau trong tung hang, tinh tu hang
dau tien den hang cuoi cung. Cot duoc danh so tu `1`.

Vi du voi `N = 4`, ket qua la:

```txt
[[2, 4, 1, 3], [3, 1, 4, 2]]
```

## Bien dich va chay

```sh
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp -o nqueen
./nqueen
```

Tep `output.txt` duoc mo o che do binary de giu ky tu xuong dong LF tren
Windows.
