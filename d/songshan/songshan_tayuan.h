//tayuan.h

//Sample for room: ��Ժ
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_tayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ժ");
	
	add_npc("songshan_deng");         //add by zdn 2001-07-20
	add_npc("songshan_di");

		

	add_door("��ɽ������", "��ɽ������", "��ɽ��Ժ");

	set("long", "�����±�ɽ���ϣ��Ƿ�������Ժ��Ժ����ʮ������ܷ������߽���ʮ�ɣ�����������Ժ��������������Ĺ����������������" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	
	set("outdoors", "songshan");
********************************************/
};


ROOM_END;
