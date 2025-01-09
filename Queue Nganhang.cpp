#include <iostream>
#include <cstdlib>
using namespace std;

// Định nghĩa Queue
class Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;

public:
    Queue(unsigned capacity);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int item);
    int dequeue();
    int peek();
};

// Hàm tạo Queue
Queue::Queue(unsigned capacity) {
    this->capacity = capacity;
    front = 0;
    size = 0;
    rear = capacity - 1; // Rear khởi tạo ở vị trí cuối
    array = new int[capacity];
}

// Hàm hủy Queue
Queue::~Queue() {
    delete[] array;
}

// Kiểm tra Queue có rỗng không
bool Queue::isEmpty() {
    return (size == 0);
}

// Kiểm tra Queue có đầy không
bool Queue::isFull() {
    return (size == capacity);
}

// Thêm phần tử vào Queue
void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "Hàng đợi đã đầy. Không thể thêm phần tử.\n";
        return;
    }
    rear = (rear + 1) % capacity;
    array[rear] = item;
    size++;
    cout << "Đã thêm khách hàng " << item << " vào hàng đợi.\n";
}

// Loại bỏ phần tử khỏi Queue
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Hàng đợi rỗng. Không có khách hàng nào để phục vụ.\n";
        return -1;
    }
    int item = array[front];
    front = (front + 1) % capacity;
    size--;
    cout << "Đã phục vụ khách hàng " << item << ".\n";
    return item;
}

// Lấy phần tử ở đầu Queue
int Queue::peek() {
    if (isEmpty()) {
        cout << "Hàng đợi rỗng.\n";
        return -1;
    }
    return array[front];
}

// Hàm chính
int main() {
    unsigned capacity = 5; // Dung lượng hàng đợi
    Queue queue(capacity);

    int choice, customer;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Thêm khách hàng vào hàng đợi\n";
        cout << "2. Phục vụ khách hàng đầu tiên\n";
        cout << "3. Xem khách hàng đầu hàng đợi\n";
        cout << "4. Kiểm tra hàng đợi có rỗng không\n";
        cout << "5. Thoát\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhập mã khách hàng: ";
                cin >> customer;
                queue.enqueue(customer);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                customer = queue.peek();
                if (customer != -1) {
                    cout << "Khách hàng đầu tiên trong hàng đợi: " << customer << "\n";
                }
                break;
            case 4:
                if (queue.isEmpty()) {
                    cout << "Hàng đợi đang rỗng.\n";
                } else {
                    cout << "Hàng đợi không rỗng.\n";
                }
                break;
            case 5:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (choice != 5);

    return 0;
}
