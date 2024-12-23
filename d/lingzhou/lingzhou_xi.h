//nanmen.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xi);

virtual void create()			//Call it when Room Create
{

	set_name( "������");

	//add npcs into the room
	add_npc("pub_xiaowei");/////////////////////////
	add_npc("pub_xixiabing");

	add_npc("pub_playboy");
	add_npc("lingzhou_helian");       //add by zdn 2001-07-20

	add_door("���ݾƹ�", "���ݾƹ�", "������");
	add_door("���ݵ���", "���ݵ���", "������");
	add_door("��������Ӫ", "��������Ӫ", "������");
	add_door("���ݳ����", "���ݳ����", "������");				
	add_door("���ݻʹ�����", "���ݻʹ�����", "������");
	add_door("����һƷ�ô���", "����һƷ�ô���", "������");
	add_door("���ݻ���̲", "���ݻ���̲", "������");
	add_door("���ݶ�", "���ݶ�", "������");

};


ROOM_END;
