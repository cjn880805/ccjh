//junying23.h  �о��ȷ�Ӫ��3
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying23);

virtual void create()			
{
	set_name("�о��ȷ�Ӫ��");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	add_npc("bj_hunaliangjin");
	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("�о��ȷ�Ӫ��1", "�����о��ȷ�Ӫ��1", "�����о��ȷ�Ӫ��3");
	add_door("�о�Ӫ��2", "�����о�Ӫ��2", "�����о��ȷ�Ӫ��3");
	add_door("�о��ȷ�Ӫ��4", "�����о��ȷ�Ӫ��4", "�����о��ȷ�Ӫ��3");

	set("long","�˴����о��ȷ�Ӫ�ʣ������ϵ������ʿ�ȷ�ٺ���������˾�����ʲ��½���ͬ��׳�У�ֻ���������ڲ�����ʿ��������Ϳ��Ѫ���������������������������ư׻�����ţ�����䣬��ͷ���ؿڡ��˵�ɱ�ˣ���ɱ��ɷ�ǿ��¡�" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�о�Ӫ��2") )
	{
		if(!me->query_temp("zhang/����ǿ_jion"))
		{
			return notify_fail("$HIR�����о���Ӫ�ǰ������������������������أ�����ƫӪ��ס�����կ������λ���о�֮���ģ��β����ƣ��㲻�ɵ�����һ��������");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
