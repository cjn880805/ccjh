//junying62.h  ���Ӫ��2
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying62);

virtual void create()			
{
	set_name("���Ӫ��");

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
	
	add_door("����Ӫ��3", "��������Ӫ��3", "������Ӫ��2");
	add_door("���Ӫ��1", "������Ӫ��1", "������Ӫ��2");
	add_door("�о�Ӫ��6", "�����о�Ӫ��6", "������Ӫ��2");
	add_door("���Ӫ��4", "������Ӫ��4", "������Ӫ��2");

	set("long","�������������ͷ�֮�صأ�����ɭ�ϡ����ó�ͳ˧��ñ���Ҫּ��" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�о�Ӫ��6") )
	{
		if(!me->query_temp("zhang/����ǿ_jion"))
		{
			return notify_fail("$HIR�����о���Ӫ�ǰ������������������������أ�����ƫӪ��ס�����կ������λ���о�֮���ģ��β����ƣ��㲻�ɵ�����һ��������");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
