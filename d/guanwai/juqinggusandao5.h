//juqinggusandao5.h ����ɽ��5
//�ز� 2002.3.9

ROOM_BEGIN(CRjuqinggusandao5);

virtual void create()			
{
	set_name("�����ɽ��5");
	add_npc("pub_jueqingdizi");
	remove_all_doors();
	char msg[255];
	for(int i=1;i<9;i++)
	{
		if(i!=5)
			add_door(snprintf(msg, 255,"�����ɽ��%d",i), snprintf(msg, 255,"�����ɽ��%d",i), "�����ɽ��5");
	}    
};

int valid_leave(CChar * me, const char * dir)
{
	if(me->query_temp("gumu/jq_y"))
		me->delete_temp("gumu/jq_y");
	return CRoom::valid_leave(me, dir);
}

ROOM_END;





