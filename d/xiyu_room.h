#define XIYU_BEGIN(room_name)	class room_name : public CRxiyu_room	{	public:	room_name(){};	virtual ~room_name(){};
#define XIYU_END		};	

//Lanwood 2001-02-03

ROOM_BEGIN(CRxiyu_room);

virtual void setup()
{
	CRoom::setup();

	static char xunbuname[16][14]={"monster_4k","monster_6k","monster_8k","monster_10k","monster_13k","monster_16k","monster_20k","monster_24k","monster_28k","monster_32k","monster_36k","monster_40k","monster_44k","monster_416k","monster_1632k","monster_3248k",};

	add_npc(xunbuname[random(16)]);	
	add_npc(xunbuname[random(16)]);	
}
	
ROOM_END;