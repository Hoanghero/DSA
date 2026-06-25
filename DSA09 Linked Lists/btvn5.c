#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FLOORS 17
#define ROOMS 12
#define MAXM 64
#define MAXN 64

typedef struct {
    int occupied;
    char name;
    int nextFloor;
    int nextRoom;
} Room;

typedef struct {
    int floor;
    int room;
} Addr;

Room hotel[FLOORS][ROOMS + 1];

void initHotel(void) {
    for (int f = 0; f < FLOORS; f++) {
        for (int r = 1; r <= ROOMS; r++) {
            hotel[f][r].occupied = 0;
            hotel[f][r].name = ' ';
            hotel[f][r].nextFloor = -1;
            hotel[f][r].nextRoom = -1;
        }
    }
}

void printHotel(void) {
    for (int f = 0; f < FLOORS; f++) {
        for (int r = 1; r <= ROOMS; r++) {
            printf("%d ", hotel[f][r].occupied);
        }
        printf("\n");
    }
    printf("\n");
}

void freeRoom(int f, int r) {
    hotel[f][r].occupied = 0;
    hotel[f][r].name = ' ';
    hotel[f][r].nextFloor = -1;
    hotel[f][r].nextRoom = -1;
}

void shuffleAddr(Addr *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Addr tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int collectEmpty(int onlyFloor0, Addr *out) {
    int cnt = 0;
    for (int f = 0; f < FLOORS; f++) {
        if (onlyFloor0 == 1 && f != 0) continue;
        if (onlyFloor0 == 0 && f == 0) continue;
        for (int r = 1; r <= ROOMS; r++) {
            if (!hotel[f][r].occupied) {
                out[cnt].floor = f;
                out[cnt].room = r;
                cnt++;
            }
        }
    }
    return cnt;
}

int assignGroups(int n, char groups[][MAXM], int sizes[], Addr leaders[]) {
    Addr emptyLeader[ROOMS];
    Addr emptyOther[FLOORS * ROOMS];
    int cntLeader = collectEmpty(1, emptyLeader);
    int cntOther = collectEmpty(0, emptyOther);

    int totalMembers = 0;
    for (int i = 0; i < n; i++) totalMembers += sizes[i];

    if (cntLeader < n) return 0;
    if (cntLeader + cntOther < totalMembers) return 0;

    shuffleAddr(emptyLeader, cntLeader);
    shuffleAddr(emptyOther, cntOther);

    int otherIdx = 0;
    for (int i = 0; i < n; i++) {
        Addr prevAddr = emptyLeader[i];
        leaders[i] = prevAddr;

        hotel[prevAddr.floor][prevAddr.room].occupied = 1;
        hotel[prevAddr.floor][prevAddr.room].name = groups[i][0];
        hotel[prevAddr.floor][prevAddr.room].nextFloor = -1;
        hotel[prevAddr.floor][prevAddr.room].nextRoom = -1;

        for (int j = 1; j < sizes[i]; j++) {
            Addr cur = emptyOther[otherIdx++];

            hotel[cur.floor][cur.room].occupied = 1;
            hotel[cur.floor][cur.room].name = groups[i][j];
            hotel[cur.floor][cur.room].nextFloor = -1;
            hotel[cur.floor][cur.room].nextRoom = -1;

            hotel[prevAddr.floor][prevAddr.room].nextFloor = cur.floor;
            hotel[prevAddr.floor][prevAddr.room].nextRoom = cur.room;

            prevAddr = cur;
        }
    }
    return 1;
}

void traceGroup(int floor0, int room0) {
    int f = floor0, r = room0;
    printf("Truong doan tai P%d.%d\n", f, r);
    while (f != -1 && r != -1) {
        printf("  Khach %c -> P%d.%d\n", hotel[f][r].name, f, r);
        int nf = hotel[f][r].nextFloor;
        int nr = hotel[f][r].nextRoom;
        f = nf;
        r = nr;
    }
}

int addMembers(int floor0, int room0, char *newNames, int count) {
    Addr emptyOther[FLOORS * ROOMS];
    int cntOther = collectEmpty(0, emptyOther);
    if (cntOther < count) return 0;
    shuffleAddr(emptyOther, cntOther);

    int f = floor0, r = room0;
    while (hotel[f][r].nextFloor != -1) {
        int nf = hotel[f][r].nextFloor;
        int nr = hotel[f][r].nextRoom;
        f = nf;
        r = nr;
    }

    for (int i = 0; i < count; i++) {
        Addr cur = emptyOther[i];

        hotel[cur.floor][cur.room].occupied = 1;
        hotel[cur.floor][cur.room].name = newNames[i];
        hotel[cur.floor][cur.room].nextFloor = -1;
        hotel[cur.floor][cur.room].nextRoom = -1;

        hotel[f][r].nextFloor = cur.floor;
        hotel[f][r].nextRoom = cur.room;

        f = cur.floor;
        r = cur.room;
    }
    return 1;
}

int removeMember(int leaderFloor, int leaderRoom, int targetFloor, int targetRoom) {
    if (leaderFloor == targetFloor && leaderRoom == targetRoom) {
        int nf = hotel[leaderFloor][leaderRoom].nextFloor;
        int nr = hotel[leaderFloor][leaderRoom].nextRoom;

        if (nf == -1) {
            freeRoom(leaderFloor, leaderRoom);
            return 1;
        }

        hotel[leaderFloor][leaderRoom].name = hotel[nf][nr].name;
        hotel[leaderFloor][leaderRoom].nextFloor = hotel[nf][nr].nextFloor;
        hotel[leaderFloor][leaderRoom].nextRoom = hotel[nf][nr].nextRoom;
        freeRoom(nf, nr);
        return 1;
    }

    int pf = leaderFloor, pr = leaderRoom;
    int cf = hotel[pf][pr].nextFloor, cr = hotel[pf][pr].nextRoom;

    while (cf != -1) {
        if (cf == targetFloor && cr == targetRoom) {
            hotel[pf][pr].nextFloor = hotel[cf][cr].nextFloor;
            hotel[pf][pr].nextRoom = hotel[cf][cr].nextRoom;
            freeRoom(cf, cr);
            return 1;
        }
        pf = cf;
        pr = cr;
        int nf = hotel[cf][cr].nextFloor;
        int nr = hotel[cf][cr].nextRoom;
        cf = nf;
        cr = nr;
    }
    return 0;
}

void checkoutGroup(int floor0, int room0) {
    int f = floor0, r = room0;
    while (f != -1 && r != -1) {
        int nf = hotel[f][r].nextFloor;
        int nr = hotel[f][r].nextRoom;
        freeRoom(f, r);
        f = nf;
        r = nr;
    }
}

int main() {
    srand((unsigned)time(NULL));
    initHotel();

    int n = 3;
    int sizes[3] = {4, 3, 5};
    char groups[3][MAXM] = {"ABSE", "TMK", "HJSSA"};
    Addr leaders[3];

    if (!assignGroups(n, groups, sizes, leaders)) {
        printf("Khong du phong trong de xep cac doan khach.\n");
        return 1;
    }

    printf("Trang thai khach san sau khi xep\n");
    printHotel();

    printf("Tra cuu thong tin doan (Doan 1)");
    traceGroup(leaders[0].floor, leaders[0].room);
    printf("\n");

    printf("Khach le check-out + bo sung khach moi cho Doan 2\n");
    freeRoom(2, 5);
    freeRoom(4, 7);
    char newGuests[2] = {'X', 'Y'};
    addMembers(leaders[1].floor, leaders[1].room, newGuests, 2);
    traceGroup(leaders[1].floor, leaders[1].room);
    printf("\n");

    printf("Mot so khach check-out dot xuat (Doan 3)\n");
    int f = leaders[2].floor, r = leaders[2].room;
    int nf = hotel[f][r].nextFloor, nr = hotel[f][r].nextRoom;
    removeMember(leaders[2].floor, leaders[2].room, nf, nr);
    traceGroup(leaders[2].floor, leaders[2].room);
    printf("\n");

    printf("Doan 1 check-out toan bo\n");
    checkoutGroup(leaders[0].floor, leaders[0].room);
    printHotel();

    return 0;
}