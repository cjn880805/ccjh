//18hell_2.h
//ʮ�˵�����ڻ�Ȫ֮·BOSS����

//coded by sound
//data: 2001-10-21

CUNLUOROOM_BEGIN(CR18hell_2);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "��Ȫ��Ѩ");
	
	set("long", "������ͨ��ʮ�˵����ġ���Ȫ�������ܵ����걻һ��Ī�������������ţ�����һ���޴�ĵ��¶�Ѩ��Ե�������ϵ�������ȥ��");
	
	//add npcs into the room
	add_npc("diyu_shizhe2");
	add_npc("dajianshi_lante");

};

CUNLUOROOM_END;
