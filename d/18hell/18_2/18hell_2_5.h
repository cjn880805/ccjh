//18hell_2_5.h
//ʮ�˵�����ڻ�Ȫ֮·��ŷ���

//coded by sound
//data: 2001-10-21

YEWAIROOM_BEGIN(CR18hell_2_5);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "��Ȫ֮·");
	
	set("long", "������ͨ��ʮ�˵����ġ���Ȫ�������ܵ����걻һ��Ī�������������ţ�����һ���޴�ĵ��¶�Ѩ��Ե�������ϵ�������ȥ��");
	
	//add npcs into the room
	add_npc("diyu_shizhe2");

};

YEWAIROOM_END;