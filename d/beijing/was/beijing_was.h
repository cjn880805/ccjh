//beijing_was.h  ��������

RESIDENT_BEGIN(CRbeijing_was);

virtual void create()
{
	set_name( "����");
	set("resident", "����");

	add_npc("was_fanseng");
	add_npc("was_fanseng");

	add_door("������", "����������", "��������");
	add_door("���µ�һ��", "�������µ�һ��", "��������");
};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"���µ�һ��") )
	{
		if(!me->query_temp("was/renwu2_5"))
		{
			return notify_fail("$HIR�������Եķ�ɮ������ס���ȥ����ʩ������������");
		}
	}
	return CRoom::valid_leave(me, dir);
}
RESIDENT_END;
