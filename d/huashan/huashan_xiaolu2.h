//xiaolu2.h

//Sample for room: ��ɽСɽ·2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_xiaolu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽСɽ·2");
	
	add_npc("pub_guest");         //add by zdn 2001-07-17

	add_door("��ɽСɽ·", "��ɽСɽ·", "��ɽСɽ·2");
	add_door("��ɽС��", "��ɽС��", "��ɽСɽ·2");

	set("long", "�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ���������������ܾ����ĵģ�������߽���һ��������Դ�����������һ������(men)��");  
    
 
/*****************************************************
	set("exits", ([  
		"southwest" : __DIR__"xiaolu1",
	]));
********************************************/
};


ROOM_END;
