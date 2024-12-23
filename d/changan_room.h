#define CHANGAN_BEGIN(room_name)	class room_name : public CRchangan_room	{	public:	room_name(){};	virtual ~room_name(){};
#define CHANGAN_END		};	

//Lanwood 2001-02-03

ROOM_BEGIN(CRchangan_room);

virtual void setup()
{
	CRoom::setup();

	static char xunbuname[16][14]={"monster_4k","monster_6k","monster_8k","monster_10k","monster_13k","monster_16k","monster_20k","monster_24k","monster_28k","monster_32k","monster_36k","monster_40k","monster_44k","monster_416k","monster_1632k","monster_3248k",};

	if(! random(2))	add_npc(xunbuname[random(16)]);	
	if(! random(2))	add_npc(xunbuname[random(16)]);	
	if(! random(3))	add_npc(xunbuname[random(12)]);	
	if(! random(3))	add_npc(xunbuname[random(12)]);	
	if(! random(4))	add_npc(xunbuname[random(8)]);	
	if(! random(4))	add_npc(xunbuname[random(8)]);	
	if(! random(5))	add_npc(xunbuname[random(5)]);	
	if(! random(5))	add_npc(xunbuname[random(5)]);	
}
	
ROOM_END;
