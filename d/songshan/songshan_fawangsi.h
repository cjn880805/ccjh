//fawangsi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_fawangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_zhenfang");
	add_door("��ɽ��Ժ", "��ɽ��Ժ", "��ɽ������");
	add_door("��ɽ��̨", "��ɽ��̨", "��ɽ������");
	add_door("��ɽɽ��4", "��ɽɽ��4", "��ɽ������");
	add_door("��ɽɽ��5", "��ɽɽ��5", "��ɽ������");

	set("long", "�����±�ɽ���ϣ��Ƿ�������Ժ��Ժ����ʮ������ܷ������߽���ʮ�ɣ�����������Ժ��������������Ĺ����������������" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	set("outdoors", "songshan");
********************************************/
};


ROOM_END;
