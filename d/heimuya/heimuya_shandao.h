//shandao.h

//Sample for room: ��ľ��ɽ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shandao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��ɽ��");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("��ľ�³�̲", "��ľ�³�̲", "��ľ��ɽ��");
	add_door("��ľ��ʯ��", "��ľ��ʯ��", "��ľ��ɽ��");
	add_door("��ľ�·����ô���", "��ľ�·����ô���", "��ľ��ɽ��");

};


ROOM_END;
