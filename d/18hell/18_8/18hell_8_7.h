//18hell_8_7.h
//ʮ�˵������Ĳ��ʺ������7����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_8_7);

virtual void create()			//Call it when Room Create
{
	set_name("��ʺ����");
	
	add_npc("diyu_shizhe8");

};

virtual int do_look(CChar * me)
{
	say("�γ�ת�ǵ�Χ�Ǹ�ǽ���и������м��ǽ��һ�����ڷ��̹���������������ԣ��ֳֳ���ư���������յù��̵��۽��Ӹ�ǽ����к��ǽ�µ����������ϡ���", me);
	say("���������������ڱ�ľ�ݡ�������Χ��ƽ̨�ϣ���������������ſ��ľ׮�ϣ����ö������Ҳ�߸ߵ�ʯ���ϣ�������Ѻ�������ߵ���ʺ�������̡�", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
