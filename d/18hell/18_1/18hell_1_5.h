//18hell_1_5.h
//ʮ�˵�����һ����ŷ���

//coded by sound
//data: 2001-10-21

YEWAIROOM_BEGIN(CR18hell_1_5);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "�߲��Թ�");
	
	set("long", "������ʮ�˵�����һ�㡰��Ȫ�������ܵ����걻һ��Ī�������������ţ�����һ���޴�ĵ��¶�Ѩ��Ե�������ϵ�������ȥ��");
	
	//add npcs into the room
	add_npc("diyu_shizhe1");

};

YEWAIROOM_END;
