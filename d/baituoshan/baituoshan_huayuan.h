//huayuan.h

//Sample for room: ����ɽ��԰
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_huayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��԰");

	//add npcs into the room
	add_npc("pub_lady1");
	
	add_door("����ɽ����", "����ɽ����", "����ɽ��԰");
	add_door("����ɽ����", "����ɽ����", "����ɽ��԰");
	add_door("����ɽ����", "����ɽ����", "����ɽ��԰");
	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ��԰");

};


ROOM_END;
