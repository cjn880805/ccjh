//juqinggusandao7.h ����ɽ��7
//�ز� 2002.3.9

ROOM_BEGIN(CRjuqinggusandao7);

virtual void create()			
{
	set_name("�����ɽ��7");
	add_npc("pub_jueqingdizi");
	remove_all_doors();
	char msg[255];
	for(int i=1;i<9;i++)
	{
		if(i!=7)
			add_door(snprintf(msg, 255,"�����ɽ��%d",i), snprintf(msg, 255,"�����ɽ��%d",i), "�����ɽ��7");
	}    
};

int valid_leave(CChar * me, const char * dir)
{
	if(me->query_temp("gumu/jq_y"))
		me->delete_temp("gumu/jq_y");
	return CRoom::valid_leave(me, dir);
}

ROOM_END;




