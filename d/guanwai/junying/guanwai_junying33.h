//junying33.h  ���ȷ�Ӫ��3
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying33);

virtual void create()			
{
	set_name("���ȷ�Ӫ��");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	if(random(2))
	{
		add_npc("pub_songbing1");
		add_npc("pub_songjiang1");
	}
	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("���ȷ�Ӫ��1", "�������ȷ�Ӫ��1", "�������ȷ�Ӫ��3");
	add_door("�о�Ӫ��3", "�����о�Ӫ��3", "�������ȷ�Ӫ��3");
	add_door("���ȷ�Ӫ��4", "�������ȷ�Ӫ��4", "�������ȷ�Ӫ��3");

	set("long","�˴������ȷ�Ӫ�ʣ����½�����ɽ��·֮��������ˮ���ŵ���ʿ������ʱ��ҡ���죬�������ء����Ǿ��ݶ�ʢ��" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�о�Ӫ��3") )
	{
		if(!me->query_temp("zhang/����ǿ_jion"))
		{
			return notify_fail("$HIR�����о���Ӫ�ǰ������������������������أ�����ƫӪ��ס�����կ������λ���о�֮���ģ��β����ƣ��㲻�ɵ�����һ��������");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
