//yuetai.h

//Sample for room: ��̨
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_yuetai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��̨");
	
	add_npc("songshan_tang");         //add by zdn 2001-07-20


	add_door("��ɽ������", "��ɽ������", "��ɽ��̨");

	set("long", "�����Ƿ����µ���̨������̨������̫��ɽ�͸������ƣ��¶���˫����ƣ��м����硣���� '����' ������ѽڣ������Է���������������֮�У���������ɽ�ȣ�����ǵǷ�˾�֮һ�� '���Ŵ���' ��    �ٲ�һ����һСС«���£��ٲ�б������ʤ�۷塣�ٲ�֮����·���ϡ�" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"fawangsi",
	]));
	set("objects", ([
		__DIR__"npc/fei" : 1,
	]));
********************************************/
};


ROOM_END;
