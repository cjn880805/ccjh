//junying14.h  ���ȷ�Ӫ��4
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying14);

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
	
	add_door("���ȷ�Ӫ��2", "�������ȷ�Ӫ��2", "�������ȷ�Ӫ��4");
	add_door("�о�Ӫ��1", "�����о�Ӫ��1", "�������ȷ�Ӫ��4");
	add_door("���ȷ�Ӫ��3", "�������ȷ�Ӫ��3", "�������ȷ�Ӫ��4");

	set("long","�˴������ȷ�Ӫ�ʣ������У������У�������������ɱ����ǹ����ҫ���ɺ��⡣���˵��ˣ��Ȳ���Ҳ�ô�����¡�" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�о�Ӫ��1") )
	{
		if(!me->query_temp("zhang/����ǿ_jion"))
		{
			return notify_fail("$HIR�����о���Ӫ�ǰ������������������������أ�����ƫӪ��ס�����կ������λ���о�֮���ģ��β����ƣ��㲻�ɵ�����һ��������");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
