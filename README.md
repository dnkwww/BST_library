# BST_library
 
111上資料結構HW2

[作業說明網頁](https://hackmd.io/@chtsai/SyumZ-XXj)

---

建構一個 Binary Search Tree (BST) 的 library.

函式庫使用說明書.pdf的執行結果指令未分類檔案，在CMD打開根目錄打以下指令執行即可：

```
gcc -c -I./include ./src/BST.c -o ./obj/BST.o

ar -cr ./lib/libBST.a ./obj/BST.o

gcc -I./include ./src/main.c ./lib/libBST.a -o ./bin/test.exe

cd bin
test.exe
```
