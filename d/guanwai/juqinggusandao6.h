//juqinggusandao6.h 绝情山道6
//秦波 2002.3.9

ROOM_BEGIN(CRjuqinggusandao6);

virtual void create()			
{
	set_name("绝情谷山道6");
	add_npc("pub_jueqingdizi");
	remove_all_doors();
	char msg[255];
	for(int i=1;i<9;i++)
	{
		if(i!=6)
			add_door(snprintf(msg, 255,"绝情谷山道%d",i), snprintf(msg, 255,"绝情谷山道%d",i), "绝情谷山道6");
	}    
};

int valid_leave(CChar * me, const char * dir)
{
	if(me->query_temp("gumu/jq_y"))
		me->delete_temp("gumu/jq_y");
	return CRoom::valid_leave(me, dir);
}

ROOM_END;




