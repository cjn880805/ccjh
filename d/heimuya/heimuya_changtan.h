//changtan.h

//Sample for room: ��ľ�³�̲
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_changtan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�³�̲");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("��ľ������̲", "��ľ������̲", "��ľ�³�̲");
	add_door("��ľ��ɽ��", "��ľ��ɽ��", "��ľ�³�̲");

};


ROOM_END;
