//hiemuya.h

//Sample for room:  ��ľ��
//coded by zouwenbin
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRHeiMuYacity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��");
	
	add_npc("pub_laozhe");        //add by zdn 2001-07-14

	add_door("��ľ����ʯ��", "��ľ����ʯ��", "����");

	add_door("��ľ�³ɵµ�", "��ľ�³ɵµ�", "����");
	add_door("��ľ��������", "��ľ��������", "����");
	add_door("��ľ�°׻��ô���", "��ľ�°׻��ô���", "����");
	add_door("��ľ�·����ô���", "��ľ�·����ô���", "����");

};


ROOM_END;
