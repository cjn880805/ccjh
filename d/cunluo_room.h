#define CUNLUOROOM_BEGIN(room_name)	class room_name : public CRcunluo_room	{	public:	room_name(){};	virtual ~room_name(){};
#define CUNLUOROOM_END		}	

//XuNing 2001-08-31

ROOM_BEGIN(CRcunluo_room);

virtual int valid_leave(CChar * me, const char * dir)
{
	me->set_temp("mapnum", 20 + random(10));		//20 ~ 30
	return 1;
}
	
ROOM_END;