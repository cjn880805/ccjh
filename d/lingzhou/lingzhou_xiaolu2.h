//xiaolu2.h

//Sample for room: ��������С·2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xiaolu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������С·2");
	
	add_npc("monster_20k");      //add by zdn 2001-07-14
	add_npc("pub_gaoming");


	add_door("��������С·1", "��������С·1", "��������С·2");
	add_door("��������С·3", "��������С·3", "��������С·2");
	add_door("���ݰ��ɵ���", "���ݰ��ɵ���", "��������С·2");

};


ROOM_END;




