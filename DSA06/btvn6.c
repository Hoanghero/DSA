#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES_PER_AP 100
#define TOTAL_APS 50 // Giả sử M = 50 điểm truy cập trong toàn bộ toà nhà

// ---------------- CẤU TRÚC QUEUE CƠ BẢN ----------------
typedef struct {
    int data[MAX_DEVICES_PER_AP];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

bool isFull(Queue* q) {
    return q->count == MAX_DEVICES_PER_AP;
}

void enqueue(Queue* q, int device_id) {
    if (isFull(q)) {
        printf("Queue day! Khong the them thiet bi.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_DEVICES_PER_AP;
    q->data[q->rear] = device_id;
    q->count++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_DEVICES_PER_AP;
    q->count--;
    return val;
}

// ---------------- HÀM HỖ TRỢ XỬ LÝ TRÊN QUEUE ----------------

// Kiểm tra thiết bị có trong Queue hay không (bằng cách xoay vòng)
bool isDeviceInQueue(Queue* q, int device_id) {
    bool found = false;
    int size = q->count;
    for (int i = 0; i < size; i++) {
        int current = dequeue(q);
        if (current == device_id) {
            found = true;
        }
        enqueue(q, current); // Xoay vòng, trả lại vào Queue
    }
    return found;
}

// Xóa một thiết bị khỏi Queue (Dùng khi di chuyển hoặc bị chặn)
void removeDeviceFromQueue(Queue* q, int device_id) {
    int size = q->count;
    for (int i = 0; i < size; i++) {
        int current = dequeue(q);
        if (current != device_id) {
            enqueue(q, current); // Chỉ đẩy lại những thiết bị không bị xóa
        }
    }
}

// ---------------- HỆ THỐNG TOÀ NHÀ ----------------

Queue building_aps[TOTAL_APS];
Queue blacklist;

void initSystem() {
    for (int i = 0; i < TOTAL_APS; i++) {
        initQueue(&building_aps[i]);
    }
    initQueue(&blacklist);
}

// Thiết bị yêu cầu kết nối vào một AP
void connectDevice(int ap_id, int device_id) {
    if (isDeviceInQueue(&blacklist, device_id)) {
        printf("TU CHOI: Thiet bi [%d] dang nam trong Blacklist!\n", device_id);
        return;
    }
    enqueue(&building_aps[ap_id], device_id);
    printf("Thanh cong: Thiet bi [%d] da ket noi vao AP [%d].\n", device_id, ap_id);
}

// Xử lý khi thiết bị di chuyển từ AP cũ sang AP mới
void moveDevice(int old_ap, int new_ap, int device_id) {
    printf("Roaming: Thiet bi [%d] dang di chuyen tu AP [%d] sang AP [%d]...\n", device_id, old_ap, new_ap);
    // 1. Ngắt kết nối ở AP cũ
    removeDeviceFromQueue(&building_aps[old_ap], device_id);
    // 2. Kết nối vào AP mới
    connectDevice(new_ap, device_id);
}

// Chặn truy cập không đúng chức năng
void blockDevice(int current_ap, int device_id) {
    printf("CANH BAO: Phat hien thiet bi [%d] vi pham tai AP [%d]. Dang chan truy cap...\n", device_id, current_ap);
    // 1. Gỡ khỏi AP hiện tại
    removeDeviceFromQueue(&building_aps[current_ap], device_id);
    // 2. Thêm vào blacklist (nếu chưa có)
    if (!isDeviceInQueue(&blacklist, device_id)) {
        enqueue(&blacklist, device_id);
    }
}

// ---------------- CHƯƠNG TRÌNH CHÍNH ----------------
int main() {
    initSystem();

    // Kịch bản mô phỏng
    connectDevice(1, 999);  // Thiết bị 999 kết nối tầng 1 (AP 1)
    connectDevice(1, 888);  // Thiết bị 888 kết nối tầng 1 (AP 1)
    
    moveDevice(1, 5, 999);  // Thiết bị 999 di chuyển lên tầng cao hơn (AP 5)
    
    blockDevice(5, 999);    // Thiết bị 999 vi phạm và bị chặn tại AP 5
    
    moveDevice(5, 6, 999);  // Thiết bị 999 cố tình di chuyển sang AP 6 để kết nối lại
    
    return 0;
}