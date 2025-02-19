## DSL

### 链表 
**WHAT?**
链表是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。 

**WHY?**

1. 动态内存分配：链表可以根据需要动态地分配和释放内存，不需要预先分配固定大小的内存空间。
2. 灵活的插入和删除：相比数组，链表的插入和删除操作更加高效（O(1)时间复杂度），不需要移动其他元素。
3. 空间利用率高：链表只需要为实际存储的数据分配空间，不会像数组那样可能存在空间浪费。
4. 易于扩展：链表可以轻松地通过添加新节点来扩展，不受固定大小的限制。
5. 适用场景：
   - 频繁进行插入和删除操作的场景
   - 无法预知数据量大小的场景
   - 需要动态扩容的场景
   - 实现其他数据结构（如栈、队列）的基础

**HOW?**
#### 1. 单链表
1. 创建一个节点类，包含数据和指向下一个节点的指针。
2. 创建一个链表类，包含头节点和尾节点的指针。
3. 在链表中添加节点时，需要找到正确的位置，然后插入新节点。
4. 删除节点时，需要找到要删除的节点，并将其前后节点的指针连接起来。
5. 查找节点时，需要遍历整个链表，直到找到目标节点。
**EXAMPLE**
```c++

```

#### 2. 双链表
1. 创建一个双链表结点类，包含数据、指向下一个节点的指针和指向前一个节点的指针。

   ![image-20250218161744949](/Users/lishundong/Library/Application Support/typora-user-images/image-20250218161744949.png)
```c++
template <typename T> class DoublyListNode {
public:
  T data;
  DoublyListNode *prev;
  DoublyListNode *next;
  explicit DoublyListNode(T val = T())
      : data(val), prev(nullptr), next(nullptr) {}
};
```
2. 创建一个双链表类，包含头节点和尾节点的指针。
```c++
template <typename T> class DoublyLinkedList {
public:
  DoublyLinkedList()
      : dummyHead(new DoublyListNode<T>()), dummyTail(new DoublyListNode<T>()),
        size(0) {
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
  }
  ~DoublyLinkedList() {}

private:
  DoublyListNode<T> *dummyHead;
  DoublyListNode<T> *dummyTail;
  size_t size;
};
```
3. 在双链表中添加节点时，需要找到正确的位置，然后插入新节点，并更新前后节点的指针。
```c++
  /** 尾插法
   * 1. 创建新结点
   * 2. dummyTail->prev 指向新结点
   * 3. newNode->prev 指向 dummyTail->prev
   * 4. newNode->next 指向 dummyTail
   * 5. dummyTail->prev->next 指向 newNode
   */
  void append(T val) { insert(dummyTail, val); }
  /** 头插法
   * 1. 创建新结点
   * 2. dummyHead->next 指向新结点
   * 3. 新结点的 prev 指向 dummyHead
   * 4. 新结点的 next 指向 原来的头结点
   * 5. 原来的头结点的 prev 指向 新结点
   */
  void prepend(T val) { insert(dummyHead->next, val); }

  // 指定位置插入
  void insert(size_t index, T val) {
    if (index < 0 || index > size) {
      throw std::runtime_error("index out of range");
    }
    DoublyListNode<T> *cur = dummyHead->next;
    for (size_t i = 0; i < index; ++i) {
      cur = cur->next;
    }
    insert(cur, val);
  }

  void insert(DoublyListNode<T> *pos, T val) {
    if (pos == nullptr || pos == dummyHead)
      return;
    // step 1-3
    DoublyListNode<T> *newNode = new DoublyListNode<T>(val);
    newNode->prev = pos->prev;
    pos->prev->next = newNode;
    newNode->next = pos;
    pos->prev = newNode;
    ++size;
  }
```
4. 删除节点时，需要找到要删除的节点，并将其前后节点的指针连接起来。
```c++
  void remove_front() { remove(dummyHead->next); }
  void remove_back() { remove(dummyTail->prev); }
  void remove(size_t index) {
    DoublyListNode<T> *toRemoveNode = getNode(index);
    remove(toRemoveNode);
  }
  void remove(DoublyListNode<T> *pos) {
    if (pos == nullptr || pos == dummyHead || pos == dummyTail)
      return;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    --size;
  }
```
5. 查找节点时，需要遍历整个链表，直到找到目标节点。
```c++
  T find(size_t index) {
    DoublyListNode<T> *toFindNode = getNode(index);
    return toFindNode->data;
  };

  DoublyListNode<T> *getNode(size_t index) {
    if (index < 0 || index >= size) {
      throw std::runtime_error("index out of range");
     }
     DoublyListNode<T> *cur = dummyHead->next;
     for (size_t i = 0; i < index; i++) {
          cur = cur->next;
     }
     return cur;
  }
```
6. 更新节点时，需要找到目标节点，并更新其数据。
```c++
  void update(size_t index, T val) {
    DoublyListNode<T> *toUpdateNode = getNode(index);
    toUpdateNode->data = val;
  }
```
7. 打印链表时，需要从头节点开始遍历，并打印每个节点的数据。
```c++
  void print() {
    if (size == 0) {
      std::cout << "DoublyLinkedList is Empty: []" << std::endl;
      return;
    }
    DoublyListNode<T> *cur = dummyHead->next;
    std::cout << "Print DoublyLinkedList: [";
    int i = 0;
    while (cur != dummyTail) {
      if (i++ != 0)
        std::cout << ", ";
      std::cout << cur->data;
      cur = cur->next;
    }
    std::cout << "]" << std::endl;
  }
```
8. 清空双链表的实现代码：
```c++
  void clear() {
    DoublyListNode<T> *cur = dummyHead->next;
    while (cur != dummyTail) {
      DoublyListNode<T> *toDeleteNode = cur;
      cur = cur->next;
      delete toDeleteNode;
    }
    Init();
  }
```

