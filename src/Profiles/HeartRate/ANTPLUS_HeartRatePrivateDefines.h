/* Byte positions */
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_DATAPAGE_BYTE 0
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE   0
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE 4
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE 5
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE 6
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE 7

/* Masks */
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_DATAPAGE_MASK 0x7F
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK   0x80

/* BitShifts */
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_SHIFT  7
#define ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_SHIFT 8