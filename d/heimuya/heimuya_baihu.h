//baihuda.h

//Sample for room: �׻���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_baihu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�׻���");
	
	add_npc("heimuya_renwuyue");         // add by zdn 2001-07-14

	add_door("��ľ�³���", "��ľ�³���", "��ľ�°׻���");
	add_door("��ľ��ʥ����", "��ľ��ʥ����", "��ľ�°׻���");
	add_door("��ľ�³���", "��ľ�³���", "��ľ�°׻���");

	set("long", "�����Ǻ�ľ�µĵڶ����á��׻��á���������ש�̵أ����ں�ʬ���ء����ϱ������м���Ѫ��(zi)��");
    
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp