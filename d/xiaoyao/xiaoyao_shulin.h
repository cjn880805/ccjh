//shulin.h

//Sample for room: ��ң������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_shulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң������");

	add_npc("xiaoyao_suxingh");

	add_door("��ң��С��1", "��ң��С��1", "��ң������");
	add_door("�����ݵ�", "�����ݵ�", "��ң������");	

	set("long", "����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ������ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ����������");

/*****************************************************

********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp