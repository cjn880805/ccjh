//dadian.h

//Sample for room: �������
//coded by zouwenbin
//data: 2000-11-

ROOM_BEGIN(CRSongShan_dadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");
	
	add_npc("songshan_zuo");      //add by zdn 2001-07-20


	add_door("��ɽ��ʥ��", "��ɽ��ʥ��", "��ɽ�������");
	add_door("��ɽɽ��1", "��ɽɽ��1", "��ɽ�������");

	set("long", "��������ż䣬������䣬�����е�ʽ�ݶ����������߳߸ߵ�̨���ϣ�������ΰ������й���������������" );
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
********************************************/
};


ROOM_END;
