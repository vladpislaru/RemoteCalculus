
typedef struct SensorData SensorsArray<>;

struct SensorData{
    int dataId;
    int noValues;
    float values<>;
};

struct GetData {
    int sensor;
    int session;
};

struct PostData{
    int session;
    SensorData sensor;
};

struct SensorStat{
    int min;
    int max;
    int middle;
    int median;
};

struct UserSpace{
    int session;
    string username<>;
    SensorData bd;
};

program RPCBD {
    version  RPCBDvers{
        int login(string) = 1;
        int logout(int) = 2;
        void load(UserSpace) = 3;
        int add(PostData) = 4;
        int delete(GetData) = 5;
        int update(PostData) = 6;
        SensorData read(GetData) = 7;
        SensorsArray readAll(int) = 8;
        SensorData getStat(GetData) = 9;
        SensorData getStatAll(int) = 10;
    } = 1;
} = 123456789;