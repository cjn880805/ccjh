//songlin.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_songlin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");
	add_npc("pub_yumu");

	add_door("��ɽ����", "��ɽ����", "��ɽ������");

	set("long", "����һƬ�����֡����ɸߵ������������飬�ڵò������ա������������룬�в�֪����Ұ��͵͵�ӹ�������һƬ�ž���");  
    
 
/*****************************************************

********************************************/
};


ROOM_END;
