//yongdao.h

//Sample for room: ���͵���
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_yongdao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵���");
	
	add_npc("pub_dizi3"); 
	add_npc("pub_dizi3");        //add by zdn 2001-07-16

	add_door("���͵��ٲ�", "���͵��ٲ�", "���͵���");
	add_door("���͵�ʯ��1", "���͵�ʯ��1", "���͵���");

    set("long", "�������������࣬�����Ǽ��Ҵ�����������в������µ��ӡ�����˶��ֳ�ʳ����߱߳ԣ�Ω�ֵ�����ʱ�䡣�����������ڵ���ؤ����ǽ����Ȼ��˯��һ��С������ż⣬������ӵ��͡�" );
    

/*****************************************************

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp