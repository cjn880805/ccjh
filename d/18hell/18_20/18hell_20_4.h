//18hell_20.h
//ʮ�˵�����ʮ�������������4����

ROOM_BEGIN(CR18hell_20_4);

virtual void create()			//Call it when Room Create
{
	set_name("�������");
	
	add_npc("diyu_shizhe20");

};

virtual int do_look(CChar * me)
{
	say("����һ�޴����ʯ�м���һԲ����ӣ�����ڣ�һ�����С���߲��������������ߡ���Ы���������ҧ��ʳ������߸ߵ���ʯ�ߣ�һ������������Ѻ����������С�", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
