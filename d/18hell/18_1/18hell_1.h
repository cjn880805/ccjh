//18hell_1.h
//ʮ�˵�����һ��BOSS����

//coded by sound
//data: 2001-10-21

CUNLUOROOM_BEGIN(CR18hell_1);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "�߲��Թ�");
	
	set("long", "������ʮ�˵�����ڡ���Ȫ�������ܵ����걻һ��Ī�������������ţ�����һ���޴�ĵ��¶�Ѩ��Ե�������ϵ�������ȥ��");
	
//	add npcs into the room
	add_npc("diyu_shizhe1");
	add_npc("ningfeng");

};

CUNLUOROOM_END;
