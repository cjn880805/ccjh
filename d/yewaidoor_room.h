#ifndef __YEWAIDOOR_ROOM_H__
#define __YEWAIDOOR_ROOM_H__

#define YEWAIDOOR_BEGIN(room_name)	class room_name : public CRyewaidoor_room	{	public:	room_name(){};	virtual ~room_name(){};
#define YEWAIDOOR_END		}	

//XuNing 2001-08-31
char * make_random_yewai(UINT n);

ROOM_BEGIN(CRyewaidoor_room);

static void YewaiDoorCallOut(CContainer * ob, LONG param1, LONG param2)
{
	POSITION p;
	CDoor * d;
	CRoom *me = (CRoom *)ob;
	DTEXITLIST * dlist = (DTEXITLIST *)param2;
	UINT n;

	p = dlist->GetHeadPosition();

	while(p != NULL)
	{
		d = dlist->GetNext(p);
		if((n = d->query_temp("yewai")) > 0)
		{
			d->Bind(make_random_yewai(n), NULL);
		}
	}

	me->call_out(YewaiDoorCallOut, (time_t)param1, param1, param2);
}

CDoor * add_yewaidoor(const char * id, UINT n, time_t ct, const char * dir = "")
{
	string s;
	CDoor * door;

	if(!strcmp(id, "west"))
		s = "迷宫东";
	else if(!strcmp(id, "east"))
		s = "迷宫西";
	else if(!strcmp(id, "north"))
		s = "迷宫北";
	else if(!strcmp(id, "south"))
		s = "迷宫南";
	else return NULL;

	door = add_door(id, make_random_yewai(n), s.c_str(), dir);

	door->set_temp("yewai", n);

	call_out(YewaiDoorCallOut, ct, ct, (LONG)&m_DoorList);

	return door;
}

virtual int valid_leave(CChar * me, const char * dir)
{
	CDoor *d;
	if((d = PresentDoor(dir)) == 0)return 1;

	if(d->query_temp("yewai") > 0)
	{
		me->set_temp("firstmap", 1);
		me->set_temp("mapnum", 20 + random(10));			//设定切换地图20 ~ 30次返回来时地图
		me->set_temp("frommap", querystr("base_name"));		//记录来时的地图
		me->set_temp("fromdir", d->querystr("id"));			//记录来时的方向
		me->set_temp("todir", d->querystr("next_door"));	//记录到达时的方向
	}

	return 1;
}
	
ROOM_END;

#endif