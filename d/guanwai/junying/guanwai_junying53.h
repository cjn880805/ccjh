//junying53.h  ����Ӫ��3
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying53);

virtual void create()			
{
	set_name("����Ӫ��");

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
	
	add_door("����Ӫ��1", "��������Ӫ��1", "��������Ӫ��3");
	add_door("�о�Ӫ��5", "�����о�Ӫ��5", "��������Ӫ��3");
	add_door("����Ӫ��4", "��������Ӫ��4", "��������Ӫ��3");

	set("long","����Ӫ�����ڹ�ĦӪ�����䱸�ķ��ʻ��������ǹ��������ݡ�����¡¡��ǹ�����󣬼�Ъ�������׵�������" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�о�Ӫ��5") )
	{
		if(!me->query_temp("zhang/����ǿ_jion"))
		{
			return notify_fail("$HIR�����о���Ӫ�ǰ������������������������أ�����ƫӪ��ס�����կ������λ���о�֮���ģ��β����ƣ��㲻�ɵ�����һ��������");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
