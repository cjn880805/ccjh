//xiuxishi.h

//Sample for room: ���˾���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���˾���");

	//add npcs into the room
	add_npc("pub_weishi2");/////////////////////////
	add_npc("pub_weishi1");
	add_npc("pub_xiangke");
	//add_npc("zhuwanli");
	add_door("�������������", "�������������", "������������˾���");

	set("long", "����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ���һ����ң����顸�����������ĸ����֡��ſ�վ���������������Ž��£���ִ�ֵ�������������" );
	set("valid_startroom", 1);
    set("sleep_room",1);

};

ROOM_END;




