//18hell_9.h
//ʮ�˵����������������2����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_9_2);

virtual void create()			//Call it when Room Create
{
	set_name("�������");
	
	add_npc("diyu_shizhe9");

};

virtual int do_look(CChar * me)
{
	say("�η���һ����ִ���ͳ�������������ߣ�����������������̶ȥ���̡�����һ��ɲ�ľ޴����̶��ʢ����ɫ��ˮ��������������̶���������Ҳ�̶�߶�������һ�������������̶֮�С� ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
